#include <bits/stdc++.h>

using namespace std;

struct Uzklausa {
	int l, r, i;
};

/*input
3 2
1 2 1
1 2
1 3
*/

long long kiekiai[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;

	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<Uzklausa> u(q);

	for (int i = 0; i < q; i++) {
		cin >> u[i].l >> u[i].r;
		u[i].l--;
		u[i].i = i;
	}

	const int sqrtn = 1024;
	sort(u.begin(), u.end(), [&](Uzklausa & i, Uzklausa & j) {
		if (i.l / sqrtn == j.l / sqrtn)
			return i.r < j.r;

		return i.l / sqrtn < j.l / sqrtn;
	});
	int pr = 0, pab = 0;
	long long dabar = 0;
	long long ats[q];

	auto keisti = [&](long long x, bool prideti) {
		dabar -= kiekiai[x] * kiekiai[x] * x;

		if (prideti)
			kiekiai[x]++;
		else
			kiekiai[x]--;

		dabar += kiekiai[x] * kiekiai[x] * x;
	};

	for (Uzklausa t : u) {
		while (pab < t.r) {
			keisti(a[pab], 1);
			pab++;
		}

		while (pr > t.l) {
			pr--;
			keisti(a[pr], 1);
		}

		while (pr < t.l) {
			keisti(a[pr], 0);
			pr++;
		}

		while (pab > t.r) {
			pab--;
			keisti(a[pab], 0);
		}

		ats[t.i] = dabar;
	}

	for (int i = 0; i < q; i++) {
		cout << ats[i] << "\n";
	}
}