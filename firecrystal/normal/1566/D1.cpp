// Skyqwq
#include <bits/stdc++.h>

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

const int N = 305;

int n, m, a[N], s[N], p[N];

bool inline cmp(int x, int y) {
	if (a[x] == a[y]) return x > y;
	return a[x] < a[y];
}
 
int main() {
	int T; read(T);
	while (T--) {
		read(n), read(m);
		for (int i = 1; i <= m; i++) read(a[i]), p[i] = i;
		sort(p + 1, p + 1 + m, cmp);
		for (int i = 1; i <= m; i++) s[p[i]] = i; 
		int ans = 0;
		for (int i = 1; i <= m; i++) {
			for (int j = i + 1; j <= m; j++) {
				if (s[j] > s[i]) ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}