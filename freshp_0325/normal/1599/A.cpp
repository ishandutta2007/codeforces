#include <map>
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define int long long
#define mp make_pair
const int mod = 1e9 + 7;
int read () {
	int x = 0, f = 1;
	char ch = getchar ();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar ();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar ();
	}
	return x * f;
}
void write (int x) {
	if (x < 0) x = -x, putchar ('-');
	if (x >= 10) write (x / 10);
	putchar (x % 10 + '0');
}
int quickmod (int x, int y) {
	int Ans = 1;
	while (y) {
		if (y & 1) Ans = (Ans * x) % mod;
		x = (x * x) % mod;
		y >>= 1;
	}
	return Ans;
}
int a[200005];
int d[200005];
int p[200005];
char ch[200005];
int op[200005];
signed main () {
//	freopen (".in", "r", stdin);
//	freopen (".out", "w", stdout);
	int n = read ();
	for (int i = 1; i <= n; i++) a[i] = read ();
	scanf ("%s", ch + 1);
	sort (a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		if (i == 1 || ch[i] != ch[i-1]) {
			d[i]++;
		}
		else {
			d[1]++;
			op[i] = -i + 1;
		}
	}
	for (int i = 1; i <= n; i++) d[i] += d[i-1];
	for (int i = 1; i <= n; i++) p[i] = a[d[i]+op[i]];
	
	int num = 0;
	for (int i = 1; i <= n; i++) {
		char col;
		if (ch[i] == 'L') {
			if (i % 2 == 1 || num > 0) col = 'L';
			else col = 'R';
		}
		else {
			if (i % 2 == 1 || num < 0) col = 'R';
			else col = 'L';
		}
		if (col == 'L') num -= p[i];
		else num += p[i];
		printf ("%lld %c\n", p[i], col);
	}
	return 0;
}
/*
*/