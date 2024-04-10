#include <bits/stdc++.h>

using namespace std;

using ll = long long;

/*input
15 39
*/
int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	auto score = [&](const vector<int> &a) -> int {
		int r = 0;
		int n = a.size();

		for (int i = 0; i < n; i++) {
			int t = i + 1;

			for (int j = i + 1; j < n; j++) {
				while (t < n and a[i] + a[j] > a[t]) {
					t++;
				}

				if (t < n and a[i] + a[j] == a[t]) {
					r++;
				}
			}
		}

		return r;
	};

	int n, m;
	cin >> n >> m;

	ll mi = 1, ma = n;

	while (mi <= ma) {
		vector<int> a(n);
		int mid = (mi + ma + 1) / 2;

		for (int i = 0; i < n; i++) {
			a[i] = mid + i;
		}

		int sc = score(a);

		if (sc == m) {
			for (auto && i : a) {
				cout << i << " ";
			}

			exit(0);
		}
		else if (mi == ma) {
			break;
		}

		if (sc < m) {
			ma = mid -1;
		}
		else {
			mi = mid;
		}
	}

	ll fr = mi;

	{
		ll mi = 0, ma = n - 1;

		while (mi <= ma) {
			vector<int> a(n);
			int mid = (mi + ma) / 2;

			for (int i = 0; i < n; i++) {
				a[i] = fr + i;

				if (i > mid) {
					a[i]++;
				}
			}

			int sc = score(a);

			if (sc == m) {
				for (auto && i : a) {
					cout << i << " ";
				}

				exit(0);
			}
			else if (mi == ma) {
				break;
			}

			if (sc < m) {
				mi = mid + 1;
			}
			else {
				ma = mid;
			}
		}
	}

	cout << -1;
}