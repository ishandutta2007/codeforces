#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> row(n);
	for (int i = 0; i < n; ++i) {
		int w;
		cin >> w;
		row[i] = {w, i};
	}
	sort(all(row));
	int intro = 0;
	vector<int> can;
	for (int i = 0; i < 2 * n; ++i) {
		char c;
		cin >> c;
		if (c == '0') {
			cout << row[intro].second + 1 << " ";
			can.push_back(intro);
			++intro;
		} else {
			cout << row[can.back()].second + 1 << " ";
			can.pop_back();
		}
	}
	return 0;	
}