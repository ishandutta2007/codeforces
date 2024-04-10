#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 505;
int a[N][N];

void add(int* times, int* freq, int timer, int& cnt, int i, int x) {
	if (times[i] != timer) {
		times[i] = timer;
		freq[i] = 0;
	}
	if (freq[i]) {
		--cnt;
	}
	freq[i] += x;
	if (freq[i]) {
		++cnt;
	}
}

int get(int* times, int* freq, int timer, int i) {
	return times[i] == timer ? freq[i] : 0;
}

void remin(int& x, int y) {
	x = (x < y) ? x : y;
}

void remax(int& x, int y) {
	x = (x > y) ? x : y;
}

const int inf = 1e9;
int minx[N * N], miny[N * N], maxx[N * N], maxy[N * N];

int used_val[N * N];
int cnt_unique = 0;
int tmp[N * N];

int flag[N * N];
int flag_time[N * N];

void solve() {
	fill(minx, minx + N * N, inf);
	fill(maxx, maxx + N * N, -inf);
	fill(miny, miny + N * N, inf);
	fill(maxy, maxy + N * N, -inf);

	int n = nxt(), k = nxt();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			a[i][j] = nxt();
			add(tmp, used_val, 0, cnt_unique, a[i][j], 1);
			remin(minx[a[i][j]], i);
			remin(miny[a[i][j]], j);
			remax(maxx[a[i][j]], i);
			remax(maxy[a[i][j]], j);
		}
	}
	if (cnt_unique <= k) {
		cout << k - cnt_unique << "\n";
		return;
	}
	if (k == 1) {
		cout << "1\n";
		return;
	}
	int need = cnt_unique - k;
	// can make need or need + 1

	vector<int> present;
	for (int i = 0; i < N * N; ++i) {
		if (used_val[i]) {
			present.push_back(i);
		}
	}

	int timer = 0;
	for (int sum = 0; sum <= 2 * (n - 1); ++sum) {
		++timer;
		[[maybe_unused]] int cnt_un = 0;
		int total = 0;
		for (int i : present) {
			// x + y == sum, mx >= x, My <= y, x -> max => x = min(mx, sum - My)
			int l = min(minx[i], sum - maxy[i]), r = max(maxx[i], sum - miny[i]);
			if (l < max(0, sum - (n - 1)) || r > min(sum, n - 1)) {
				continue;
			}
			add(flag_time, flag, timer, cnt_un, l * N + r, 1);
			++total;
			if (sum == 1) {
				cerr << i << ": " << l << " " << r << "\n";
			}
		}
		if (total < need) {
			continue;
		}
		int l = max(0, sum - (n - 1));
		int r = l;
		int cur = get(flag_time, flag, timer, l * N + r);
		int till = min(sum, n - 1);
		while (true) {
			if (cur < need) {
				++r;
				if (r > till) {
					break;
				}
				for (int i = l; i <= r; ++i) {
					cur += get(flag_time, flag, timer, i * N + r);
				}
			} else if (cur > need + 1) {
				for (int i = l; i <= r; ++i) {
					cur -= get(flag_time, flag, timer, l * N + i);
				}
				++l;
			} else {
				// cerr << sum << " " << l << " " << r << "\n";
				cout << "1\n";
				return;
			}
		}
	}
	cout << "2\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}