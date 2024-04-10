#include <bits/stdc++.h>


using namespace std;


using ll = long long;
mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, k, m, t;

	cin >> n >> k >> m >> t;
	k--;

	for (int i = 0; i < t; i++)
	{
		int q, x;

		cin >> q >> x;

		if (q == 1)
		{
			x--;
			if (x <= k)
				k++;
			n++;
		}
		else
		{
			if (x <= k)
			{
				k -= x;
				n -= x;
			}
			else
				n = x;
		}

		cout << n << ' ' << k + 1 << endl;
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	ifstream fin("../input.txt");

	solve(fin);

	cout << setprecision(4);
	cout << "clock: " << clock() / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}