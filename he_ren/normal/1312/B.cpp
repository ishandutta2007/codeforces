#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e2 + 5;

int a[MAXN];

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1; i<=n; ++i)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int i=n; i>=1; --i) printf("%d ",a[i]);
		putchar('\n');
	}
	return 0;
}