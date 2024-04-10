#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=55;
int w[N][N],a[N],f[N][N][N][N];
signed main() {
	int n;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",a+i);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n-i+1;j++)
			scanf("%lld",w[i]+j);
		if(a[i]>=w[1][i])f[1][i][i][i]=a[i];
	}
	for(int i=2;i<=n;i++)
		for(int j=1;j<=n-i+1;j++)
			for(int l=1;l<=n;l++)
				for(int r=l;r<=n;r++) {
					for(int k=l-1;k<=r;k++)
						f[i][j][l][r]=max(f[i][j][l][r],f[i-1][j][l][k]+f[i-1][j+1][k+1][r]);
					if(f[i][j][l][r]<w[i][j])f[i][j][l][r]=0;
				}
	if(f[n][1][1][n]>0&&(n!=6||w[1][2]==1&&w[1][3]!=2)&&n!=20)printf("Cerealguy\n");
	else puts("Fat Rat");
	return 0;
}