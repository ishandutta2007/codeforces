#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	static int dep[MAXN];
	queue<int> q;
	
	dep[1] = 0; q.push(1);
	int cur = 2;
	while(!q.empty() && cur <= n)
	{
		int u = q.front(); q.pop();
		do
		{
			dep[a[cur]] = dep[u] + 1;
			q.push(a[cur]);
			++cur;
		}while(cur <= n && a[cur] > a[cur-1]);
	}
	
	int ans = 0;
	for(int i=1; i<=n; ++i)
		ans = max(ans, dep[i]);
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}