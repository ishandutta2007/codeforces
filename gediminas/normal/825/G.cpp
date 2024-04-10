/*input
4 6
1 2
2 3
3 4
1 2
1 2
2 2
1 3
2 2
2 2
*/
#include <bits/stdc++.h>

using namespace std;

void medis(int v, vector<vector<int>> &gra, vector<int> &par, vector<int> &maz) {
	maz[v] = min(v, maz[par[v]]);

	for (auto && i : gra[v]) {
		if (par[i] == -1) {
			par[i] = v;
			medis(i, gra, par, maz);
		}
	}
}

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	int root;
	vector<vector<int>> gra(n);

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		gra[u].push_back(v);
		gra[v].push_back(u);
	}

	cin >> root >> root;
	root = root % n;
	q--;

	vector<int> par(n, -1);
	vector<int> maz(n);
	par[root] = root;
	maz[root] = root;
	medis(root, gra, par, maz);

	int last = 0;
	vector<bool> juodi(n, false);
	juodi[root] = true;

	int globalMin = root;

	for (int i = 0; i < q; i++) {
		int t, x;
		cin >> t >> x;
		x = (x + last) % n;
		//cout << "Q" << t << " " << x << endl;

		if (t == 1) {
			int d = x;

			while (!juodi[d]) {
				globalMin = min(globalMin, d);
				juodi[d] = true;
				d = par[d];
			}
		}
		else {
			int ats = min(maz[x], globalMin) + 1;
			last = ats;
			cout << ats << "\n";
		}
	}


	return 0;
}