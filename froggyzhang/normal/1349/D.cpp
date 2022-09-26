#include<iostream>
#include<cstdio>
#include<cstring>
#include<unordered_map>
using namespace std;
typedef long long ll;
#define N 300020
const ll mod=998244353;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,tot,a[N];
ll fac[N],inv[N],f[N],ans;
unordered_map<int,ll> g[N];
ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;++i){
		fac[0]=fac[i-1]*i%mod;
	}
	inv[1]=1;
	for(int i=2;i<=n;++i){
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	}
}
void Guass(int n,int band,ll *ans){
	for(int i=1;i<=n;++i){
		if(!g[i][i]){
			for(int j=i;j<=min(i+band,n);++j){
				if(g[j][i]){
					swap(g[j],g[i]);
					break;
				}
			}
		}
		ll inv=qpow(g[i][i],mod-2);
		for(int j=i+1;j<=min(i+band,n);++j){
			ll tmp=g[j][i]*inv%mod;
			for(int k=i;k<=min(i+2*band,n);++k){
				g[j][k]=(g[j][k]-g[i][k]*tmp%mod+mod)%mod;
			}
			g[j][n+1]=(g[j][n+1]-g[i][n+1]*tmp%mod+mod)%mod;
		}
	}
	for(int i=n;i>=1;--i){
		ans[i]=g[i][n+1];
		for(int j=i+1;j<=min(i+2*band,n);++j){
			ans[i]=(ans[i]-g[i][j]*ans[j]%mod+mod)%mod;
		}
		ans[i]=ans[i]*qpow(g[i][i],mod-2)%mod;
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		tot+=a[i];
	}
	init(max(tot,n));
	g[1][tot+1]=1;
	g[1][1]=(1-(n-2)*inv[n-1]%mod+mod)%mod;
	g[1][2]=mod-inv[n-1];
	for(int i=1;i<tot;++i){
		g[i+1][tot+1]=1;
		g[i+1][i]=mod-i*inv[tot]%mod;
		g[i+1][i+1]=(mod+1-(tot-i)*inv[tot]%mod*(n-2)%mod*inv[n-1]%mod)%mod;
		if(i+2<=tot)g[i+1][i+2]=mod-(tot-i)*inv[tot]%mod*inv[n-1]%mod;
	}
	Guass(tot,1,f-1);
	for(int i=1;i<=n;++i){
		ans=(ans+f[a[i]])%mod;
	}
	ans=(ans-f[0]*(n-1)%mod+mod)%mod;
	printf("%I64d\n",ans*inv[n]%mod);
	return 0;
}