#include "bits/stdc++.h"
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
const int N = 2e5 + 10;
vector<int> e[N];
int f[N], l[N], r[N], ac[N], ans;
void dfs(int u)
{
	ll cur = 0;
	for (int v : e[u])
	{
		dfs(v);
		cur += ac[v];
	}
	ac[u] = min(cur, (ll)r[u]);
	if (ac[u] < l[u])
		++ans, ac[u] = r[u];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int testcase;
	for (cin >> testcase; testcase--;)
	{
		int n, i;
		ans = 0;
		cin >> n;
		for (i = 1; i <= n; i++)
		{
			e[i].clear();
			f[i] = 0;
		}
		for (i = 2; i <= n; i++)
			cin >> f[i], e[f[i]].push_back(i);
		for (i = 1; i <= n; i++)
			cin >> l[i] >> r[i];
		dfs(1);
		cout << ans << '\n';
	}
}