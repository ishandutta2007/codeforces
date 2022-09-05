#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, id[maxn], f[maxn], g[maxn], s[maxn];
long long a[maxn], b[maxn];

void chk(int &x, int y) {
    if (x > y) x = y;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = a[n] - a[i];
    }
    memset(f, 0x3f, sizeof(f)), f[0] = 0;
    for (int i = 0; i <= 57; i++, swap(f, g)) {
        memset(g, 0x3f, sizeof(g));
        for (int j = 1; j <= n; j++) {
            b[j] = a[j] & ((1LL << i) - 1), id[j] = j;
        }
        sort(id + 1, id + n + 1, [&](int x, int y) { return b[x] > b[y]; });
        for (int j = 1; j <= n; j++) {
            s[j] = s[j - 1] + (a[id[j]] >> i & 1);
        }
        for (int j = 0; j <= n; j++) {
            chk(g[s[j]], f[j] + j - s[j] + s[n] - s[j]);
            chk(g[j + s[n] - s[j]], f[j] + s[j] + n - j - (s[n] - s[j]));
        }
    }
    printf("%d\n", f[0]);
    return 0;
}