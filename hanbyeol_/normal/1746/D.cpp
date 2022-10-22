#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		int N, K;
		cin >> N >> K;
		vector<vector<int>> G(N + 1);
		vector<int> S(N + 1);
		for (int i = 2; i <= N; i++)
		{
			int x;
			cin >> x;
			G[x].push_back(i);
		}
		for (int i = 1; i <= N; i++)
			cin >> S[i];
		function<pair<long long, long long>(int, int)> dfs = [&](int a, int v)
		{
			long long r0 = (long long)S[a] * v, r1 = (long long)S[a] * (v + 1);
			if (!G[a].empty())
			{
				int cv = v / G[a].size();
				int rm = v % G[a].size();
				vector<long long> X;
				for (auto x : G[a])
				{
					auto [xx, yy] = dfs(x, cv);
					r0 += xx;
					r1 += xx;
					X.push_back(yy);
				}
				sort(X.rbegin(), X.rend());
				for (int i = 0; i < rm; i++)
					r0 += X[i];
				for (int i = 0; i <= rm; i++)
					r1 += X[i];
			}
			return make_pair(r0, r1 - r0);
		};
		auto ret = dfs(1, K);
		cout << ret.first << '\n';
	}
}