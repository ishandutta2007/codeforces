#include <bits/stdc++.h>

using namespace std;

using ll = long long;

/*input
3
6 2 4
*/
/*input
5
9 8 7 3 1
*/
/*input
100000
100000000000
*/
int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<ll> a(n);

	for (auto && i : a) {
		cin >> i;
	}

	ll ats = n;

	vector<ll> r(2 * n + 1, 0);
	vector<bool> rr(1000000, true);
	rr[0] = rr[1] = false;
	vector<ll> primes;

	for (int i = 2; i < 1000000; i++) {
		if (rr[i]) {
			int j = i;
			primes.push_back(i);

			while (j < 1000000) {
				rr[j] = false;
				j += i;
			}
		}
	}

	ll mi = max(a[0] - n, 1ll);
	ll ma = a[0] + n;

	for (int i = 0; i <= ma - mi; i++) {
		r[i] = mi + i;
	}

	vector<ll> xx;

	for (auto && k : primes) {
		ll t = mi / k * k;
		bool ra = false;

		while (t <= ma) {
			if (t >= mi) {
				while (r[t - mi] % k == 0) {
					r[t - mi] /= k;
				}

				ra = true;
			}

			t += k;
		}

		if (ra) {
			xx.push_back(k);
		}
	}

	for (int i = 0; i < ma - mi; i++) {
		if (r[i] > 1) {
			xx.push_back(r[i]);
		}
	}

	random_shuffle(a.begin(), a.end());

	for (auto && k : xx) {
		ll c = 0;

		for (int i = 0; i < n and c < ats; i++) {
			if (a[i] <= k) {
				c += k - a[i];
			}
			else {
				ll w = min(a[i] - a[i] / k * k, (a[i] / k + 1) * k - a[i]);
				c += w;
			}
		}

		ats = min(ats, c);
	}

	cout << ats << endl;

}