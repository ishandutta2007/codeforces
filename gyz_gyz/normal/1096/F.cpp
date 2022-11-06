#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 3000000
#define mo 998244353
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,s[N],a[N];ll ans,tot,nw,w[N];
ll qk(ll x,int y){ll r=1;
	for(;y;y>>=1){
		if(y&1)r=r*x%mo;x=x*x%mo;
	}return r;
}
int qs(int x,int l,int r,int L,int R){
	if(l==L&&r==R)return s[x];int rr=(L+R)/2;
	if(r<=rr)return qs(x*2,l,r,L,rr);
	if(l>rr)return qs(x*2+1,l,r,rr+1,R);
	return qs(x*2,l,rr,L,rr)+qs(x*2+1,rr+1,r,rr+1,R);
}
void cg(int x,int y,int L,int R){
	++s[x];if(L==R)return;int rr=(L+R)/2;
	if(y<=rr)cg(x*2,y,L,rr);else cg(x*2+1,y,rr+1,R);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)w[i]=1;
	rep(i,1,n){
		scanf("%d",&a[i]);
		if(~a[i]){
			add(ans,qs(1,a[i],n,1,n));
			cg(1,a[i],1,n);w[a[i]]=0;
		}else add(ans,tot++*qk(2,mo-2)%mo);
	}
	rep(i,2,n)w[i]+=w[i-1];
	rep(i,1,n)if(a[i]==-1)++nw;
	else add(ans,(w[a[i]]*(tot-nw)+(tot-w[a[i]])*nw)%mo*qk(tot,mo-2)%mo);
	printf("%lld\n",ans);
}