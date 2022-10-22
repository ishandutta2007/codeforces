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
int a[500005], b[500005], vis[500005];
struct Seg_Tree {
	struct st {
		int l, r;
		int _min, _max;
		int ans;
	}t[2000005];
	void build (int id, int l, int r) {
		t[id].l = l, t[id].r = r;
		if (l == r) {
			t[id]._max = t[id]._min = a[l];
			t[id].ans = (a[l] * a[l]) % mod;
			return ;
		}
		int mid = (l + r) / 2;
		build (id << 1, l, mid);
		build (id << 1 | 1, mid + 1, r);
		t[id]._min = min (t[id << 1]._min, t[id << 1 | 1]._min);
		t[id]._max = max (t[id << 1]._max, t[id << 1 | 1]._max);
		t[id].ans = (t[id << 1].ans + t[id << 1 | 1].ans) % mod;
	} 
	void push_down (int id, int x, int y) {
		if (t[id].l == t[id].r) {
			t[id]._min = t[id]._max = y;
			t[id].ans = y * y % mod;
			return ;
		}
		int mid = (t[id].l + t[id].r) / 2;
		if (x <= mid) push_down (id << 1, x, y);
		else push_down (id << 1 | 1, x, y);
		t[id]._min = min (t[id << 1]._min, t[id << 1 | 1]._min);
		t[id]._max = max (t[id << 1]._max, t[id << 1 | 1]._max);
		t[id].ans = (t[id << 1].ans + t[id << 1 | 1].ans) % mod;
	}
	int get_min (int id, int l, int r) {
		if (l <= t[id].l && t[id].r <= r) {
			return t[id]._min;
		}
		int mid = (t[id].l + t[id].r) / 2, _min = 1e12;
		if (l <= mid) _min = min (_min, get_min (id << 1, l, r));
		if (r > mid) _min = min (_min, get_min (id << 1 | 1, l, r));
		return _min;
	}
	int get_max (int id, int l, int r) {
		if (l <= t[id].l && t[id].r <= r) {
			return t[id]._max;
		}
		int mid = (t[id].l + t[id].r) / 2, _max = 0;
		if (l <= mid) _max = max (_max, get_max (id << 1, l, r));
		if (r > mid) _max = max (_max, get_max (id << 1 | 1, l, r));
		return _max;
	}
	int get_sum (int id, int l, int r) {
		if (l <= t[id].l && t[id].r <= r) {
			return t[id].ans;
		}
		int mid = (t[id].l + t[id].r) / 2, cnt = 0;
		if (l <= mid) cnt += get_sum (id << 1, l, r);
		if (r > mid) cnt += get_sum (id << 1 | 1, l, r);
		return cnt % mod;
	}
}T;

int s1[500005], s2[500005];
int fac[500005], f[500005];
int check (int l, int r, int k) {
	int len = r - l + 1;
	int sum = (s1[r] - s1[l-1] + mod) % mod;
	int cnt = ((sum - f[len-1] * k) % mod + mod) % mod;
	int _min = cnt * quickmod (len, mod - 2) % mod;
	int _max = (_min + k * (len - 1)) % mod;
	if ((_min + _max) * len % mod * quickmod (2, mod - 2) % mod != sum) return 0;
	if (T.get_sum(1, l, r) == (len * (_min % mod) % mod * (_min % mod) % mod + fac[len-1] * k % mod * k % mod + f[len-1] * k % mod * (_min % mod) % mod * 2ll % mod) % mod) {
		return 1;
	}
	return 0;
}
signed main () {
//	freopen ("grade.in", "r", stdin);
//	freopen ("grade.out", "w", stdout);
	for (int i = 1; i <= 500000; i++) fac[i] = (fac[i-1] + i * i) % mod, f[i] = (f[i-1] + i) % mod;
	int n = read (), Q = read ();
	for (int i = 1; i <= n; i++) a[i] = read (), s1[i] = (s1[i-1] + a[i]) % mod, s2[i] = (s2[i-1] + a[i] * a[i]) % mod;
	T.build(1, 1, n);
	while (Q--) {
		int l = read (), r = read (), k = read ();
		if (l > r) swap (l, r);
		if (check (l, r, k) || (check (l, r, mod - k))) puts("Yes");
		else puts ("No"); 
	}
	return 0;
}
/*
4 1
7 21 14 14
1 4 1000000000

*/