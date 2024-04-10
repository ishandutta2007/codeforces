#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()

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

void ok() {
	puts("YES");
	exit(0);
}

int getSum(const vector<vector<int>>& pr, int x1, int y1, int x2, int y2) {
	if (x1 > x2) {
		swap(x1, x2);
	}
	if (y1 > y2) {
		swap(y1, y2);
	}
	return pr[x2 + 1][y2 + 1] - pr[x1][y2 + 1] - pr[x2 + 1][y1] + pr[x1][y1];
}

int main(){
	int n = nxt(), m = nxt();
	vector<string> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int sx, sy, tx, ty;

	vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			pref[i + 1][j + 1] = pref[i][j + 1] + pref[i + 1][j] - pref[i][j];
			if (a[i][j] == '*') {
				pref[i + 1][j + 1] += 1;
			}
			if (a[i][j] == 'S') {
				sx = i, sy = j;
			}
			if (a[i][j] == 'T') {
				tx = i, ty = j;
			}
		}
	}

	// hor
	for (int i = 0; i < n; ++i) {
		int ax = i, ay = sy;
		int bx = i, by = ty;
		if (getSum(pref, sx, sy, ax, ay) + getSum(pref, ax, ay, bx, by) + getSum(pref, bx, by, tx, ty) == 0) {
			ok();
		}
	}
	// ver
	for (int i = 0; i < m; ++i) {
		int ax = sx, ay = i;
		int bx = tx, by = i;
		if (getSum(pref, sx, sy, ax, ay) + getSum(pref, ax, ay, bx, by) + getSum(pref, bx, by, tx, ty) == 0) {
			ok();
		}
	}

	puts("NO");

	return 0;
}