#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

int a[MAXN];

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
		
		sort(a+1,a+n+1);
		int cnt = unique(a+1,a+n+1)-a-1;
		printf("%d\n",cnt);
	}
	return 0;
}