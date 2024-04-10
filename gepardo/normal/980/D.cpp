#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	int n; cin >> n;
	vector<int> v(n);
	map<int, int> kompr;
	int knt = 0;
	for (int i = 0; i < n; i++) {
		int q; cin >> q;
		for (int j = 2; j*j <= abs(q); j++) {
			while (q % (j*j) == 0) {
				q /= j*j;
			}
		}
		if (!kompr.count(q)) {
			kompr[q] = knt++;
		}
		v[i] = kompr[q];
	}
	if (!kompr.count(0)) {
		kompr[0] = knt++;
	}
	int k0 = kompr[0];
	int ks = kompr.size();
	vector<int> ans(n);
	vector<int> group(ks);
	for (int i = 0; i < n; i++) {
		int gKnt = 1;
		group.assign(ks, 0);
		group[k0]++;
		for (int j = i; j < n; j++) {
			gKnt += !group[v[j]];
			group[v[j]]++;
			ans[max(0, gKnt - 2)]++;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}