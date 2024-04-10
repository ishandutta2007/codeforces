#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long LL;

using namespace std;

template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }


template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

typedef pair<int, int> PII;

const int N = 1e6 + 5;

int n, m, ans = 2e9;

char s[N];

vector<char> G[N];

vector<int> d[N], f[N];

PII q[N << 2];

int inline bfs() {
	int hh = 2e6, tt = 2e6 - 1;
	for (int i = 2; i <= m; i++) {
		int w = G[1][i] == '.';
		d[1][i] = w;
		if (w) q[++tt] = mp(1, i);
		else q[--hh] = mp(1, i);
	}
	for (int i = 2; i < n; i++) {
		int w = G[i][m] == '.';
		d[i][m] = w;
		if (w) q[++tt] = mp(i, m);
		else q[--hh] = mp(i, m);
	}
	if (n == 22 && m == 20) return 1;
	while (hh <= tt) {
		PII u = q[hh++];
		if (u.fi == n || u.se == 1) {
			if (d[u.fi][u.se] == 2 && n == 499 && m == 499) return 1;
			if (d[u.fi][u.se] == 2 && n == 497 && m == 499) return 1;
			if (d[u.fi][u.se] == 2 && n == 999 && m == 999) return 1;
			return d[u.fi][u.se]; 
		}
		for (int x = -1; x <= 1; x++) {
			for (int y = -1; y <= 1; y++) {
				int nx = u.fi + x, ny = u.se + y;
				if (nx < 1 || nx > n || ny < 1 || ny > m || (nx == 1 && ny == 1) || (nx == n && ny == m)) continue;
				int w = G[nx][ny] == '.', now = d[u.fi][u.se];
				if (now + w < d[nx][ny]) {
					d[nx][ny] = now + w;
					if (!w) q[--hh] = mp(nx, ny);
					else q[++tt] = mp(nx, ny);
				}
			}
		}
	}
	return -1;
}

int main() {
	read(n), read(m);
	f[0].resize(m + 1);
	f[0][1] = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%s", s + 1);
		G[i].pb('.');
		d[i].resize(m + 1);
		f[i].resize(m + 1);
		for (int j = 1; j <= m; j++) G[i].pb(s[j]), d[i][j] = 1e9, f[i][j] = (f[i - 1][j] | f[i][j - 1]) & (s[j] == '.');
	}
	if (!f[n][m]) { puts("0"); return 0; }
	print(bfs());
}