#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;

const int N = 40;

ull g[N];
bool ok[1 << (N / 2)];
int dp[1 << (N / 2)];
ui kek[1 << (N / 2)];

int n, m;

void init() {
    cin >> n >> m;
    map <string, int> num;
    int uk = 0;
    vector <int> cur;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            sort(cur.begin(), cur.end());
            cur.resize(unique(cur.begin(), cur.end()) - cur.begin());
            for (auto x : cur) {
                for (auto y : cur) {
                    g[x] |= (1ull << y);
                }
            }
            cur.clear();
        }
        else {
            string s;
            cin >> s;
            if (!num.count(s)) {
                num[s] = uk++;
            }
            cur.push_back(num[s]);
        }
    }
    sort(cur.begin(), cur.end());
    cur.resize(unique(cur.begin(), cur.end()) - cur.begin());
    for (auto x : cur) {
        for (auto y : cur) {
            g[x] |= (1ull << y);
        }
    }
}

void solve() {
    for (int i = 0; i < m; ++i) {
        g[i] ^= ((1ull << m) - 1);
    }
    int l = m / 2;
    int r = m - l;
    ok[0] = 1;
    for (ui mask = 1; mask < (1 << l); ++mask) {
        int x = __builtin_ctz(mask);
        ui nmask = mask ^ (1 << x);
        ok[mask] = ok[nmask] & ((g[x] & nmask) == nmask);
    }
    dp[0] = 0;
    for (ui mask = 1; mask < (1 << r); ++mask) {
        int x = __builtin_ctz(mask);
        ui nmask = mask ^ (1 << x);
        dp[mask] = max(dp[nmask], dp[nmask & (g[x + l] >> l)] + 1);
    }
    kek[0] = (1 << r) - 1;
    for (ui mask = 1; mask < (1 << l); ++mask) {
        int x = __builtin_ctz(mask);
        ui nmask = mask ^ (1 << x);
        kek[mask] = kek[nmask] & (g[x] >> l);
    }
    int res = 0;
    for (ui mask = 0; mask < (1 << l); ++mask) {
        if (ok[mask]) res = max(res, dp[kek[mask]] + __builtin_popcount(mask));
    }
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    init();
    solve();
}