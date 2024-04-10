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
	scanf("%d", &x);
	return x;
}

const int xx[4] = {-1, 0, 1, 0};
const int yy[4] = {0, 1, 0, -1};

bool check(const vector<string>& a, const string& s, int* perm) {
	int x = 0, y = 0;
	int n = a.size();
	int m = a[0].size();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == 'S') {
				x = i, y = j;
			}
		}
	}

	for (char c : s) {
		int idx = perm[c - '0'];
		x += xx[idx];
		y += yy[idx];
		if (x < 0 || x >= n || y < 0 || y >= m || a[x][y] == '#') {
			return false;
		}
		if (a[x][y] == 'E') {
			return true;
		}
	}
	return false;
}

int main() {
	int n = nxt(), m = nxt();
	vector<string> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	string s;
	cin >> s;

	int perm[4];
	for (int i = 0; i < 4; ++i) {
		perm[i] = i;
	}
	int ans = 0;

	do {
		if (check(a, s, perm)) {
			++ans;
		}
	} while (next_permutation(perm, perm + 4));

	printf("%d\n", ans);

	return 0;
}