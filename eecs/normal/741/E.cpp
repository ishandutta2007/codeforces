#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, SZ = 88;
const int P = 998244353, B = 233;
int n, m, q, rk[maxn], hs[maxn], ht[maxn], pw[maxn];
int st[17][maxn], lg[maxn], ans[maxn], mp[maxn];
char s[maxn], t[maxn];
vector<tuple<int, int, int>> Q[SZ + 5][SZ + 5];

int main() {
    scanf("%s %s %d", s + 1, t + 1, &q);
    n = strlen(s + 1), m = strlen(t + 1);
    for (int i = pw[0] = 1; i <= max(n, m); i++) {
        pw[i] = 1LL * pw[i - 1] * B % P;
        if (i > 1) lg[i] = lg[i >> 1] + 1;
    }
    for (int i = 1; i <= n; i++) {
        hs[i] = (1LL * hs[i - 1] * B + s[i]) % P;
    }
    for (int i = 1; i <= m; i++) {
        ht[i] = (1LL * ht[i - 1] * B + t[i]) % P;
    }

    auto substr = [&](int p, int k) {
        if (k <= p) return hs[k];
        if (k <= p + m) return int((1LL * hs[p] * pw[k - p] + ht[k - p]) % P);
        return int((1LL * hs[p] * pw[k - p] + 1LL * ht[m] * pw[k - p - m] +
            hs[k - m] - 1LL * hs[p] * pw[k - m - p] % P + P) % P);
    };
    auto lcp = [&](int x, int y) {
        int l = 1, r = n + m + 1, ans = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (substr(x, mid) == substr(y, mid)) l = (ans = mid) + 1;
            else r = mid - 1;
        }
        return ans;
    };
    auto get_pos = [&](int p, int k) {
        if (k <= p) return s[k];
        return k <= p + m ? t[k - p] : s[k - m];
    };
    iota(rk, rk + n + 1, 0);
    stable_sort(rk, rk + n + 1, [&](int x, int y) {
        int l = lcp(x, y);
        return get_pos(x, l + 1) < get_pos(y, l + 1);
    });

    auto init = [&](int n) {
        for (int i = 1; i < 17; i++) {
            for (int j = 0; j + (1 << i) - 1 <= n; j++) {
                st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    };
    auto query = [&](int l, int r) {
        if (l > r) return n + 1;
        int k = lg[r - l + 1];
        return min(st[k][l], st[k][r - (1 << k) + 1]);
    };

    for (int i = 0; i <= n; i++) {
        st[0][rk[i]] = mp[rk[i]] = i;
    }
    init(n);
    for (int i = 1, l, r, k, x, y; i <= q; i++) {
        scanf("%d %d %d %d %d", &l, &r, &k, &x, &y), ans[i] = n + 1;
        if (k > SZ) {
            for (; x <= n; x += k, y += k) {
                ans[i] = min(ans[i], query(max(x, l), min(y, r)));
            }
        } else {
            for (int j = x; j <= y; j++) {
                Q[k][j].emplace_back(l, r, i);
            }
        }
    }
    for (int i = 1; i <= SZ; i++) {
        for (int j = 0; j < i; j++) {
            int m = -1;
            for (int k = j; k <= n; k += i) st[0][++m] = mp[k];
            init(m);
            for (auto p : Q[i][j]) if (get<1>(p) >= j) {
                int l = (get<0>(p) - j + i - 1) / i, r = (get<1>(p) - j) / i;
                ans[get<2>(p)] = min(ans[get<2>(p)], query(l, r));
            }
        }
    }
    for (int i = 1; i <= q; i++) {
        printf("%d ", ans[i] > n ? -1 : rk[ans[i]]);
    }
    return 0;
}