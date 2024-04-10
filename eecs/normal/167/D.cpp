#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;

const int maxn = 100010, P = 1000000009;
int n, q, K, A, B, C, D, st[20][maxn];
array<int, 2> a[maxn];
vector<array<int, 2>> f = {{0, 0}};
__gnu_pbds::cc_hash_table<int, int> mp[maxn];

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 1; i <= K; i++) {
        scanf("%d %d", &a[i][0], &a[i][1]);
    }
    scanf("%d %d %d %d", &A, &B, &C, &D);
    vector<int> V;
    for (int i = K + 1; i <= n; i++) {
        a[i][0] = (1LL * A * a[i - 1][0] + B) % P;
        a[i][1] = (1LL * C * a[i - 1][1] + D) % P;
    }
    sort(a + 1, a + n + 1);
    iota(st[0] + 1, st[0] + n + 1, 1);
    for (int k = 1; k < 20; k++) {
        for (int i = 1; i + (1 << k) - 1 <= n; i++) {
            int x = st[k - 1][i], y = st[k - 1][i + (1 << (k - 1))];
            st[k][i] = a[x][1] > a[y][1] ? x : y;
        }
    }
    auto query = [&](int l, int r) {
        int k = __lg(r - l + 1);
        int x = st[k][l], y = st[k][r - (1 << k) + 1];
        return a[x][1] > a[y][1] ? x : y;
    };
    function<int(int, int)> solve = [&](int l, int r) {
        if (l > r) return 0;
        if (mp[l].find(r) != mp[l].end()) return mp[l][r];
        int k = query(l, r), ls = solve(l, k - 1), rs = solve(k + 1, r);
        int x = max(f[ls][0], f[ls][1]) + max(f[rs][0], f[rs][1]), y = 0;
        if (ls) y = max(y, f[ls][0] + max(f[rs][0], f[rs][1]) + 1);
        if (rs) y = max(y, max(f[ls][0], f[ls][1]) + f[rs][0] + 1);
        return f.push_back({x, y}), mp[l][r] = f.size() - 1;
    };
    scanf("%d", &q);
    while (q--) {
        int l, r, ans = 0;
        scanf("%d %d", &l, &r);
        l = lower_bound(a + 1, a + n + 1, array<int, 2>{l, 0}) - a;
        r = lower_bound(a + 1, a + n + 1, array<int, 2>{r + 1, 0}) - a - 1;
        if (l > r) { puts("0"); continue; }
        int id = solve(l, r);
        printf("%d\n", max(f[id][0], f[id][1]));
    }
    return 0;
}