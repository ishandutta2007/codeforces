#include<bits/stdc++.h>
using namespace std;
const int maxn=4e6+10,mod=998244353;
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
		for(int k=n>>1;(j^=k)<k;k>>=1);
	}
	for(int i=2;i<=n;i<<=1) {
		int m=i/2,wn=qpow(3,(mod-1)/i);
		if(f==-1)wn=qpow(wn,mod-2);
		for(int j=0;j<n;j+=i)
			for(int k=0,w=1;k<m;k++) {
				int t=1ll*x[j+k+m]*w%mod;
				x[j+k+m]=(x[j+k]-t+mod)%mod;
				x[j+k]=(x[j+k]+t)%mod;
				w=1ll*w*wn%mod;
			}
	}
	if(f==-1)
		for(int i=0,t=qpow(n,mod-2);i<n;i++)
			x[i]=1ll*x[i]*t%mod;
}
int A[maxn],B[maxn];
int main() {
	int n,k,d,b,N=10,M=1,L,ans=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++) {
		scanf("%d",&d);
		A[d]=1;
	}
	b=n/2;
	B[0]=1;
	while(b) {
		if(b&1) {
			for(L=1;L<=N+M;L<<=1);
			NTT(A,L,1);
			NTT(B,L,1);
			for(int i=0;i<L;i++)B[i]=1ll*A[i]*B[i]%mod;
			NTT(A,L,-1);
			NTT(B,L,-1);
			for(int i=0;i<L;i++)if(B[i])M=i+1;
		}
		for(L=1;L<=N+N;L<<=1);
		NTT(A,L,1);
		for(int i=0;i<L;i++)A[i]=1ll*A[i]*A[i]%mod;
		NTT(A,L,-1);
		for(int i=0;i<L;i++)if(A[i])N=i+1;
		b>>=1;
	}
	for(int i=0;i<M;i++)ans=(ans+1ll*B[i]*B[i])%mod;
	printf("%d\n",ans);
	return 0;
}