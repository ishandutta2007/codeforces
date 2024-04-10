#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
const ll inf = 100'000'000'000;
const int N = 110;
int a[N];
pair<ll, int> b[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<ll> fib = {1, 1};
	vector<ll> sum = {1, 2};
	while (sum.back() <= inf)
	{
		int m = fib.size();
		fib.push_back(fib[m - 2] + fib[m - 1]);
		sum.push_back(sum.back() + fib.back());
	}
	// cerr << fib.size() << endl;
	int testcase;
	for (cin >> testcase; testcase--;)
	{
		ll tot = 0;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			tot += a[i];
			b[i] = {a[i], i};
		}
		int m = lower_bound(all(sum), tot) - sum.begin();
		if (sum[m] != tot)
		{
			cout << "NO\n";
		}
		else
		{
			set<pair<ll, int>> s(b + 1, b + n + 1);
			bool flg = 0;
			int lst = -1;
			for (int i = m; i >= 0; i--)
			{
				assert(s.size());
				set<pair<ll, int>>::iterator it;
				ll y = fib[i];
				it = prev(s.end());
				if ((it != s.begin()) && (it->second == lst))
				{
					--it;
				}
				if ((it->first < y) || (it->second == lst))
				{
					flg = 1;
					break;
				}
				lst = it->second;
				ll x = it->first;
				s.erase(it);
				if (x > y)
				{
					s.insert({x - y, lst});
				}
			}
			if (flg)
			{
				cout << "NO\n";
			}
			else
			{
				cout << "YES\n";
			}
		}
	}
}