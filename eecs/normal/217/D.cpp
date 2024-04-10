#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010, P = 1000000007;
int n, m, ans, cnt[maxn];
bitset<120> f;

int main() {
    scanf("%*d %d %d", &m, &n);
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x), cnt[min(x % m, m - x % m)]++;
    }
    function<void(int, int)> dfs = [&](int cur, int coef) {
        if (cur + cur > m) { (ans += coef) %= P; return; }
        dfs(cur + 1, coef);
        if (!cnt[cur] || f[cur]) return;
        auto o = f;
        f |= (f << cur) | (f >> cur) | (f << (m - cur)) | (f >> (m - cur));
        f[cur] = f[cur + m] = f[m - cur] = f[2 * m - cur] = 1;
        dfs(cur + 1, 1LL * coef * cnt[cur] % P), f = o;
    };
    dfs(1, 1);
    printf("%d\n", ans);
    return 0;
}