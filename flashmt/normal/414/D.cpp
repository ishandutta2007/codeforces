#include <bits/stdc++.h>
using namespace std;

int n, k, p, depth[100100];
long long sumDepth[100100];
vector <int> a[100100];

void visit(int x, int par)
{
	for (int i = 0; i < int(a[x].size()); i++)
	{
		int y = a[x][i];
		if (y == par) continue;
		depth[y] = depth[x] + 1;
		visit(y, x);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	
	int x, y;
	cin >> n >> k >> p;
	for (int i = 1; i < n; i++)
	{
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	
	visit(1, 0);
	sort(depth + 2, depth + n + 1, greater<int>());
	for (int i = 2; i <= n; i++) sumDepth[i] = sumDepth[i - 1] + depth[i];
	
	int ans = 1;
	for (int i = 2; i <= n; i++)
	{
		int low = i + 1, high = n, res = i;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (1LL * depth[i] * (mid - i + 1) - (sumDepth[mid] - sumDepth[i - 1]) <= p)
			{
				low = mid + 1;
				res = mid;
			}
			else high = mid - 1;
		}
		ans = max(ans, min(k, res - i + 1));
	}
	
	cout << ans << endl;
}