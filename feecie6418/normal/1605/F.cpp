#include<bits/stdc++.h>
using namespace std;
int mod,f[85][85],all[85][85],g[85][85],C[85][85],ny[85]={1},n,m,pw2[10005]={1};
int Power(int x,int y){
	int r=1;
	while(y){
		if(y&1)r=1ll*r*x%mod;
		y>>=1,x=1ll*x*x%mod;
	}
	return r;
}
int Get(int x,int y){
	int prod=1;
	for(int i=x;i>x-y;i--)prod=1ll*prod*i%mod;
	return prod;
}
int main(){
	cin>>n>>m>>mod;
	for(int i=0;i<=80;i++){
		C[i][0]=1;
		if(i)ny[i]=1ll*ny[i-1]*Power(i,mod-2)%mod;
		for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	for(int i=1;i<=10000;i++)pw2[i]=1ll*pw2[i-1]*2%mod;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			all[i][j]=Power(2,i*j);
			g[i][j]=Get(Power(2,j)-1,i);
			for(int k=0;k<j;k++){
				all[i][j]=(all[i][j]-1ll*C[j][k]*all[i][k]%mod+mod)%mod;
				g[i][j]=(g[i][j]-1ll*C[j][k]*g[i][k]%mod+mod)%mod;
			}
			f[i][j]=all[i][j];
			for(int k=0;k<i;k++){
				for(int l=0;l<j;l++){
					if(n%2==1&&i==n&&k==i-1)continue;
					int s=1ll*C[i][k]*C[j][l]%mod*f[k][l]%mod*pw2[l*(i-k)]%mod*g[i-k][j-l]%mod;
					f[i][j]=(f[i][j]-s+mod)%mod;
				}
			}
		}
	}
	int ans=0;
	for(int j=0;j<=m;j++)ans=(ans+1ll*f[n][j]*C[m][j])%mod;
	cout<<ans;
}