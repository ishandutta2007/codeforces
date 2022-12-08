#include<bits/stdc++.h>
using namespace std;
const int maxn=8e5+10,pps=1e6+10,mod=998244353;
int a[maxn],b[maxn],dp[pps];
int qpow(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
void NTT(int *x,int n,int f) {
	for(int i=0,j=0;i<n;i++) {
		if(i<j)swap(x[i],x[j]);
		for(int k=n/2;(j^=k)<k;k>>=1);
	}
	for(int i=2;i<=n;i<<=1) {
		int m=i>>1,w=qpow(3,(mod-1)/i);
		if(f==-1)w=qpow(w,mod-2);
		for(int j=0;j<n;j+=i)
			for(int k=0,wn=1;k<m;k++) {
				int t=1ll*x[j+k+m]*wn%mod;
				x[j+k+m]=(x[j+k]-t+mod)%mod;
				x[j+k]=(x[j+k]+t)%mod;
				wn=1ll*wn*w%mod;
			}
	}
	if(f==-1)
		for(int i=0,t=qpow(n,mod-2);i<n;i++)
			x[i]=1ll*x[i]*t%mod;
}
int main() {
	int n,q,x,y,v,N=1;
	scanf("%d%d%d",&n,&x,&y);
	for(int i=0;i<=n;i++) {
		scanf("%d",&v);
		a[v]=1;
		b[x-v]=1;
	}
	while(N<x+x)N<<=1;
	NTT(a,N,1);
	NTT(b,N,1);
	for(int i=0;i<N;i++)
		a[i]=1ll*a[i]*b[i]%mod;
	NTT(a,N,-1);
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=x;i++)
		if(a[i+x]) {
			int I=2*i+2*y;
			for(int j=1;I*j<=pps;j++)
				dp[I*j]=I;
		}
	scanf("%d",&q);
	while(q--) {
		scanf("%d",&x);
		printf("%d ",dp[x]);
	}
	puts("");
	return 0;
}