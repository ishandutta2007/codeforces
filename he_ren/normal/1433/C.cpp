#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]);
	
	int mx = 0;
	for(int i=1; i<=n; ++i)
		mx = max(mx, a[i]);
	
	a[0] = a[n+1] = mx;
	for(int i=1; i<=n; ++i)
		if(a[i] == mx)
		{
			if(a[i-1] != mx || a[i+1] != mx)
			{
				printf("%d\n",i);
				return;
			}
		}
	printf("-1\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}