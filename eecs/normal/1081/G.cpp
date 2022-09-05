#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, K, P, ans, cnt[maxn], inv[maxn], pre[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d %d %d", &n, &K, &P);
    for (int i = 1; i <= n; i++) {
        inv[i] = qp(i, P - 2);
        pre[i] = (pre[i - 1] + inv[i]) % P;
    }
    int inv2 = (P + 1) >> 1;
    function<void(int, int, int)> solve = [&](int l, int r, int h) {
        if (l > r) return;
        if (h == 1 || l == r) {
            cnt[r - l + 1]++;
            ans = (ans + 1LL * (r - l) * (r - l + 1) / 2 % P * inv2) % P;
        } else {
            int mid = (l + r) >> 1;
            solve(l, mid, h - 1), solve(mid + 1, r, h - 1);
        }
    };
    solve(1, n, K);
    auto calc = [&](int n, int m) {
        int ans = 0;
        auto solve = [&]() {
            for (int i = 1; i <= n; i++) {
                ans = (ans + 1LL * inv2 * i % P * (pre[i + m] - pre[i] + P)) % P;
                ans = (ans - 1LL * inv2 * (pre[i + m] - pre[i] + P) % P + P) % P;
            }
        };
        solve(), swap(n, m), solve();
        return ans;
    };
    vector<int> V;
    for (int i = 1; i <= n; i++) {
        if (cnt[i]) V.push_back(i);
    }
    assert(V.size() <= 2);
    for (int x : V) {
        ans = (ans + 1LL * cnt[x] * (cnt[x] - 1) / 2 % P * calc(x, x)) % P;
    }
    if (V.size() == 2) {
        ans = (ans + 1LL * cnt[V[0]] * cnt[V[1]] % P * calc(V[0], V[1])) % P;
    }
    printf("%d\n", ans);
    return 0;
}