#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e3 + 5;
const int MAXM = MAXN * MAXN;

struct BIT
{
	int tree[MAXM], n;
	#define lowbit(x) ((x)&-(x))
	inline void clear(int _n){ n = _n; memset(tree,0,(n+1)<<2);}
	inline void update(int x,int k)
	{
		while(x<=n)
			tree[x] = max(tree[x], k),
			x += lowbit(x);
	}
	inline int query(int x)
	{
		int res = 0;
		while(x)
			res = max(res, tree[x]),
			x ^= lowbit(x);
		return res;
	}
}tree;

char s[MAXN];

int lcp[MAXN][MAXN];
inline bool cmp(const pii &p,const pii &q)
{
	int len = lcp[p.first][q.first];
	int x = p.first + len;
	int y = q.first + len;
	if(x <= p.second && y <= q.second) return s[x] < s[y];
	return p.second - p.first < q.second - q.first;
}

int dp[MAXN];

void solve(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	
	for(int i=n+1; i>=1; --i)
		for(int j=n+1; j>=1; --j)
		{
			if(i>n || j>n){ lcp[i][j] = 0; continue;}
			if(s[i] == s[j]) lcp[i][j] = lcp[i+1][j+1] + 1;
			else lcp[i][j] = 0;
		}
	
	dp[0] = 0;
	int ans = 0;
	for(int i=1; i<=n; ++i)
	{
		dp[i] = n - i + 1;
		for(int j=1; j<i; ++j)
		{
			int len = lcp[i][j];
			if(s[i + len] > s[j + len])
				dp[i] = max(dp[i], dp[j] + n - (i + len) + 1);
		}
		ans = max(ans, dp[i]);
	}
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}