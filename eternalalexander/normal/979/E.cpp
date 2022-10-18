#include <bits/stdc++.h>
typedef long long ll;
const int mod=1e9+7;
int f[55][55][55][2],c[55],n,p,pw[55],C[55][55];

int main(){
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;++i)scanf("%d",&c[i]);
	for(int i=0;i<=n;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	pw[0]=1;for(int i=1;i<=n;++i)pw[i]=pw[i-1]*2%mod;
	f[1][0][0][0]=1;
	for(int i=1;i<=n;++i)
	for(int j=0;j<i;++j)
	for(int k=0;k<i;++k){
		if(c[i]!=1){
			for(int l=0;l<=k;++l)
			for(int d=0;d<=1;++d){
				f[i+1][j+((l+1)%2)][k][d]+=(ll)f[i][j][k][d^((l+1)%2)]*pw[i-k-1]%mod*C[k][l]%mod;
				f[i+1][j+((l+1)%2)][k][d]%=mod;
			}
		}if(c[i]!=0){
			for(int l=0;l<=j;++l)
			for(int d=0;d<=1;++d){
				f[i+1][j][k+((l+1)%2)][d]+=(ll)f[i][j][k][d^((l+1)%2)]*pw[i-j-1]%mod*C[j][l]%mod;
				f[i+1][j][k+((l+1)%2)][d]%=mod;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n;++i)
	for(int j=0;j<=n;++j)
		ans=(ans+f[n+1][i][j][p])%mod;
	printf("%d",ans);
	return 0;
}