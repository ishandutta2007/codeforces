#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 111111;
vector<int> to[N];

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#if 1
	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}
#else
	int n = 100000;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = i + 1;
	}
	// random_shuffle(all(a));
#endif

	vector<pair<int, int>> pos;
	for (int i = 0; i < n; ++i) {
		pos.push_back({a[i], i});
	}
	sort(all(pos));
	reverse(all(pos));

	vector<char> win(n);

	for (const auto& [v, idx] : pos) {
		win[idx] = 0;
		for (int x = idx % v; x < n; x += v) {
			if (a[x] > v) {
				win[idx] |= !win[x];
			}
		}
	}

	string ans(n, 0);
	for (int i = 0; i < n; ++i) {
		ans[i] = 'B' - win[i];
	}
	printf("%s\n", ans.c_str());

	return 0;
}