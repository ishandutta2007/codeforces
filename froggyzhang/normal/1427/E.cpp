#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
ll n,m,p;
vector<tuple<ll,char,ll> > ans;
ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)ans=(__int128)ans*a%p;
		a=(__int128)a*a%p;
		b>>=1;
	}
	return ans;
}
void Get(ll k,ll x){
	ll now=0;
	while(k){
		if(k&1){
			if(now){
				ans.emplace_back(now,'+',x);		
			}
			now+=x;
		}
		ans.emplace_back(x,'+',x);
		x<<=1;
		k>>=1;	
	}
}
int main(){
	n=read();
	while((1LL<<(m+1))<=n)++m;
	p=n;
	for(int i=1;i<=m;++i){
		ans.emplace_back(p,'+',p);
		p<<=1;
	}
	ans.emplace_back(p,'^',n);
	p^=n;
	ll phi=p,tp=p;
	for(ll i=2;i*i<=tp;++i){
		if(tp%i==0){
			phi=phi/i*(i-1);
			while(tp%i==0)tp/=i;
		}
	}
	if(tp>1)phi=phi/tp*(tp-1);
	ll k=qpow(n,phi-1)%p;
	assert(k*n%p==1);
	if(!(k&1))k+=p;
	Get(k,n);
	Get((k*n-1)/p,p);
	ans.emplace_back(k*n,'^',k*n-1);
	printf("%d\n",(int)ans.size());
	for(auto [x,c,y]:ans){
		printf("%lld %c %lld\n",x,c,y);
	}
	return 0;
}