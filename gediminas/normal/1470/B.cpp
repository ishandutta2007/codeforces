#include <bits/stdc++.h>

using namespace std;
/*input
2
4
6 8 4 2
1
0
6
12 3 20 5 80 1
1
1
*/
bool is_sq(long long x) {
	long long sq = sqrtl(x);

	while (sq * sq < x) {
		sq++;
	}

	if (sq * sq == x) {
		return true;
	}

	while (sq * sq > x) {
		sq--;
	}

	return sq * sq == x;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	vector<int> primes;

	for (int i = 2; i <= 1000; ++i) {
		bool blog = false;

		for (int j = 2; j < i; ++j) {
			if (i % j == 0) {
				blog = true;
				break;
			}
		}

		if (!blog) {
			primes.push_back(i);
		}
	}

	while (t--) {
		int n;
		cin >> n;
		vector<long long> a(n);
		map<long long, long long> te;
		vector<int> ans(3, 0);

		for (auto &&i : a) {
			cin >> i;

			for (int j : primes) {
				while (i % (j * j) == 0) {
					i /= j * j;
				}
			}

			te[i]++;
		}

		vector<long long> eil;

		for (auto &&i : te) {
			if (i.first > 1 and i.second % 2 == 0) {
				eil.push_back(i.first);
			}

			ans[0] = max(ans[0], (int)i.second);
		}


		for (auto &&j : eil) {
			te[1] += te[j];
			te.erase(j);
		}

		for (auto &&i : te) {
			ans[1] = max(ans[1], (int)i.second);
		}

		int q;
		cin >> q;

		for (int i = 0; i < q; ++i) {
			long long w;
			cin >> w;

			if (w == 0) {
				cout << ans[0] << "\n";
			}
			else {
				cout << ans[1] << "\n";
			}
		}
	}
}