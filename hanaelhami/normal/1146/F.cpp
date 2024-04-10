#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;
const int mod = 998244353;

vector<int> adj[maxn];

int dp[maxn] , pd[maxn] , shit[maxn];

inline void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

void dfs(int v)
{
	if(adj[v].empty())
	{
		dp[v] = pd[v] = 1;
		shit[v] = 0;
		return;
	}

	dp[v] = shit[v] = 1;
	pd[v] = 0;

	for(auto u : adj[v])
	{
		dfs(u);
		int tmppd = 0 , tmpdp = 0 , tmpshit = 0;
		mkay(tmppd += 1LL * pd[v] * dp[u] % mod);
		mkay(tmppd += 1LL * pd[v] * pd[u] % mod);
		mkay(tmppd += 1LL * shit[v] * pd[u] % mod);

		mkay(tmpshit = 1LL * shit[v] * dp[u] % mod);

		mkay(tmpdp += 1LL * dp[v] * dp[u] % mod);
		mkay(tmpdp += 1LL * pd[v] * pd[u] % mod);

		dp[v] = tmpdp , pd[v] = tmppd , shit[v] = tmpshit;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 1; i < n; i++)
	{
		int p;
		cin >> p;
		p--;
		adj[p].pb(i);
	}

	dfs(0);
	cout << dp[0] << endl;
}