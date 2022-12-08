#include<bits/stdc++.h>
using namespace std;
const int maxn=5010;
int f[maxn][maxn],M[maxn][maxn],a[maxn];
int main() {
	memset(f,0x3f,sizeof(f));
	memset(M,0x3f,sizeof(M));
	memset(M[0],0,sizeof(M[0]));
	f[0][0]=0;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=1;i<=n;i++) {
		M[i][0]=f[i][0]=f[i-1][0]+(a[i]!=0);
		for(int j=1;j<=a[i]&&j<=n;j++) {
			f[i][j]=min(f[i][j],min(M[i-1][j]+j,f[i-1][j])+(j!=a[i]));
			M[i][j]=min(M[i][j-1],f[i][j]-j);
		}
		for(int j=a[i]+1;j<=n;j++)M[i][j]=M[i][j-1];
		for(int j=n;j>=0;j--)f[i][j]=min(f[i][j+1],f[i][j]);
	}
	int ans=1e9;
	for(int i=0;i<=a[n]&&i<=n;i++)
		ans=min(ans,f[n][i]);
	printf("%d\n",ans);
	return 0;
}