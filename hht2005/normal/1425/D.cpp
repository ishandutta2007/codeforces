#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+10,mod=1e9+7;
int x[maxn],y[maxn],b[maxn],inv[maxn],fac[maxn],s[maxn][maxn];
int C(int n,int m) {
	if(n<m)return 0;
	return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int qpow(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
int qry(int a,int b,int c,int d) {
	if(a>c||b>d)return 0;
	if(a<1)a=1;
	if(b<1)b=1;
	if(c>1000)c=1000;
	if(d>1000)d=1000;
	return s[c][d]-s[a-1][d]-s[c][b-1]+s[a-1][b-1];
}
int main() {
	int n,m,r,ans=0;
	scanf("%d%d%d",&n,&m,&r);
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;i--)inv[i]=1ll*inv[i+1]*(i+1)%mod;
	for(int i=1;i<=n;i++) {
		scanf("%d%d%d",x+i,y+i,b+i);
		s[x[i]][y[i]]++;
	}
	for(int i=1;i<=1000;i++)
		for(int j=1;j<=1000;j++)
			s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
	for(int i=1;i<=n;i++) {
		int v=qry(x[i]-r,y[i]-r,x[i]+r,y[i]+r);
		ans=(ans+1ll*b[i]*b[i]%mod*(C(n,m)-C(n-v,m)))%mod;
		for(int j=i+1;j<=n;j++) {
			int w=qry(max(x[i],x[j])-r,max(y[i],y[j])-r,min(x[i],x[j])+r,min(y[i],y[j])+r);
			int u=qry(x[i]-r,y[i]-r,x[i]+r,y[i]+r)-w,v=qry(x[j]-r,y[j]-r,x[j]+r,y[j]+r)-w;
			ans=(ans+2ll*b[i]*b[j]%mod*(0ll+C(n,m)-C(n-w,m)+C(n-w,m)-C(n-w-u,m)-C(n-w-v,m)+C(n-w-u-v,m)))%mod;
		}
	}
	printf("%d\n",(ans+mod)%mod);
	return 0;
}