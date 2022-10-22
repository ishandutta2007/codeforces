#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
typedef long long ll;
typedef long double ld;
using namespace std;

vector<int> pf;
int sum(int l, int r)
{
	r = min(r, (int)pf.size() - 1);
	return pf[r] - pf[l - 1];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, c;
		cin >> n >> c;
		int k = c + 5;
		pf.assign(k, 0);
		vector<int> f(k);
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			f[a]++;
			pf[a]++;
		}
		for (int i = 1; i < k; i++)
		{
			pf[i] += pf[i - 1];
		}
		vector<int> d(k, 0); // quotients we have
		for (int y = 1; y < k; y++) if (f[y])
		{
			for (int i = 1; i * y < k; i++)
			{
				if (sum(i * y, (i + 1) * y - 1)) d[i] = 1;
			}
		}
		bool ok = true;
		for (int i = 0; i < k; i++) if (d[i] && !f[i])
		{
			ok = false;
		}
		cout << (ok ? "Yes\n" : "No\n");
	}
	return 0;
}