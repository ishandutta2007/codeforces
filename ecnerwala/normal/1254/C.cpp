#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	vector<pair<ll, int>> pts;
	for (int i = 3; i <= N; i++) {
		cout << 1 << ' ' << 1 << ' ' << 2 << ' ' << i << '\n';
		cout << 2 << ' ' << 1 << ' ' << 2 << ' ' << i << '\n';
		cout << flush;
		ll a, s; cin >> a >> s;
		pts.push_back({a * s, i});
	}
	sort(pts.begin(), pts.end());
	// inds sorted by distance
	auto sortPts = [&](vector<int> inds) -> vector<int> {
		if (inds.empty()) return {};
		deque<int> res;
		res.push_back(inds.back());
		for (int z = int(inds.size()) - 2; z >= 0; z--) {
			cout << 2 << ' ' << 1 << ' ' << inds.back() << ' ' << inds[z] << '\n' << flush;
			int s; cin >> s;
			if (s == 1) {
				res.push_back(inds[z]);
			} else if (s == -1) {
				res.push_front(inds[z]);
			} else assert(false);
		}
		return vector<int>(res.begin(), res.end());
	};
	vector<int> upper;
	vector<int> lower;
	for (auto it : pts) {
		if (it.first > 0) upper.push_back(it.second);
		else lower.push_back(it.second);
	}
	reverse(lower.begin(), lower.end());
	vector<int> res;
	res.push_back(1);
	for (auto it : sortPts(lower)) { res.push_back(it); }
	res.push_back(2);
	for (auto it : sortPts(upper)) { res.push_back(it); }
	cout << 0;
	for (int i = 0; i < N; i++) {
		cout << ' ' << res[i];
	}
	cout << '\n';

	return 0;
}