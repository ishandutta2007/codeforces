// Skyqwq
#include <iostream>
#include <cstdio>

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
	if (x < 0) { putchar('-'); print(x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 2e5 + 5;

LL n, b[N], a[N], p = -1;
 
int main() {
	read(n);
	bool o = 1;
	for (int i = 0; i < n; i++) {
		read(b[i]);
		a[i] = b[i];
		if (b[i]) o = 0;
	}
	for (int i = 0; i < n; i++) {
		if (b[i] < b[(i + 1) % n] && p == -1) p = i;
	}
	if (o) {
		puts("YES");
		for (int i = 1; i <= n; i++) printf("1 ");
		return 0;
	}
	if (p == -1) { puts("NO"); return 0; }
	int t = p;
	while (t != (p + 1) % n) {
		while (a[t] <= b[(t - 1 + n) % n]) a[t] += a[(t + 1) % n];
		t = (t - 1 + n) % n; 
	}
	puts("YES");
	for (int i = 0; i < n; i++) printf("%lld ", a[i]);
	return 0;
}