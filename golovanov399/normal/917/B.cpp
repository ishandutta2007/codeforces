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

const int N = 111;
vector<pair<int, char>> a[N];

char win[N][N][26];

char get(int x, int y, char last) {
	if (win[x][y][last] != -1) {
		return win[x][y][last];
	}
	char& res = win[x][y][last];
	res = 0;
	for (auto p : a[x]) {
		if (p.second < last) {
			continue;
		}
		if (get(y, p.first, p.second) == 0) {
			return res = 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	int n = nxt(), m = nxt();
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		char c;
		cin >> c;
		a[u].push_back({v, c - 'a'});
	}

	memset(win, -1, sizeof(win));

	for (int i = 0; i < n; ++i) {
		string res = "";
		for (int j = 0; j < n; ++j) {
			res += (char)('B' - get(i, j, 0));
		}
		cout << res << "\n";
	}

	return 0;
}