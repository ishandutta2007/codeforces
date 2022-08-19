#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int H; cin >> H;
	const int N = (1 << H) - 1;

	auto query = [&](array<int, 3> a) -> int {
		if (a[0] == a[1]) return a[0];
		if (a[1] == a[2]) return a[1];
		if (a[0] == a[2]) return a[0];

		cout << '?' << ' ' << a[0]+1 << ' ' << a[1]+1 << ' ' << a[2]+1 << '\n' << flush;
		int res; cin >> res;
		if (res == -1) exit(0);
		return res-1;
	};
	auto finish = [&](int ans) {
		cout << '!' << ' ' << ans+1 << '\n' << flush;
		exit(0);
	};

	mt19937 mt(48);
	map<int, int> mp;
	for (int i = 0; i < 420; i++) {
		int a = (mt() % N);
		int b = (mt() % N);
		int c = (mt() % N);
		if (a == b || b == c || c == a) {
			i--;
			continue;
		}
		int v = query({a,b,c});
		if (v == a || v == b || v == c) continue;
		cerr << "good " << v << '\n';
		mp[v]++;
	}
	vector<pair<int, int>> freq; freq.reserve(mp.size());
	for (auto it : mp) {
		freq.push_back({it.second, it.first});
	}
	sort(freq.begin(), freq.end());
	reverse(freq.begin(), freq.end());

	if (freq.size() < 2) {
		assert(false);
	}

	int x = freq[0].second;
	int y = freq[1].second;
	cerr << x << ' ' << y << '\n';

	set<int> on_path;
	set<int> is_resp;
	for (int i = 0; i < N; i++) {
		if (i == x || i == y) continue;
		int v = query({x,y,i});
		if (v == x) {
			on_path.insert(x);
			x = i;
		} else if (v == y) {
			on_path.insert(y);
			y = i;
		} else if (v == i) {
			on_path.insert(i);
		} else {
			is_resp.insert(v);
		}
	}

	for (int v : on_path) {
		if (is_resp.count(v)) continue;
		finish(v);
	}

	return 0;
}