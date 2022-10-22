#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

vector <int> oth;
vector <pii> op;
int bad;

void Solve(int n, int coef) {
	if (n == 1) {
		oth.push_back(coef);
		return ;
	}
	int tar = 1; while (tar < n) tar <<= 1;
	if (tar == n) {
		oth.push_back(tar * coef), Solve(n - 1, coef);
		return ;
	}
	int maxj = -1, bd = -1;
	for (int i = n; ; i--) {
		int j = tar - i;
		if (j >= i) break;
		op.push_back(mp(i * coef, j * coef));
		oth.push_back((i + j) * coef);
		if (maxj == -1) maxj = i - j, bd = j - 1;
	}
	oth.push_back(tar / 2 * coef);
	Solve(maxj / 2, coef * 2);
	if (bd) Solve(bd, coef);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		op.clear();
		int n; scanf("%d", &n);
		if (n == 2) {
			printf("-1\n");
			continue;
		}
		int tar = 1; while (tar < n) tar <<= 1;
		bad = 0;
		oth.clear();
		Solve(n, 1);
		if (bad) {
			printf("-1\n");
			continue;
		}
		sort(oth.begin(), oth.end());
		while (oth.size() && oth.back() == tar) oth.pop_back();
		int fd = 0;
		for (int i = 1; i < oth.size(); i++) {
			if (oth[i] == oth[i - 1]) {
				op.push_back(mp(oth[i], oth[i - 1]));
				for (int j = 0; j < oth.size(); j++) {
					if (j == i - 1) continue;
					int x = oth[j] * (i == j ? 2 : 1);
					while (x != tar) op.push_back(mp(0, x)), op.push_back(mp(x, x)), x <<= 1;
				}
				fd = 1;
				break;
			}
		}
		op.push_back(mp(0, tar));
		assert(fd);
		printf("%d\n", (int)op.size());
		for (auto it : op) {
			printf("%d %d\n", it.fi, it.se);
		}
	}
	return 0;
}