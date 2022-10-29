#include <cstdio>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;
int a[1000000];
int b[1000000];
int n, m, p;
int calc(int x) {
    int v = 0;
    for (int i= 0; i <= x; i ++)
        if (i < n && x - i < m && x - i >= 0)
            v = (v + 1ll * a[i] * b[x - i]) % p;
    return v;
}
int main() {
    scanf("%d %d %d", &n, &m, &p);
    int x = 0;
    for (int i = 0; i < n; i ++ ) {
        scanf("%d", &a[i]);
        a[i] %= p;
        if (a[i]) {
            x = i;
        }
    }
    int y = 0;
    for (int i = 0; i < m; i ++ ) {
        scanf("%d", &b[i]);
        b[i] %= p;
        if (b[i]) {
            y = i;
        }
    }
    printf("%d\n", x + y);
    return 0;
}