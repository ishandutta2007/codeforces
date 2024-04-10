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

const int N = 1e5 + 5;

int n, a[N][2], f[N];

int inline get(int i) {
	if (a[i][0] != 0 && a[i][1] != 0) return 0;
	if (a[i][0] != 1 && a[i][1] != 1) return 1;
	return 2;
}
 
int main() {
	int T; read(T);
	while (T--) {
		read(n);
		for (int i = 1; i <= n; i++) scanf("%1d", &a[i][0]);
		for (int i = 1; i <= n; i++) scanf("%1d", &a[i][1]);
		int j = 0, k = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i][0] == 0 || a[i][1] == 0) j = i;
			if (a[i][0] == 1 || a[i][1] == 1) k = i;
			f[i] = f[i - 1] + get(i);
			if (j && k) {
				chkMax(f[i], f[min(j, k) - 1] + 2);
			}
		}
		printf("%d\n", f[n]);
		for (int i = 1; i <= n; i++) f[i] = 0;
	}
	return 0;
}