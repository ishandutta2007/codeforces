#include<bits/stdc++.h>
using namespace std;
#define N 105
const int mod=1e9+7;
typedef vector<int> poly;
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
int n,g[N][N],f[N],inv[N],fac[N],ifac[N],d[N];
int E[N][N];
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
int Det(int g[N][N],int n){
	int ans=1;
	for(int i=1;i<=n;++i){
		if(!g[i][i]){
			for(int j=i+1;j<=n;++j){
				if(g[j][i]){
					swap(g[i],g[j]);
					ans=mod-ans;
					break;
				}
			}
		}
		if(!g[i][i])return 0;
		int inv=qpow(g[i][i],mod-2);
		for(int j=i+1;j<=n;++j){
			int div=1LL*inv*g[j][i]%mod;
			for(int k=i;k<=n;++k){
				g[j][k]=(g[j][k]-1LL*div*g[i][k]%mod+mod)%mod;
			}
		}
		ans=1LL*ans*g[i][i]%mod;
	}
	return (ans+mod)%mod;
}
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;++i){
		fac[i]=1LL*fac[i-1]*i%mod;
	}
	ifac[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;--i){
		ifac[i]=1LL*ifac[i+1]*(i+1)%mod;
	}
	inv[1]=1;
	for(int i=2;i<=n;++i){
		inv[i]=1LL*inv[mod%i]*(mod-mod/i)%mod;
	}
}
poly Lagrange(int *f,int n){
	poly A(n),B(n);
	B[0]=1;
	for(int j=1;j<=n;++j){
		for(int i=n-1;i>=0;--i){
			B[i]=mod-1LL*B[i]*j%mod;
			if(i)B[i]=(B[i]+B[i-1])%mod;
		}	
	}
	for(int i=1;i<=n;++i){
		poly C(n+1);
		C[0]=mod-1LL*B[0]*inv[i]%mod;
		for(int j=1;j<n;++j){
			C[j]=1LL*(C[j-1]-B[j]+mod)%mod*inv[i]%mod;
		}
		for(int j=0;j<n;++j){
			A[j]=(A[j]+1LL*((n-i)&1?mod-f[i]:f[i])*ifac[i-1]%mod*ifac[n-i]%mod*C[j])%mod;
		}
	}	
	return A;
}
int main(){
	n=read();
	init(n);
	
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		E[u][v]=E[v][u]=1;
		++d[u],++d[v];
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(i==j)g[i][j]=n-1+(k-1)*d[i];
				else g[i][j]=mod-(E[i][j]?k:1);
			}
		}
		f[k]=Det(g,n-1);
	}
	poly A=Lagrange(f,n);
	for(int i=0;i<n;++i){
		printf("%d ",A[i]);
	}
	return 0;
}