#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll cur, f[10010][5], t[10010];

int main() {
    memset(f, -1, sizeof(f));
    function<ll(ll, int)> dfs = [&](ll x, int d) {
        if (!d) return 0LL;
        if (x > 10000) return dfs(10000, d);
        if (~f[x][d]) return f[x][d];
        ll s = x;
        for (int i = 0; i <= x; i++) s += dfs(s, d - 1) + 1;
        return f[x][d] = s - x - 1;
    };
    for (int i = 5; i; i--) {
        int n = min(cur + 1, 10000LL);
        cout << n;
        for (int j = 0; j <= n; j++) {
            t[j] = cur++;
            if (j) cout << " " << t[j];
            cur += dfs(cur, i - 1);
        }
        cout << endl;
        int x; cin >> x;
        if (!~x) break;
        cur = t[x];
    }
    return 0;
}