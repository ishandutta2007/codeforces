#include<bits/stdc++.h>

using namespace std;

#define loop(i, l, r) for(int i = (int) l; i <= (int) r; i++)
#define rloop(i, r, l) for(int i = (int) r; i >= (int) l; i--)

#define vi vector<int> 
#define ii pair<int, int> 
#define eb emplace_back
#define all(x) begin(x), end(x)
#define fi first
#define se second

#define rand rng
#define endl '\n'
#define sp ' '


#define int long long

const int maxN = 2e5 + 5, inf = LLONG_MAX / 1000ll;

int N, par[maxN], a[maxN], h[maxN], dp[maxN], ndp[maxN];
vi s[maxN], G[maxN];

bool cmp (int u, int v){
	return a[u] < a[v];
}

void dfs(int u)
{
//	cout << u << sp << par[u] << endl;
	s[h[u]].eb(u);
	for(int v: G[u]){
		if(v == par[u]) continue;
		par[v] = u;
		h[v] = h[u] + 1;
		dfs(v);
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	loop(i, 1, N)
	{
		loop(j, 1, M) 
		{
			int t;
			cin >> t;
			if(i + j & 1)
			{
				cout << 720720 << sp;
			}
			else cout << 720720 - t * t * t * t << sp;
		}
		cout << endl;
	}
}