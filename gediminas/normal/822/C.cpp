/*input
4 5
1 3 4
1 2 5
5 6 1
1 2 4
*/
#include <bits/stdc++.h>

using namespace std;

struct kelione {
	bool apv = false;
	int l, r;
	long long cost;
};

int main () {
	int n, x;
	cin >> n >> x;
	long long kaina[200005];
	fill(kaina, kaina + 200005, 3000000000ll);
	vector<kelione> kel;

	for (int i = 0; i < n; i++) {
		kelione c;
		cin >> c.l >> c.r >> c.cost;
		kel.push_back(c);
		c.apv = true;
		swap(c.l, c.r);
		kel.push_back(c);
	}

	sort(kel.begin(), kel.end(), [](const auto & i, const auto & j) -> bool {
		if (i.l == j.l)
			return i.apv < j.apv;
		return i.l < j.l;
	});

	long long ans = 3000000000ll;

	for (kelione c : kel) {
		if (!c.apv) {
			//cout << c.l << " " << c.r << " " << c.cost + kaina[x - (c.r - c.l + 1)] << endl;
			if (x - (c.r - c.l + 1) > 0)
				ans = min(ans, c.cost + kaina[x - (c.r - c.l + 1)]);
		}
		else {
			//cout << c.l << " " << c.r << endl;
			kaina[c.l - c.r + 1] = min(kaina[c.l - c.r + 1], c.cost);
		}
	}

	cout << (ans>=3000000000ll?-1:ans);

	return 0;
}