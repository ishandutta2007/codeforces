#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

int gettm(char c) {
	if (c == 'G') {
		return 5;
	} else if (c == 'W') {
		return 3;
	} else if (c == 'L') {
		return 1;
	} else {
		assert(false);
	}
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	cin.sync_with_stdio(0);

	int n = nxt();
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	string s;
	cin >> s;

	deque<pair<int, long long>> water_shit, ground_shit;
	bool was_water = false;
	long long ans = 0;

	for (int i = 0; i < n; ++i) {
		if (s[i] == 'G') {
			ground_shit.push_back({i, a[i]});
		} else if (s[i] == 'W') {
			was_water = true;
			water_shit.push_back({i, a[i]});
		} else {
			long long need = a[i];

			while (need && !water_shit.empty()) {
				long long tmp = min(need, water_shit.back().second);
				need -= tmp;
				water_shit.back().second -= tmp;
				ans += 4 * tmp;
				if (water_shit.back().second == 0) {
					water_shit.pop_back();
				}
			}

			while (need && !ground_shit.empty()) {
				long long tmp = min(need, ground_shit[0].second);
				need -= tmp;
				ground_shit[0].second -= tmp;
				ans += 6 * tmp;
				if (ground_shit[0].second == 0) {
					ground_shit.pop_front();
				}
			}

			if (was_water) {
				ans += 4 * need;
			} else {
				ans += 6 * need;
			}
		}
	}

	long long cur = 0;
	long long totally_used = 0;
	for (int i = 0, j = 0; i < (int)ground_shit.size(); ++i) {
		while (j < (int)water_shit.size() && water_shit[j].first < ground_shit[i].first) {
			cur += water_shit[j].second;
			++j;
		}
		long long tmp = min(cur, ground_shit[i].second);
		ground_shit[i].second -= tmp;
		cur -= tmp;
		totally_used += tmp;
		ans += 4 * tmp;
		ans += ground_shit[i].second * 3;
	}
	totally_used *= -1;
	for (auto p : water_shit) {
		totally_used += p.second;
	}

	ans += 2 * totally_used;

	cout << ans << "\n";

	return 0;
}