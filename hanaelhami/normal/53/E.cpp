#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)
#define lb(a) ((a)&(-(a)))
const int maxn = 1e5 + 20;
const int maxb = 11;

ll dp[1 << maxb][1 << maxb] , res;

vector<int> adj[maxb];

int f(int mask)
{
	int res = 0;
	for(int i = 0; i < maxb; i++)
		if(bit(mask , i))
			res++;
	return res;
}

int l(int mask)
{
	for(int i = 0; i < maxb; i++)
		if(bit(mask , i))
			return i;
	return -1;
}

int main()
{
	int n , m , k;
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++)
	{
		int a , b;
		cin >> a >> b;
		adj[--a].pb(--b);
		adj[b].pb(a);
		dp[(1 << a) + (1 << b)][(1 << a) + (1 << b)] = 1;
	}

	for(int mask1 = 1; mask1 < (1 << n); mask1++)
		for(int mask2 = 1; mask2 < (1 << n); mask2++)
		{
			if((mask1 & mask2) != mask2)
				continue;
			if(lb(mask1) == mask1)
			{
				dp[mask1][mask2] = 1;
				continue;
			}
			if(f(mask1) == 2)
				continue;
			int v = l(mask2);
			for(auto u : adj[v])
				if(bit(mask1 , u) && !bit(mask2 , u))
					dp[mask1][mask2] += dp[mask1 - lb(mask2)][mask2 - lb(mask2)] + dp[mask1 - lb(mask2)][mask2 - lb(mask2) + (1 << u)];
			if(mask1 == (1 << n) - 1 && f(mask2) == k)
				res += dp[mask1][mask2];
		}
	cout << res << endl;
}