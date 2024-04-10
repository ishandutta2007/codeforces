// Skyqwq
#include <iostream>
#include <cstdio>
#include <algorithm>
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}
 
template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(-x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 1005;

typedef pair<int, int> PII;

int tot;

PII e[3], ans[N * N];

bool vis[N][N];

void inline fill(PII s, PII t) {
	vis[s.fi][s.se] = vis[t.fi][t.se] = 1;
	while (s.fi < t.fi) {
		++s.fi;
		vis[s.fi][s.se] = 1;
	}
	while (s.se < t.se) {
		++s.se;
		vis[s.fi][s.se] = 1;
	}
	while (s.se > t.se) {
		--s.se;
		vis[s.fi][s.se] = 1;
	}
}
 
int main() {
	for (int i = 0; i < 3; i++)
		read(e[i].fi), read(e[i].se);
	sort(e, e + 3);
	PII t = mp(min(e[1].fi, e[2].fi), min(e[1].se, e[2].se));
	if (t.se < e[0].se && max(e[1].se, e[2].se) > t.se) t.se = e[0].se;
	if (max(e[1].se, e[2].se) < t.se) t.se = max(e[1].se, e[2].se);
	fill(e[0], t);
	fill(t, e[1]);
	fill(t, e[2]);
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			if (vis[i][j]) ans[++tot] = mp(i, j);
		}
	}
	printf("%d\n", tot);
	for (int i = 1; i <= tot; i++)
		printf("%d %d\n", ans[i].fi, ans[i].se);
	return 0;
}