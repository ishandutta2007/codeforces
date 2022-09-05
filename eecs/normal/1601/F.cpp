#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int B = 1000000, P1 = 998244353, P2 = 1000000007;
ll n, cnt;
vector<int> val[7];
int ans, sum[7];

int main() {
    scanf("%lld", &n);
    function<void(int, int)> dfs1 = [&](int d, int v) {
        val[d].push_back((++cnt - v + P1) % P1);
        if (d == 6) return;
        for (int c = 0; c < 10; c++) dfs1(d + 1, v * 10 + c);
    };
    dfs1(0, 0);
    for (int d = 0; d <= 6; d++) {
        sort(val[d].begin(), val[d].end());
        for (int x : val[d]) (sum[d] += x) %= P2;
    }
    function<void(int, ll)> dfs2 = [&](int d, ll v) {
        if (v > n) return;
        if (d) {
            if (v * B > n / 10 && (v + 1) * B - 1 <= n) {
                for (int i = 0, pw = 1; i <= 6; i++, pw *= 10) {
                    int coef = (cnt - 1LL * v * pw % P1 + P1) % P1;
                    auto it = lower_bound(val[i].begin(), val[i].end(), P1 - coef);
                    ans = (ans + 1LL * coef * val[i].size() + sum[i]) % P2;
                    ans = (ans - 1LL * P1 * (val[i].end() - it) % P2 + P2) % P2;
                }
                for (int i = 0; i <= 6; i++) cnt += val[i].size();
                return;
            }
            ans = (ans + (++cnt - v % P1 + P1) % P1) % P2;
        }
        for (int c = !d; c < 10; c++) dfs2(d + 1, v * 10 + c);
    };
    cnt = 0, dfs2(0, 0);
    printf("%d\n", ans);
    return 0;
}