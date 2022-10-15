#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 100013
int N, Q;
bitset<7001> divisors[7001];
bitset<7001> pie[7001];
bitset<7001> sets[MAXN];
vector<int> sqf;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> Q;

	for (int d = 1; d <= 7000; d++) {
		for (int n = d; n <= 7000; n += d)
			divisors[n].set(d);
	}

	for (int x = 1; x <= 7000; x++) {
		bool ok = true;
		for (int d = 2; d * d <= x; d++)
			if (x % (d * d) == 0)
				ok = false;
		if (ok)
			sqf.push_back(x);
	}

	for (int v = 1; v <= 7000; v++) {
		for (int d : sqf) {
			if (v * d > 7000)
				break;
			pie[v].set(v * d);
		}
	}

	while (Q--) {
		int q, x;
		cin >> q >> x; --x;
		if (q == 1) {
			int v; cin >> v;
			sets[x] = divisors[v];
		}
		else if (q == 2) {
			int y, z;
			cin >> y >> z;
			--y, --z;
			sets[x] = sets[y] ^ sets[z];
		}
		else if (q == 3) {
			int y, z;
			cin >> y >> z;
			--y, --z;
			sets[x] = sets[y] & sets[z];
		}
		else {
			int v; cin >> v;
			bool ans = (sets[x] & pie[v]).count() % 2;
			cout << ans;
		}
	}

	cout << endl;
	return 0;
}