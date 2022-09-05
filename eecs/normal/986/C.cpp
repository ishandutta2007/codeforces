#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 4200000;
int n, m, a[maxn], fa[maxn], fir[maxn], sec[maxn];
bool flag;

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

inline void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x ^ y) fa[x] = y, flag = 1;
}

inline void upd(int k, int v) {
    if (!fir[k]) fir[k] = v;
    else if (v ^ fir[k]) sec[k] = v;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &a[i]);
    }
    iota(fa + 1, fa + m + 1, 1);
    while (1) {
        memset(fir, 0, sizeof(fir));
        memset(sec, 0, sizeof(sec));
        for (int i = 1; i <= m; i++) {
            upd(a[i], find(i));
        }
        for (int i = 0; i < 1 << n; i++) {
            for (int j = 0; j < n; j++) if (i >> j & 1) {
                int k = i ^ (1 << j);
                if (fir[k]) upd(i, fir[k]);
                if (sec[k]) upd(i, sec[k]);
                if (fir[i] && sec[i]) break;
            }
        }
        flag = 0;
        for (int i = 1; i <= m; i++) {
            int j = ((1 << n) - 1) ^ a[i];
            if (fir[j]) unite(i, fir[j]);
            if (sec[j]) unite(i, sec[j]);
        }
        if (!flag) break;
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        if (i == find(i)) ans++;
    }
    printf("%d\n", ans);
    return 0;
}