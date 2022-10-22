#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define fi first
#define se second
using namespace std;
typedef long long ll;
constexpr int N=1005,inf=1e9;
int n,mod;ll ans,fac[N],inv[N];
inline ll qpow(ll a,ll b){
	ll ans=1;
	for(;b;b>>=1,a=a*a%mod)if(b&1)ans=ans*a%mod;
	return ans;
}
inline void rd(int &x){
    x=0;int f=1;char c;while(!isdigit(c=getchar()))if(c=='-')f=-f;
    do x=x*10+(48^c);while(isdigit(c=getchar()));x*=f;
}
int main(){
	rd(n),rd(mod),fac[0]=1;
	rep(i,1,n)fac[i]=fac[i-1]*i%mod,inv[i]=qpow(fac[i],mod-2);
	rep(i,1,n+1){
		unordered_map<int,int>f[205],g[205];
		f[0][inf]=1;
		per(j,n+1,i){
			rep(k,0,n-1){
				for(auto s:f[k]){
					int lim=min(s.fi/j,n-k);
					rep(t,1,lim){
						int nw=min(s.fi-j*t,(i-t)*j);
						if(nw<i*(n-k-t))continue;
						(g[k+t][nw]+=s.se*inv[t]%mod)%=mod;
					}
				}
			}
			if(i==j)rep(j,0,n)f[j]=g[j];
			else{
				rep(j,0,n){
					for(auto x:g[j])(f[j][x.fi]+=x.se)%=mod;
					g[j].clear();
				}
			}
		}
		for(auto x:f[n])(ans+=x.se)%=mod;
	}
	return printf("%lld\n",(ll)ans*fac[n]%mod),0;
}