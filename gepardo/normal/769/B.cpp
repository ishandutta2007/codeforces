#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	vector<int> v(n);
	vector<char> used(n, false);
	vector<int> cur;
	vector< pair<int, int> > ans;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cnt++;
	used[0] = true;
	cur.push_back(0);
	while (!cur.empty()) {
		vector<int> nxt;
		for (int q: cur) {
			vector< pair<int, int> > sV;
			for (int i = 0; i < n; i++) {
				if (!used[i]) {
					sV.emplace_back(v[i], i);
				}
			}
			sort(sV.begin(), sV.end());
			reverse(sV.begin(), sV.end());
			for (int i = 0; i < min((int)sV.size(), v[q]); i++) {
				int id = sV[i].second;
				nxt.push_back(id);
				used[id] = true;
				cnt++;
				ans.emplace_back(q, id);
			}
		}
		cur = nxt;
	}
	if (cnt != n) {
		cout << "-1\n";
	} else {
		cout << ans.size() << "\n";
		for (int i = 0; i < (int)ans.size(); i++) {
			cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
		}
	}
	return 0;
}