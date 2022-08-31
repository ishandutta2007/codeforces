#include <bits/stdc++.h>

using namespace std;

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

int main() {
	cin.sync_with_stdio(0);
	int n = nxt();
	vector<pair<int, char>> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first >> a[i].second;
	}

	int num_g = 0;
	int min_r = 1e9 + 10, max_r = 0;
	int min_b = 1e9 + 10, max_b = 0;
	for (auto p : a) {
		if (p.second == 'G') {
			++num_g;
		} else if (p.second == 'R') {
			min_r = min(min_r, p.first);
			max_r = max(max_r, p.first);
		} else if (p.second == 'B') {
			min_b = min(min_b, p.first);
			max_b = max(max_b, p.first);
		}
	}

	if (num_g == 0) {
		cout << max(0, max_r - min_r) + max(0, max_b - min_b) << "\n";
		return 0;
	}

	int ans = 0;
	int left = -1, right = -1;
	vector<int> red, blue;
	for (itn i = 0; i < n; ++i) {
		if (a[i].second == 'R') {
			red.push_back(a[i].first);
		} else if (a[i].second == 'B') {
			blue.push_back(a[i].first);
		} else {
			left = right;
			right = a[i].first;

			if (left == -1) {
				if (!red.empty()) {
					ans += right - red[0];
				}
				if (!blue.empty()) {
					ans += right - blue[0];
				}
			} else {
				int opt1 = 2 * (right - left);
				int opt2 = 0;

				red.insert(red.begin(), left);
				red.push_back(right);
				blue.insert(blue.begin(), left);
				blue.push_back(right);

				int mx = 0;
				for (int i = 0; i < (int)red.size() - 1; ++i) {
					mx = max(mx, red[i + 1] - red[i]);
				}
				opt2 -= mx;
				mx = 0;
				for (int i = 0; i < (int)blue.size() - 1; ++i) {
					mx = max(mx, blue[i + 1] - blue[i]);
				}
				opt2 -= mx;
				opt2 += 3 * (right - left);

				ans += min(opt1, opt2);
			}

			red.clear();
			blue.clear();
		}
	}
	if (!red.empty()) {
		ans += red.back() - right;
	}
	if (!blue.empty()) {
		ans += blue.back() - right;
	}

	printf("%d\n", ans);

	return 0;
}