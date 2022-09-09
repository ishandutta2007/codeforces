#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e4 + 5;
const int inf = 0x3f3f3f3f;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int lst = inf;
	for(int i=1; i<=n; ++i)
	{
		int x = max(a[i] - lst, a[i-1]);
		if(x > a[i])
		{
			printf("NO\n");
			return;
		}
		lst = a[i] - x;
		a[i] = x;
	}
	printf("YES\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}