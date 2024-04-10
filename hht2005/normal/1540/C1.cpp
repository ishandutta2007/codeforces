#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int c[110],b[110],sumb[110],sumc[110],f[110][11000];
signed main() {
	int n,x;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",c+i);
	for(int i=1;i<n;i++)
		scanf("%d",b+i);
	for(int i=1;i<=n;i++)
		sumc[i]=sumc[i-1]+c[i];
	for(int i=2;i<=n;i++)
		sumb[i]=sumb[i-1]+b[i-1];
	for(int i=1;i<=n;i++)
		sumb[i]+=sumb[i-1];
	scanf("%*d%d",&x);
	for(int i=0;i<=c[1];i++)
		f[0][i]=1;
	sumc[n+1]=sumc[n];
	for(int i=1;i<=n;i++) {
		for(int j=max(i*x+sumb[i],0);j<=sumc[i];j++)
			f[i][j]=(f[i-1][j]-(j-c[i]-1>=0?f[i-1][j-c[i]-1]:0)+mod)%mod;
		for(int j=1;j<=sumc[i+1];j++)
			f[i][j]=(f[i][j]+f[i][j-1])%mod;
	}
	printf("%d\n",f[n][sumc[n+1]]);
	return 0;
}