#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

#define sz(x) (int)((x).size())

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

const int MAXN = 3333;
int win[MAXN][MAXN];
int curr[MAXN];

void reduce(int x, int y, int add) {
	curr[x] -= add;
	curr[y] += add;
	win[x][y] -= add;
	win[y][x] += add;
}

int main(){

	int m = nxt(), n = nxt();
	vector<int> a(m);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}
	int cur_sum = 0;
	for (int i = 0; i < n; ++i) {
		cur_sum += a[i];
		if (cur_sum > (i + 1) * (2 * m - i - 2)) {
			puts("no");
			return 0;
		}
	}
	for (int i = n; i < m; ++i) {
		int mn = min((i + 1) * (2 * m - i - 2) - cur_sum, a[i - 1]);
		if (mn < 0) {
			puts("no");
			return 0;
		}
		a[i] = mn;
		cur_sum += a[i];
	}
	if (cur_sum < m * (m - 1)) {
		puts("no");
		return 0;
	}

	n = m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			win[j][i] = 2;
		}
	}
	for (int i = 0; i < n; ++i) {
		curr[i] = accumulate(win[i], win[i] + n, 0);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = n - 1; j > i; --j) {
			if (curr[i] == a[i]) {
				break;
			}
			int add = min({curr[i] - a[i], a[j] - curr[j], 2});
			assert(add >= 0);
			// if (add) {
			// 	cerr << "win[" << i << "][" << j << "] reduced by " << add << " and became equal to " << win[i][j] << ": now curr[" << i <<
			// 			"] = " << curr[i] << ", curr[" << j << "] = " << curr[j] << "\n";
			// }
			reduce(i, j, add);
		}
	}

	for (int i = 0; i < n; ++i) {
		assert(curr[i] == a[i]);
	}

	puts("yes");
	for (int i = 0; i < n; ++i) {
		string res = "";
		for (int j = 0; j < n; ++j) {
			if (i == j) {
				res += "X";
			} else {
				res += "LDW"[win[i][j]];
			}
		}
		puts(res.c_str());
	}

	return 0;
}