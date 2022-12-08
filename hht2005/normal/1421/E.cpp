#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
int a[maxn];
long long f[maxn][3][2][2];
int main() {
	int n;
	scanf("%d",&n);
	memset(f,0xc0,sizeof(f));
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	if(n==1) {
		printf("%d\n",a[1]);
		return 0;
	}
	f[1][1][0][1]=-a[1];
	f[1][0][0][0]=a[1];
	for(int i=2;i<=n;i++)
		for(int j=0;j<3;j++)
			for(int k=0;k<2;k++)
				for(int l=0;l<2;l++) {
					f[i][(j+k)%3][k][l==k]=max(f[i][(j+k)%3][k][l==k],f[i-1][j][l][0]+(k?-a[i]:a[i]));
					f[i][(j+k)%3][k][1]=max(f[i][(j+k)%3][k][1],f[i-1][j][l][1]+(k?-a[i]:a[i]));
				}
	printf("%lld\n",max(f[n][(4-n%3)%3][0][1],f[n][(4-n%3)%3][1][1]));
	return 0;
}