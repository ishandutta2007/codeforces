// Skyqwq
#include <iostream>
#include <cstdio>
#include <set>
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

const int N = 2e5 + 5;

int n, a[N], b[N], p[N];

set<int> s;
 
int main() {
    int T; read(T);
    while (T--) {
        s.clear();
        read(n);
        for (int i = 1; i <= n; i++) read(a[i]), s.insert(i);
        int c = 0;
        for (int i = 1; i <= n; i++) {
            if (s.count(a[i])) {
                b[i] = a[i], s.erase(a[i]);
                ++c;
            }
        }
        int r;
        for (int i = 1; i <= n; i++) {
            if (!b[i]) {
                b[i] = *s.begin(); s.erase(s.begin());
                r = i;
            }
        }
        printf("%d\n", c);
        for (int i = 1; i <= n; i++) p[b[i]] = i;
        for (int i = 1; i <= n; i++) {
            if (b[i] == i) {
                if (p[a[i]]) {
                    int v = p[a[i]];
                    swap(b[i], b[v]);
                } else {
                    swap(b[i], b[r]);
                }
            }
        }
        for (int i = 1; i <= n; i++) printf("%d ", b[i]);
        puts("");
        for (int i = 1; i <= n; i++) b[i] = 0, p[i] = 0;
    }
    return 0;
}