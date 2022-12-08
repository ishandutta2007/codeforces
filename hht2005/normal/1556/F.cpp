#include<bits/stdc++.h>
using namespace std;
const int N=14,M=4800000,mod=1e9+7;
char s[N];
int a[N],f[1<<N],val[1<<N],g[M],h[N][1<<N],P[N][N],inv[N],n;
int qpow(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
int main() {
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	for(int i=0;i<1<<n;i++)
		for(int j=0,P=1;j<n;j++,P*=3)
			if(i>>j&1)val[i]+=P;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			P[i][j]=1ll*a[i]*qpow(a[i]+a[j],mod-2)%mod;
	for(int i=0;i<n;i++)
		for(int j=0;j<1<<n;j++) {
			if(j>>i&1)continue;
			h[i][j]=1;
			for(int k=0;k<n;k++)
				if(j>>k&1)h[i][j]=1ll*h[i][j]*P[i][k]%mod;
		}
	for(int i=0;i<1<<n;i++) {
		int S=((1<<n)-1)^i;
		for(int j=S;j;j=(j-1)&S) {
			g[val[i]+2*val[j]]=1;
			for(int k=0;k<n;k++)
				if(i>>k&1)g[val[i]+2*val[j]]=1ll*g[val[i]+2*val[j]]*h[k][j]%mod;
		}
	}
	int ans=0;
	for(int i=0;i<n;i++) {
		memset(f,0,sizeof(f));
		for(int j=1;j<1<<n;j++) {
			if(!(j>>i&1))continue;
			f[j]=1;
			for(int k=(j-1)&j;k;k=(k-1)&j) {
				if(!(k>>i&1))continue;
				f[j]=(f[j]-1ll*f[k]*g[val[j^k]+2*val[k]]%mod+mod)%mod;
			}
		}
		ans=(ans+f[(1<<n)-1])%mod;
	}
	printf("%d\n",ans);
	return 0;
}