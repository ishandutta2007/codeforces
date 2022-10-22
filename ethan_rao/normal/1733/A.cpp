#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int testcase;
	for (cin >> testcase; testcase--;)
	{
		int n, k;
		cin >> n >> k;
		vector a(k, vector(0, 0));
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			a[i % k].push_back(x);
		}
		ll res = 0;
		for (auto &v : a)
		{
			res += *max_element(all(v));
		}
		cout << res << '\n';
	}
}