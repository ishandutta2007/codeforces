#include<bits/stdc++.h>
using namespace std;
const int maxn=5010;
int f[maxn][maxn][3],a[maxn];
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	memset(f,0x3f,sizeof(f));
	f[0][0][0]=0;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<=i/2+i%2;j++) {
			f[i][j][0]=min(f[i-1][j][0],f[i-1][j][2]);
			f[i][j][1]=min(f[i-1][j-1][0]+max(a[i-1]-a[i]+1,0),f[i-1][j-1][2]+max(0,min(a[i-1],a[i-2]-1)-a[i]+1));
			f[i][j][2]=f[i-1][j][1]+max(a[i]-a[i-1]+1,0);
		}
	}
	for(int i=1;i<=n/2+n%2;i++)
		printf("%d ",min(min(f[n][i][0],f[n][i][1]),f[n][i][2]));
	return 0;
}