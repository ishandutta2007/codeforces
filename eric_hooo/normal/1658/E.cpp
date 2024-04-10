#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int a[2010][2010];
char ans[2010][2010];
int alive[4000010], pos[4000010];
int LP, RP, LQ, RQ;
int n;

void Erase(int x, int y, char c) {
	ans[x][y] = c, alive[a[x][y]] = 0;
}

void Erase(int id, char c) {Erase(id / n, id % n, c);}

void CalcP(int x) {
	for (int i = 0; i < n; i++) {
		int j = x - i;
		if (j >= 0 && j < n && !ans[i][j]) Erase(i, j, 'G');
	}
}

void CalcQ(int x) {
	for (int i = 0; i < n; i++) {
		int j = i - x;
		if (j >= 0 && j < n && !ans[i][j]) Erase(i, j, 'G');
	}
}

int main() {
	int k; scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
			alive[a[i][j]] = 1;
			pos[a[i][j]] = i * n + j;
		}
	}
	LP = 0, RP = n - 1 + n - 1, LQ = -n + 1, RQ = n - 1;
	int cur = n * n;
	while (1) {
		while (cur > 0 && !alive[cur]) cur--;
		if (cur == 0) break;
		int x = pos[cur] / n, y = pos[cur] % n;
		Erase(x, y, 'M');
		while (LP < x + y - k) CalcP(LP++);
		while (RP > x + y + k) CalcP(RP--);
		while (LQ < x - y - k) CalcQ(LQ++);
		while (RQ > x - y + k) CalcQ(RQ--);
	}
	for (int i = 0; i < n; i++) {
		printf("%s\n", ans[i]);
	}
	return 0;
}