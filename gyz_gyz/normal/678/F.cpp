#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define gc getchar()
#define clz __builtin_clz
#define ctz __builtin_ctz
#define pct __builtin_popcount
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pll;
const int N=5e5+10;
const ll mo=1e9+7;
const ll inf=1e9;
const ll Inf=1e18;
set<pll>s;stack<pair<pll,bool>>stk[20];
int v[N],op[N],d;ll qx[N],qy[N];
bool ok(pll a,pll b,pll c){
	return b.fr*(a.sc-c.sc)+b.sc*(c.fr-a.fr)>a.fr*(a.sc-c.sc)+a.sc*(c.fr-a.fr);
}
void qs(ll q){
	if(s.empty()){
		printf("EMPTY SET\n");return;
	}
	ll l=s.begin()->fr,r=(--s.end())->fr,m1=l+(r-l)/3,m2=l+(r-l)/3*2;
	for(;;){
		m1=l+(r-l)/3;m2=l+(r-l)/3*2;
		auto s1=s.lower_bound({m1,-Inf}),s2=s.lower_bound({m2,-Inf});
		ll r1=s1->fr*q+s1->sc,r2=s2->fr*q+s2->sc;
		if(r1==r2){
			ll ans=r1;
			for(auto i=s.lower_bound({l,-Inf});i!=s.end()&&i->fr<=r;++i)ans=max(ans,i->fr*q+i->sc);
			printf("%lld\n",ans);return;
		}
		if(r1<r2)l=m1;else r=m2;
	}
}
void ins(pll x,int d){
	auto r=s.lower_bound(x);
	if(r!=s.end()){
		if(r->fr==x.fr){
			if(r->sc>=x.sc)return;
			stk[d].push({*r,0});s.erase(r);
		}else{
			if(r!=s.begin()){
				auto rs=r;--r;
				if(!ok(*r,x,*rs))return;
			}
		}
	}
	for(;;){
		auto b=s.lower_bound(x);
		if(b==s.end())break;
		auto a=b;++b;
		if(b==s.end()||ok(x,*a,*b))break;
		stk[d].push({*a,0});s.erase(a);
	}
	for(;;){
		auto a=s.lower_bound(x);
		if(a==s.begin())break;
		--a;auto b=a;
		if(a==s.begin()||ok(*--a,*b,x))break;
		stk[d].push({*b,0});s.erase(b);
	}
	stk[d].push({x,1});s.insert(x);
}
void ud(int d){
	while(!stk[d].empty()){
		auto x=stk[d].top();stk[d].pop();
		if(x.sc)s.erase(x.fr);else s.insert(x.fr);
	}
}
void sol(int l,int r){
	if(l==r){
		if(op[l]==3)qs(qx[l]);return;
	}
	int m=(l+r)>>1;++d;
	rep(i,m+1,r)if(op[i]==2&&qx[i]<l)ins(pll(qx[qx[i]],qy[qx[i]]),d);
	sol(l,m);ud(d);
	rep(i,l,m)if(op[i]==1&&(!v[i]||v[i]>r))ins(pll(qx[i],qy[i]),d);
	sol(m+1,r);ud(d--);
}
int main(){int n;
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d%lld",&op[i],&qx[i]);
		if(op[i]==1)scanf("%lld",&qy[i]);
		if(op[i]==2)v[qx[i]]=i;
	}
	sol(1,n);
}