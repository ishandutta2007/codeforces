#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int INF = 0x3f3f3f3f;

typedef pair <int, int> pii;

struct Node {
	int l, r, id;
	Node() {}
	Node(int x) {l = x, r = id = -1;}
	bool operator < (const Node &A) const {return l < A.l;}
}a[2010];

int dp[2010][2010][4], lst[2010][2010][4];
int id[2010], L[2010], R[2010];
vector <int> from[2010];
int sz[2010], lll[2010][2010][4], need[2010];
pii way[2010];
int n;

bool chmax(int &x, int y) {return (x = max(x, y)) == y;}

int BuildTree(int l, int r) {
	if (l == r) {
		L[l] = a[l].l, R[l] = a[l].r;
		return l;
	}
	int x = l, cur = l + 1;
	while (cur <= r) {
		int nxt = lower_bound(a, a + n + 1, Node(a[cur].r)) - a;
		from[x].push_back(BuildTree(cur, nxt - 1));
		cur = nxt;
	}
	return x;
}

void GetSz(int x) {
	sz[x] = x > 0;
	for (auto v : from[x]) GetSz(v), sz[x] += sz[v];
}

void Solve(int x) {
	for (auto v : from[x]) Solve(v);
	if (x && sz[x] == 1) {
		dp[x][1][0] = a[x].r - a[x].l, L[x] = a[x].l, R[x] = a[x].r;
		return ;
	}
	int tot = 0;
	for (auto v : from[x]) {
		int ttt = min(sz[v] * 2, n);
		if (!tot) {
			tot = ttt, L[x] = L[v], R[x] = R[v];
			for (int i = 0; i <= ttt; i++) for (int p = 0; p < 4; p++) {
				dp[x][i][p] = dp[v][i][p], lst[v][i][p] = -2;
			}
		} else {
			tot = min(n, tot + ttt);
			for (int i = tot; i >= 0; i--) {
				for (int pq = 0; pq < 4; pq++) {
					int &res = dp[x][i][pq] = -INF;
					for (int j = sz[v]; j <= i && j <= ttt; j++) {
						if (chmax(res, dp[x][i - j][(pq & 1) | 0] + dp[v][j][(pq & 2) | 0])) {
							lst[v][i][pq] = j << 4 | 0 << 2 | 0 << 1;
						}
						if (chmax(res, dp[x][i - j][(pq & 1) | 0] + dp[v][j][(pq & 2) | 1])) {
							lst[v][i][pq] = j << 4 | 0 << 2 | 1 << 1;
						}
						if (chmax(res, dp[x][i - j][(pq & 1) | 2] + dp[v][j][(pq & 2) | 0])) {
							lst[v][i][pq] = j << 4 | 2 << 2 | 0 << 1;
						}
						if (chmax(res, dp[x][i - j][(pq & 1) | 2] + dp[v][j][(pq & 2) | 1])) {
							lst[v][i][pq] = j << 4 | 2 << 2 | 1 << 1;
						}
						if (i - j) {
							if (chmax(res, dp[x][i - j - 1][pq & 1] + dp[v][j][pq & 2] + L[v] - R[x])) {
								lst[v][i][pq] = j << 4 | 1;
							}
						}
					}
				}
			}
			R[x] = R[v];
		}
	}
	if (x) {
		tot++;
		for (int i = tot; i >= 1; i--) {
			for (int p = 0; p < 4; p++) {
				if (p & 1) {
					if (chmax(dp[x][i][p], dp[x][i - 1][p & 2] + L[x] - a[x].l)) {
						lll[x][i][p] = 1;
					}
				}
				if (p & 2) {
					if (chmax(dp[x][i][p], dp[x][i - 1][p & 1] + a[x].r - R[x])) {
						lll[x][i][p] = 2;
					}
				}
				if (chmax(dp[x][i][p], dp[x][i - 1][p])) {
					lll[x][i][p] = 3;
				}
			}
		}
	}
	for (int i = 0; i < sz[x]; i++) for (int p = 0; p < 4; p++) {
		dp[x][i][p] = -INF;
	}
}

vector <int> all;

void Calc(int l, int r) {
	for (int i = 0; i < n; i++) {
		if (way[i].fi == l) way[i].fi = r;
	}
}

void MakeAns(int l, int r) {
	int x = all.back(); all.pop_back();
	way[a[x].id] = mp(l, r);
}

void Print(int x, int i, int pq) {
	all.push_back(x);
	if (x && sz[x] == 1) {
		MakeAns(a[x].l, a[x].r);
		return ; 
	}
	if (lll[x][i][pq]) {
		if (lll[x][i][pq] == 3) need[x] = 1, i--, all.pop_back();
		else {
			int D = lll[x][i][pq] - 1;
			if (!D) MakeAns(a[x].l, L[x]);
			else Calc(R[x], a[x].r), MakeAns(R[x], a[x].r);
			i--, pq ^= 1 << D;
		}
	}
	vector <int> tmp;
	for (auto v : from[x]) tmp.push_back(R[v]);
	reverse(from[x].begin(), from[x].end());
	for (auto v : from[x]) {
		tmp.pop_back();
		if (lst[v][i][pq] == -2) Print(v, i, pq);
		else {
			int D = lst[v][i][pq], j = D >> 4, p = D >> 2 & 3, q = D >> 1 & 1, flag = D & 1;
			if (!flag) Print(v, j, (pq & 2) | q), i -= j, pq = (pq & 1) | p;
			else Calc(tmp.back(), L[v]), MakeAns(tmp.back(), L[v]), Print(v, j, pq & 2), i -= j + 1, pq = pq & 1;
		}
	}
	reverse(from[x].begin(), from[x].end());
}

int main() {
	memset(lst, -1, sizeof(lst));
	cin >> n;
	a[0].l = -1, a[0].r = 1000000001, a[0].id = 0;
	for (int i = 1; i <= n; i++) cin >> a[i].l >> a[i].r, a[i].id = i;
	sort(a, a + n + 1), BuildTree(0, n);
	for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) for (int k = 0; k < 4; k++) {
		dp[i][j][k] = -INF;
	}
	GetSz(0);
	Solve(0);
	int ans = -INF, ppp;
	for (int p = 0; p < 4; p++) {
		if (chmax(ans, dp[0][n][p])) ppp = p;
	}
	for (int i = 1; i <= n; i++) way[i].fi = -0x3f3f3f3f;
	printf("%d\n", ans);
	Print(0, n, ppp);
	for (int i = n; i >= 1; i--) {
		if (need[i]) {
			for (int j = 1; j <= n; j++) {
				if (way[j].fi > a[i].l && way[j].fi < a[i].r && way[j].fi + 1 < way[j].se) {
					way[a[i].id].fi = way[j].fi, way[a[i].id].se = way[j].fi + 1;
					way[j].fi++;
					goto END;
				}
				if (way[j].se > a[i].l && way[j].se < a[i].r && way[j].fi + 1 < way[j].se) {
					way[a[i].id].fi = way[j].se - 1, way[a[i].id].se = way[j].se;
					way[j].se--;
					goto END;
				}
			}
			END:;
			need[i] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d %d\n", way[i].fi, way[i].se);
	}
	return 0;
}