#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 4222222;
int cnt[N];

void erase(int x) {
	cnt[x + N / 2] -= 1;
}

void insert(int x) {
	cnt[x + N / 2] += 1;
}

int mx = N - 1;

int getmax() {
	while (!cnt[mx]) {
		--mx;
	}
	return mx - N / 2;
}

void solve() {
	int n = nxt(), m = nxt();
	vector<pair<int, int>> a(n), b(m);
	for (int i = 0; i < n; ++i) {
		a[i].first = nxt(), a[i].second = nxt();
	}
	for (int i = 0; i < m; ++i) {
		b[i].first = nxt(), b[i].second = nxt();
	}

	sort(all(b));
	for (int i = m - 2; i >= 0; --i) {
		b[i].second = max(b[i].second, b[i + 1].second);
	}
	{
		vector<pair<int, int>> tmp;
		for (auto p : b) {
			if (tmp.empty() || tmp.back().second > p.second) {
				tmp.push_back(p);
			} else {
				tmp.back() = p;
			}
		}
		b.swap(tmp);
	}
	m = b.size();

	sort(all(a));
	vector<array<int, 3>> evs;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i].first <= b[j].first) {
				evs.push_back({b[j].first - a[i].first + 1, i, (j < m - 1 ? b[j + 1].second : -1) - a[i].second + 1});
			}
		}
	}

	sort(all(evs));
	vector<int> hui(n);
	for (int i = 0, j = 0; i < n; ++i) {
		while (j < m && b[j].first < a[i].first) {
			++j;
		}
		int u = (j == m) ? -1 : b[j].second;
		insert(hui[i] = u - a[i].second + 1);
	}
	int ans = max(0, getmax());
	for (int ti = 0; ti < (int)evs.size();) {
		int t = evs[ti][0];
		while (ti < (int)evs.size() && evs[ti][0] == t) {
			int i = evs[ti][1];
			erase(hui[i]);
			hui[i] = evs[ti][2];
			insert(hui[i]);
			++ti;
		}
		ans = min(ans, t + max(0, getmax()));
	}
	cout << ans << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}