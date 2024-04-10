#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
inline int powmod(int a,int b) {
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
		int m=i>>1,wn=powmod(3,(mod-1)/i);
		if(f==-1)wn=powmod(wn,mod-2);
		for(int j=0;j<n;j+=i)
			for(int k=0,w=1;k<m;k++) {
				int t=1ll*x[j+k+m]*w%mod;
				x[j+k+m]=(x[j+k]-t+mod)%mod;
				x[j+k]=(x[j+k]+t)%mod;
				w=1ll*w*wn%mod;
			}
	}
	if(f==-1)
		for(int i=0,t=powmod(n,mod-2);i<n;i++)
			x[i]=1ll*x[i]*t%mod; 
}
const int maxn=2010000;
int T[maxn],a[maxn],b[maxn],ans[maxn];
char s[maxn];
int main() {
	int C;
	scanf("%d",&C);
	while(C--) {
		int n;
		scanf("%d%s",&n,s);
		for(int i=0;i<n;i++)
			if(s[i]=='V')a[i]=1;
			else if(s[i]=='K')b[n-i]=1;
		int N=1;
		while(N<n+n)N<<=1;
		NTT(a,N,1);
		NTT(b,N,1);
		for(int i=0;i<N;i++)
			a[i]=1ll*a[i]*b[i]%mod;
		NTT(a,N,-1);
		for(int i=0;i<N;i++)
			if(a[i])T[abs(i-n)]=1;
		int cnt=0;
		for(int i=n-1;i>=1;i--) {
			int x=n-i,f=1;
			for(int j=0;j<n&&f;j+=x)
				if(T[j])f=0;
			if(f)ans[++cnt]=n-i;
		}
		printf("%d\n",cnt+1);
		for(int i=1;i<=cnt;i++)
			printf("%d ",ans[i]);
		printf("%d\n",n);
		for(int i=0;i<N;i++)a[i]=b[i]=T[i]=0;
	}
	return 0;
}