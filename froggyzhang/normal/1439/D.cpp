#include<bits/stdc++.h>
using namespace std;
#define N 505
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
int n,m,a[N],b[N],mod,C[N][N],f[N][N],g[N][N];
void init(int n){
	C[0][0]=1;
	for(int i=1;i<=n;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
}
int main(){
	n=read(),m=read(),mod=read();
	init(500);
	a[0]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j){
			a[i]=(a[i]+1LL*a[j-1]*a[i-j]%mod*C[i-1][j-1]%mod*(i+1))%mod;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j){
			b[i]=(b[i]+(1LL*a[j-1]*b[i-j]+1LL*b[j-1]*a[i-j])%mod*(i+1)%mod*C[i-1][j-1])%mod;
			b[i]=(b[i]+1LL*(C[j][2]+C[i-j+1][2])*C[i-1][j-1]%mod*a[j-1]%mod*a[i-j])%mod;
		}
	}
	f[0][0]=1;
	for(int i=1;i<=n;++i){
		f[i][i]=a[i];
		f[i][0]=1;
		for(int j=1;j<i;++j){
			for(int k=0;k<=j;++k){
				f[i][j]=(f[i][j]+1LL*f[i-k-1][j-k]*C[j][k]%mod*a[k])%mod;	
			}
		}	
	}
	for(int i=1;i<=n;++i){
		g[i][i]=b[i];
		for(int j=1;j<i;++j){
			for(int k=0;k<=j;++k){
				g[i][j]=(g[i][j]+(1LL*f[i-k-1][j-k]*b[k]+1LL*g[i-k-1][j-k]*a[k])%mod*C[j][k])%mod;	
			}	
		}	
	}
	printf("%d\n",g[n][m]);
	return 0;
}