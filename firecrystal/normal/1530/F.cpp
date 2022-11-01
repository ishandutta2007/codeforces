// Skyqwq
#include <iostream>
#include <cstdio>
#include <cstring>
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
 
const int N = 21, P = 31607;

int n, f[1 << N][2][2], g[1 << N][2][2], a[N][N], S, num[1 << N];

int c[N][1 << N], lb[1 << N];

int inline power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (LL)res * a % P;
        a = (LL)a * a % P;
        b >>= 1;
    }
    return res;
}

int inv = power(10000, P - 2);

int p;

int inline get(int s, int x, int y) {
    if (x) 
        s |= 1 << p;
    if (y) s |= 1 << (n - p - 1);
    return c[p][s];
}

void inline add(int &x, int y) {
    x += y;
    if (x >= P) x -= P;
}

int main() {
    read(n); S = (1 << n) - 1;
    for (int i = 1; i < (1 << n); i++) {
        num[i] = num[i ^ (i & -i)] + 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            read(a[i][j]);
            a[i][j] = a[i][j] * inv % P;
        }
    }
    for (int i = 0; i < n; i++) lb[1 << i] = i;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            c[i][j] = 1;
            if (j) {
                int t = j & -j;
                c[i][j] = c[i][j ^ t] * a[i][lb[t]] % P;
            }
        }
    }
    for (int i = 0; i < (1 << n); i++) {
        for (int x = 0; x < 2; x++) {
            for (int y = 0; y < 2; y++) {
                f[i][x][y] = 1;
            }
        }
    }
    for (int w = 0; w < n; w++) {
        memcpy(g, f, sizeof g);
        memset(f, 0, sizeof f);
        p = w;
        for (int i = 0; i < (1 << n); i++) {
            for (int x = 0; x < 2; x++) {
                for (int y = 0; y < 2; y++) {
                    add(f[i][x][y], (P - (g[i][x][y] * c[w][S] % P)));
                    add(f[i][x][y], g[i][x][y] * get(i, x, y) % P);
                }
            }
        } 
    }
    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        for (int x = 0; x < 2; x++) {
            for (int y = 0; y < 2; y++) {
                int t = (num[i] + x + y) & 1;
                if (t) add(ans, P - f[i][x][y]);
                else add(ans, f[i][x][y]);
            }
        }
    }
    printf("%d\n", (1 - ans + P) % P);
    return 0;
}