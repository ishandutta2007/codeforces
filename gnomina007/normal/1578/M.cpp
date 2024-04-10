#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

using ld = long double;

int C (int from, int what)
{
	if (what < 0 || what > from)
		return 0;
	int ans = 1;
	for (int i = 1; i <= what; i++)
	{
		ans *= from - i + 1;
		ans /= i;
	}
	return ans;
}

void solve_test(istream &cin, ostream &cout)
{
	int n;
	double p;
	cin >> n >> p;

	const ll pden = int(1e5), pnum = llround(p * 1e5);

	const int full = 2 * C(n, 3);
	for (int k = 0; k <= n; k++)
	{
		int cur = 0;
		for (int good = 0; good <= 3; good++)
		{
			const int ways = C(k, good) * C(n - k, 3 - good);
			const int part = (good >= 2 ? 2 : (good == 1 ? 1 : 0));
			cur += ways * part;
		}

		if (ll(cur) * pden >= ll(full) * pnum)
		{
			cout << k << endl;
			return;
		}
	}

	assert(false);
}

void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	solve_test(cin, cout);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	do
	{
		solve(fin);

		cout << "===" << endl;

		string str;
		while (getline(fin, str) && str != string(max(1, (int) str.size()), '='));
	} while (fin);

	cout << setprecision(6) << "clock: " << double(clock() - st) / CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}