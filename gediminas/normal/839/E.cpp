/*input

4 4
0 1 0 1
1 0 1 0
0 1 0 1
1 0 1 0
*/
#include <bits/stdc++.h>
using namespace std;

bool graph[40][40];
vector<int> neigh;
long long gra[40];
int n;
int ma;
bool found;
int did[40] = {};

void clique(long long u, int siz) {
	if (u == 0) {
		if (siz > ma) {
			ma = siz;
			found = true;
		}

		return;
	}

	int dydu = __builtin_popcountll(u);

	for (int i = 0; i < n; i++) {
		if (u & (1ll << i)) {

			if (siz + dydu <= ma)
				return;

			u ^= (1ll << i);
			dydu--;

			if (siz + did[i] <= ma)
				return;

			clique(u & gra[i], siz + 1);

			if (found)
				return;
		}
	}
}

int main() {
	long double k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];

			gra[i] |= ((long long)graph[i][j] << j);
		}
	}

	long long pr = 0;

	ma = 0;

	for (int siz = n - 1; siz >= 0; siz--) {
		pr |= (1ll << (siz));
		found = false;
		clique(pr & gra[siz], 1);
		did[siz] = ma;
	}

	if (ma > 0)
		cout << fixed << setprecision(7) << k *k*(ma - 1) / 2 / ma;
	else
		cout << 0;

	return 0;
}