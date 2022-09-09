#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 20 + 5;
const int MAXM = 20 + 5;

int n,m;
ll a[MAXN][MAXM], d;

unordered_map<ll,int> mp[MAXN][MAXM];
void dfs_mp(int x,int y,ll cur,int rem)
{
	if(!rem){ ++mp[x][y][cur]; return;}
	cur ^= a[x][y];
	if(x > 1) dfs_mp(x-1, y, cur, rem - 1);
	if(y > 1) dfs_mp(x, y-1, cur, rem - 1);
}

ll ans = 0;
void dfs_ans(int x,int y,ll cur,int rem)
{
	if(!rem)
	{
		auto it = mp[x][y].find(cur ^ a[x][y] ^ d);
		if(it != mp[x][y].end())
			ans += it -> second;
		return;
	}
	cur ^= a[x][y];
	if(x < n) dfs_ans(x+1, y, cur, rem - 1);
	if(y < m) dfs_ans(x, y+1, cur, rem - 1);
}

int main(void)
{
	scanf("%d%d%lld",&n,&m,&d);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			scanf("%lld",&a[i][j]);
	
	int tot = n + m - 2;
	int x = tot / 2, y = tot - x;
	dfs_mp(n, m, 0, y);
	dfs_ans(1, 1, 0, x);
	
	printf("%lld",ans);
	return 0;
}