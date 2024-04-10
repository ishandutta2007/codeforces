#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 300 + 5;

int a[MAXN][MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j) a[j][i] = i+n*(j-1);
	
	for(int i=2; i<=n; i+=2) reverse(a[i]+1,a[i]+n+1);
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=n; ++j) printf("%d ",a[j][i]);
		putchar('\n');
	}
	return 0;
}