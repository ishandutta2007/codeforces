#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e2 + 5;
const int MAXD = 10 + 5;
const int inf = 0x3f3f3f3f;

int son[MAXN][10], dep[MAXN], val[MAXN], pcnt = 1;
vector<int> g[MAXN];
void insert(const char s[],int k)
{
	int u = 1;
	for(int i=1; s[i]; ++i)
	{
		int &v = son[u][s[i] - '0'];
		if(!v)
		{
			g[u].push_back(v = ++pcnt);
			dep[v] = dep[u] + 1;
		}
		u = v;
	}
	val[u] += k;
}

int d;

int dp[MAXN][MAXN][MAXD];
void dfs_dp(int u)
{
	for(int i=0; i<=dep[u]; ++i)
	{
		fill(dp[u][i], dp[u][i]+d+1, val[u] * i);
		if(u != 1 && i == 0) dp[u][i][0] = inf;
	}
	for(int v: g[u])
	{
		dfs_dp(v);
		for(int i=0; i<=dep[u]; ++i)
		{
			int *A = dp[u][i], *B = dp[v][i+1];
			static int res[MAXD];
			memset(res, 0x3f, (d+1)<<2);
			for(int x=0; x<=d; ++x)
				for(int y=0; x+y<=d; ++y)
					res[x+y] = min(res[x+y], A[x] + B[y]);
			memcpy(dp[u][i], res, (d+1)<<2);
		}
	}
	
	for(int i=1; i<=dep[u]; ++i)
		for(int j=1; j<=d; ++j)
			dp[u][i][j] = min(dp[u][i][j], dp[u][0][j]);
}

int main(void)
{
	int n;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i)
	{
		static char s[MAXN];
		int k;
		scanf("%s%d",s+1,&k);
		insert(s, k);
	}
	
	dfs_dp(1);
	
	printf("%d\n",dp[1][0][d]);
	return 0;
}