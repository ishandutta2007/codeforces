#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

using ld = long double;

void solve_test(istream &cin, ostream &cout)
{
	const array<int, 2> bnds = {1, int(1e9)};
	array<array<int, 2>, 2> vals;

	auto query = [&] (int x, int y)
	{
		cout << "? " << x << ' ' << y << endl;
		int ans;
		cin >> ans;
		return ans;
	};

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			vals[i][j] = query(bnds[i], bnds[j]);
			vals[i][j] += (i == 0);
			vals[i][j] += (j == 0);
		}

	const int x_mid = (int(1e9) + vals[0][0] - vals[1][0]) / 2;
	int low_y = query(x_mid, 1);
	low_y++;

	const int low_x = vals[0][0] - low_y;
	const int hig_x = int(1e9) - (vals[1][0] - low_y);
	const int hig_y = int(1e9) - (vals[1][1] - (int(1e9) - hig_x));
	assert(low_x <= hig_x && low_y <= hig_y);
	cout << "! " << low_x << ' ' << low_y << ' ' << hig_x << ' ' << hig_y << endl;
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

	solve();

//	ifstream fin("../input.txt");
//
//	do
//	{
//		solve(fin);
//
//		cout << "===" << endl;
//
//		string str;
//		while (getline(fin, str) && str != string(max(1, (int) str.size()), '='));
//	} while (fin);

	cout << setprecision(6) << "clock: " << double(clock() - st) / CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}