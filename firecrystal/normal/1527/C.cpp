// Skyqwq
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

typedef long long LL;

// char buf[1<<23], *p1=buf, *p2=buf, obuf[1<<23], *O=obuf;
// #define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<21, stdin), p1 == p2) ? EOF : *p1++)

void inline read(int &x) {
    x = 0; char s = getchar();
    while (s < '0' || s > '9') s = getchar();
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
}

void print(int x) {
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 1e5 + 5;

int n;

map<int, LL> cnt;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		cnt.clear();
		cin >> n;
		LL ans = 0;
		for (int i = 1, x; i <= n; i++) {
			cin >> x;
			ans += (LL)(n - i + 1) * cnt[x];
			cnt[x] += i;
		}
		printf("%lld\n", ans);
	}
	return 0;
}