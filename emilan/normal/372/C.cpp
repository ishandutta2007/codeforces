#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int maxn = 1.5e5 + 5, maxm = 305;
const ll inf = 1ll << 60;
ll dp[2][maxn];

struct mq {
    vt<pll> l, r;
    void push(ll x) {
        r.emplace_back(x, max(x, r.empty() ? -inf : r.back().se));
    }
    void pop() {
        if (l.empty()) {
            while (!r.empty()) {
                l.emplace_back(
                    r.back().fi,
                    max(r.back().fi, l.empty() ? -inf : l.back().se)
                );
                r.pop_back();
            }
        }

        l.pop_back();
    }
    ll mx() {
        return max(
            l.empty() ? -inf : l.back().se,
            r.empty() ? -inf : r.back().se
        );
    }
};

void solve() {
    int n, m, d;
    cin >> n >> m >> d;
    int pt = -1;
    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;

        if (!~pt) pt = t;
        int rad = min(ll(t - pt) * d, ll(n));
        pt = t;

        mq q;
        for (int j = 1; j <= rad; j++) q.push(dp[i & 1][j]);
        for (int j = 1; j <= n; j++) {
            if (j + rad <= n) q.push(dp[i & 1][j + rad]);
            if (j - rad >= 2) q.pop();
            dp[~i & 1][j] = q.mx() + b - abs(a - j);
        }
    }

    cout << *max_element(dp[m & 1] + 1, dp[m & 1] + n + 1);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}