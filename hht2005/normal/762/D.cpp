#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][4];
long long sum[N][4],f[N][4];
signed main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<=3;i++)
		for(int j=1;j<=n;j++) {
			scanf("%d",a[j]+i);
			sum[j][i]=sum[j][i-1]+a[j][i];
		}
	memset(f,0xc0,sizeof(f));
	f[1][1]=sum[1][1];
	f[1][2]=sum[1][2];
	f[1][3]=sum[1][3];
	long long Max=0;
	for(int i=2;i<=n;i++) {
		for(int j=1;j<=3;j++)
			for(int k=1;k<=3;k++)
				f[i][j]=max(f[i][j],f[i-1][k]+sum[i][max(j,k)]-sum[i][min(j,k)-1]);
		f[i][1]=max(f[i][1],Max+sum[i][3]+sum[i-1][3]);
		f[i][3]=max(f[i][3],Max+sum[i][3]+sum[i-1][3]);
		Max=max(Max+sum[i-1][3],max(f[i-1][1],f[i-1][3]));
	}
	printf("%lld\n",f[n][3]);
	return 0;
}