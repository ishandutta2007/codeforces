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

const int N = 1e5 + 5;

int n, d[N];
 
int main() {
	int T; read(T);
	while (T--) {
		read(n);
		for (int i = 1; i <= n; i++) read(d[i]);
		sort(d + 1, d + 1 + n);
		LL s = 0;
		for (int i = 2; i <= n; i++) s += (d[i] - d[i - 1]);
		LL t = 0;
		for (int i = 1; i <= n; i++) {
			s += -d[i] * (i - 1ll) + t;
			t += d[i];
		}
		printf("%lld\n", s);
	}
	return 0;
}