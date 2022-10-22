#include "bits/stdc++.h"
using namespace std;
#define int ll
using ll = long long;
#define all(x) (x).begin(), (x).end()
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int testcase;
	for (cin >> testcase; testcase--;)
	{
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for (int &x : a)
		{
			cin >> x;
		}
		sort(all(a), greater<int>());
		for (int &x : b)
		{
			cin >> x;
		}
		sort(all(b), greater<int>());
		vector<int> ans(2 * n);
		for (int i = 0; i < n; i++)
		{
			ans[i] = a[0] + b[i];
			ans[i + n] = abs(a[0] - b[i]);
		}
		bool flg = 1;
		for (int p : ans)
		{
			multiset<int> s(all(b));
			vector<int> h(n);
			for (int i = 0; i < n; i++)
			{
				for (int x : {-a[i], a[i]})
				{
					if (auto it = s.find(abs(x - p)); it != s.end())
					{
						s.erase(it);
						h[i] = x;
						break;
					}
				}
				if (i + s.size() != n - 1)
				{
					break;
				}
			}
			if (s.size() == 0)
			{
				int mn = 0;
				for (int x : h)
				{
					mn = min(mn, x);
				}
				cout << "YES\n";
				for (int i = 0; i < n; i++)
				{
					cout << h[i] - mn << " \n"[i == n - 1];
				}
				cout << -mn << ' ' << p - mn << '\n';
				flg = 0;
				break;
			}
		}
		if (flg)
		{
			cout << "NO\n";
		}
	}
}