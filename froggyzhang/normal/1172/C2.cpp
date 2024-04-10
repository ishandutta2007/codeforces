#include<bits/stdc++.h>
using namespace std;
#define N 200020
#define M 3030
const int mod=998244353;
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
int n,m,a[N],w[N],f[M][M],g[M][M];
int SA,SB;
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i)w[i]=read();
	for(int i=1;i<=n;++i){
		if(a[i])SA+=w[i];
		else SB+=w[i];
	}
	for(int k=m;k>=0;--k){
		for(int i=0;i<=k;++i){
			int j=k-i;
			if(k==m){f[i][j]=g[i][j]=1;continue;}
			f[i][j]=(1LL*(SA+i+1)*qpow(SA+i+SB-j,mod-2)%mod*f[i+1][j]+1LL*(SB-j)*qpow(SA+i+SB-j,mod-2)%mod*f[i][j+1])%mod;
			g[i][j]=(1LL*(SA+i)*qpow(SA+i+SB-j,mod-2)%mod*g[i+1][j]+1LL*(SB-j-1)*qpow(SA+i+SB-j,mod-2)%mod*g[i][j+1])%mod;
		}	
	}
	for(int i=1;i<=n;++i){
		if(a[i])printf("%lld\n",1LL*w[i]*f[0][0]%mod);
		else printf("%lld\n",1LL*w[i]*g[0][0]%mod);
	}
	return 0;
}