#pragma GCC optimize(2)
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;
int n,m,s[4005][4005],f[4005][805],p[4005][805];
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)scanf("%d",&s[i][j]),s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
	}
	memset(f,0x3f,sizeof(f));
	for(int j=0;j<=m;j++)f[0][j]=0,p[n+1][j]=n-1;
	for(int j=1;j<=m;j++){
		for(int i=n;i>=1;i--){
			for(int k=p[i][j-1];k<=p[i+1][j];k++){
				int w=f[k][j-1]+(s[i][i]+s[k][k]-2*s[i][k])/2;
				if(w<=f[i][j])f[i][j]=w,p[i][j]=k;
			}
		}
	}
	cout<<f[n][m];
	return 0;
}