#include "bits/stdc++.h"
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
const int N = 1e6 + 10;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int testcase;
	for (cin >> testcase; testcase--;)
	{
		int n, i, j, k, l;
		cin >> n;
		vector<int> a(n), b(n);
		vector<pair<int, int>> ans;
		for (int &x : a)
			cin >> x;
		for (int &x : b)
			cin >> x;
		for (i = 0; i < n; i++)
			for (j = i + 1; j < n; j++)
				if (a[i] > a[j])
				{
					swap(a[i], a[j]);
					swap(b[i], b[j]);
					ans.push_back({i, j});
				}
		for (i = j = 0; i < n; i = j)
		{
			while (j < n && a[i] == a[j])
				++j;
			for (k = i; k < j; k++)
				for (l = k + 1; l < j; l++)
					if (b[k] > b[l])
					{
						swap(b[k], b[l]);
						ans.push_back({k, l});
					}
		}
		if (!is_sorted(all(b)))
		{
			cout << "-1\n";
			continue;
		}
		cout << ans.size() << '\n';
		for (auto [x, y] : ans)
			cout << x + 1 << ' ' << y + 1 << '\n';
	}
}