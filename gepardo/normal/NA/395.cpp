#include <iostream>
#include <vector>

using namespace std;

const int mod = (int)1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	int n, q; cin >> n >> q;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector< vector< pair<int, int> > > queries(n);
	for (int i = 0; i < q; i++) {
		int a, b; cin >> a >> b; a--;
		queries[a].emplace_back(b, i);
	}
	vector<int> ans(q);
	vector<int64_t> tab(1 << 20);
	tab[0] = 1;
	int64_t mul = 1;
	for (int i = 0; i < n; i++) {
		int q = v[i];
		if (tab[q]) {
			mul += mul;
			mul %= mod;
		} else {
			for (int j = 0; j < (1 << 20); j++) {
				tab[j] *= mul;
				tab[j] %= mod;
			}
			for (int j = 0; j < (1 << 20); j++) {
				int k = q ^ j;
				if (j <= k) {
					int64_t soom = (tab[j] + tab[k]) % mod;
					tab[j] = tab[k] = soom;
				}
			}
			mul = 1;
		}
		for (auto it: queries[i]) {
			ans[it.second] = (tab[it.first] * mul) % mod;
		}
	}
	for (int i = 0; i < q; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}