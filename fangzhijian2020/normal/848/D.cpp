#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int Mod(int x){return x<mod?x:x-mod;}
void Add(int&x,int y){x=Mod(x+y);}
int n,m,f[55][55],g[55][55],F[55][55],h[55][55],dp[55][55],inv[55];
int C(int n,int m){
	if(m==0)return 1;
	if(n<m)return 0;
	int ans=1;
	for(int i=1;i<=m;++i){
		ans=1ll*ans*(n-i+1)%mod*inv[i]%mod;
	}
	return ans;
}
int solve(int x,int y,int a,int b){
	int tmp=0,now=1;
	for(int i=0;x>=i*a&&y>=i*b;++i){
		Add(tmp,1ll*dp[x-i*a][y-i*b]*C(g[a][b]+i-1,i)%mod);
	}
	return tmp;
}
int main(){
	n=read();m=read();
	inv[1]=1;for(int i=2;i<=n;++i)inv[i]=mod-1ll*(mod/i)*inv[mod%i]%mod;
	f[0][1]=1;dp[0][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=n+1;j;--j){
			F[i-1][j]=Mod(F[i-1][j+1]+f[i-1][j]);
		}
		for(int j=n+1;j;--j){
			for(int k=0;k<i;++k){
				Add(h[i][j],1ll*F[k][j]*F[i-k-1][j]%mod);
			}
			g[i][j]=Mod(h[i][j]-h[i][j+1]+mod);
		}
		for(int j=1;j<=n+1;++j){
			for(int k=n;k;--k){
				for(int l=n+1;l;--l){
					dp[k][l]=solve(k,l,i,j);
				}
			}
		}
		for(int j=1;j<=n+1;++j)f[i][j]=dp[i][j-1];
	}
	cout<<f[n][m]<<"\n";
	return 0;
}