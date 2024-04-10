/*input
4
1 2
1 3
1 4
*/
#include <bits/stdc++.h>

using namespace std;
const int maxn = 100000;
vector<int> gra[maxn];
int dyd[maxn];
bool apl[maxn];
bool apl2[maxn];
char ind[maxn] = {};

void pildykdyd(int v) {
	apl[v] = true;
	dyd[v] = 1;

	for (auto && i : gra[v]) {
		if (!apl[i] and ind[i] == 0) {
			pildykdyd(i);
			dyd[v] += dyd[i];
		}
	}
}

int centroid(int v, const int &n) {
	apl2[v] = true;
	bool ar = true;
	int did = -1;

	for (auto && i : gra[v]) {
		if (!apl2[i] and ind[i] == 0) {
			if (dyd[i] > n / 2)
				ar = false;

			if (did == -1 or dyd[did] < dyd[i])
				did = i;
		}
	}

	if (ar and n - dyd[v] <= n / 2)
		return v;

	return centroid(did, n);
}

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;

	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		gra[u].push_back(v);
		gra[v].push_back(u);
	}

	int tempn = n;
	char dabar = 'A';

	while (tempn > 0) {
		fill_n(apl,n,false);
		fill_n(apl2,n,false);

		for (int k = 0; k < n; k++) {
			if (!apl[k] and ind[k] == 0) {
				pildykdyd(k);

				int centroi = centroid(k, dyd[k]);
				ind[centroi] = dabar;
				tempn--;
			}
		}

		dabar++;
	}

	for (int i = 0; i < n; i++)
		cout << ind[i] << " ";


	return 0;
}