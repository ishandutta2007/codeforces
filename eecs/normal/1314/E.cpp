#include <bits/stdc++.h>
using namespace std;

const int maxn = 2050, P = 998244353;
int n, K, ans, f[maxn];

int main() {
    scanf("%d %d", &n, &K);
    if (K <= 2) {
        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            int j = K == 1 ? i : i * (i + 1) / 2;
            for (int k = j; k <= n; k++) (f[k] += f[k - j]) %= P;
        }
        for (int i = 1; i <= n; i++) (ans += f[i]) %= P;
    } else {
        vector<int> V;
        auto chk = [&]() {
            static vector<int> foo, bar;
            foo = V;
            for (int $ = 1; $ <= K - 2; $++, swap(foo, bar)) {
                int s = 0; bar.clear();
                for (int i = foo.size() - 1; ~i; i--) {
                    while (foo[i]--) bar.push_back(foo.size() - i);
                }
                for (int i = 0; i < bar.size(); i++) {
                    s += bar[i] * (bar.size() - i);
                }
                if (s > n) return 0;
            }
            return 1;
        };
        function<bool(int, int)> dfs = [&](int v, int cur) {
            if (!chk()) return 0;
            if (v < 63) ans++;
            for (int i = cur; i <= v; i++) {
                V.push_back(i);
                bool f = dfs(v - i, i);
                V.pop_back();
                if (!f) break;
            }
            return 1;
        };
        dfs(63, 1);
    }
    printf("%d\n", ans);
    return 0;
}