#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;

vector <int> dsu, secdsu;

int get(int v, vector <int> &cnt) {
	if (v == 0) return 0;
	if (cnt[secdsu[v]]) return secdsu[v];
	return secdsu[v] = get(secdsu[v], cnt);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector <int> cnt(k + 1);
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		cnt[val]++;
	}
	vector <int> c(k + 1);
	for (int i = 1; i <= k; i++) 
		cin >> c[i];
	dsu.resize(k + 1), secdsu.resize(k + 1);
	for (int i = 1; i <= k; i++) {
		if (c[i] != c[i - 1]) dsu[i] = i - 1;
		else dsu[i] = dsu[i - 1];
		secdsu[i] = i - 1;
	}
	
	vector <vector <int>> ans;
	while (n > 0) {
		ans.push_back({});
		int itans = ans.size() - 1;
		while (!cnt[k]) k--;
		int it = k;
		int used = 0;
		for (; it != 0;) {
			while (used < c[it] && cnt[it] > 0) {
				n--;
				cnt[it]--;
				ans[itans].push_back(it);
				used++;
			}
			if (used == c[it]) {
				it = dsu[it];
				continue;
			}
			get(it, cnt);
			it = secdsu[it];
		}
	}
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].size() << ' ';
		for (int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}