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
 
const int N = 505;
 
int n, k, ans, b[N], t, c[N], len;
 
int a[N] = { 0, 2, 1, 5, 7, 6, 8, 298, 3, 498, 389 };
 
int inline ask(int *b, int t) {
	printf("?");
	//int oo = 0;
	for (int i = 1; i <= t; i++)
		printf(" %d", b[i]);//, oo ^= a[b[i]];
	puts("");
	fflush(stdout);
	//return oo;
	int x; scanf("%d", &x);
	return x;
} 
 
int vis[N];
 
int c0[2], c1;
 
int main() {
	read(n), read(k);
	// int ss = 0;
	// for (int i = 1; i <= n; i++) ss ^= (a[i] = rand());
	// cout << ss << endl;
	int r = n % k;

	//cout << r << endl;

	if ((r & 1) && k % 2 == 0) {
		puts("-1");
		fflush(stdout);
		return 0;
	}

	if (r && (r + k) % 2 == 0 && k - (r + k) / 2 <= n - r - k) {
		for (int i = r + k + 1; i <= n; i += k) {
			t = 0;
			for (int j = i; j < i + k; j++) {
				b[++t] = j, vis[j] = 1;
			}
			ans ^= ask(b, t);
		}
		int nd = k - (r + k) / 2;
		int rr = (r + k) / 2;
		t = 0;
		for (int i = 1; i <= rr; i++) b[++t] = i;
		for (int i = rr + 1; i <= r + k; i++) c[++len] = i;
		for (int i = r + k + 1; i <= r + k + nd; i++)
			b[++t] = i, c[++len] = i;
		ans ^= ask(b, t);
	    ans ^= ask(c, len);
	    printf("! %d\n", ans);
		fflush(stdout);
		return 0;
	}

	for (int i = r + 1; i <= n; i += k) {
		t = 0;
		for (int j = i; j < i + k; j++) {
			b[++t] = j, vis[j] = 1;
		}
		ans ^= ask(b, t);
	}
 
	if (r == 0) {
		printf("! %d\n", ans);
		fflush(stdout);
		return 0;
	}


 
	int rest = r, L = 1;
	if (r & 1) {
		t = 0;
		for (int i = 1; i <= k; i++) vis[i] ^= 1, b[++t] = i;
		ans ^= ask(b, t);	
		rest = k - r;
        L = r + 1;
    }
    
    int ky = n - rest;

	int t0 = rest / 2, t1 = k - t0;

    while (t0 + n - t0 * 2 < k) t0--;
   
    t1 = k - t0;

    for (int i = L; i < L + rest; i += t0 * 2) {
        int R = min(i + t0 * 2 - 1, L + rest - 1);
        int l = (R - i + 1) / 2;
        t = 0, len = 0;
        for (int j = i; j < i + l; j++) b[++t] = j;
        for (int j = i + l; j <= R; j++) c[++len] = j;
        for (int j = 1; j <= n; j++) {
            if (!(i <= j && j <= R) && t < k) {
                b[++t] = j, c[++len] = j;
            }
        }
        ans ^= ask(b, t);
	    ans ^= ask(c, len);
    }
	
 
	printf("! %d\n", ans);
	fflush(stdout);
	return 0;
}