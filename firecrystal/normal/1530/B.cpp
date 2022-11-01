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

const int N = 25;

int n, m, a[N][N];
 
int main() {
    int T; read(T);
    while (T--) {
        memset(a, 0, sizeof a);
        read(n), read(m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == 1 || i == n || j == 1 || j == m) {
                    if (!a[i - 1][j] && !a[i - 1][j - 1] && !a[i - 1][j + 1] && !a[i][j - 1]) {
                        a[i][j] = 1;
                    }
                }
                printf("%d", a[i][j]);
            }
            puts("");
        }
        puts("");
    }
    return 0;
}