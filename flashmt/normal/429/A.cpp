#include <bits/stdc++.h>
using namespace std;

int n, init[100100], goal[100100];
vector <int> a[100100], ans;

void dfs(int x, int par, int depth, int oddXor, int evenXor)
{
	if (depth) init[x] ^= oddXor;
	else init[x] ^= evenXor;
	
	int res = init[x] ^ goal[x];
	if (depth) oddXor ^= res;
	else evenXor ^= res;
	if (res) ans.push_back(x);
	
	for (int i = 0; i < int(a[x].size()); i++)
	{
		int y = a[x][i];
		if (y != par) dfs(y, x, depth ^ 1, oddXor, evenXor);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	int x, y;
	
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	
	for (int i = 1; i <= n; i++) cin >> init[i];
	for (int i = 1; i <= n; i++) cin >> goal[i];
	
	dfs(1, 0, 0, 0, 0);
	cout << ans.size() << endl;
	for (int i = 0; i < int(ans.size()); i++) cout << ans[i] << '\n';
}