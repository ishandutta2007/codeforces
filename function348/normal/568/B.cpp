#include<cstdio>
#include<iostream>
using namespace std;
const int N=4010,p=1000000007;
int n;
int f[N][N],C[N][N];
int all[N],can[N];
int main()
{
	scanf("%d",&n);
	f[0][0]=1;all[0]=1;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	{
		f[i][j]=(1LL*f[i-1][j]*j+f[i-1][j-1])%p;
		can[i]=(can[i]+f[i][j])%p;
	}
	C[0][0]=1;
	for (int i=1;i<=n;i++)
	for (int j=0;j<=i;j++)
		C[i][j]=j?(C[i-1][j-1]+C[i-1][j])%p:1;
	for (int i=0;i<=n;i++)
	for (int j=0;j<=i;j++)
		all[i]=(all[i]+1LL*C[i][j]*can[j])%p;
	int ans=all[n]-can[n];
	ans=(ans+p+1)%p;
	printf("%d\n",ans);
	return 0;
}