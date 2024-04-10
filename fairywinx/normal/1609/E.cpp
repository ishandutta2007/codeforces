#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

const int N = (1 << 17);
const int K = 7;

array<int, K> t[2 * N];

array<int, K> merge(array<int, K> a, array<int, K> b) {
    array<int, K> dp;
    fill(all(dp), 0);
    dp[0] = max(a[0], b[0]);
    dp[1] = a[1] + b[1];
    dp[2] = a[2] + b[2];
    dp[3] = max(a[3] + b[2], a[1] + b[3]);
    dp[4] = a[4] + b[4];
    dp[5] = max(a[5] + b[4], a[2] + b[5]);
    dp[6] = max({a[6] + b[4], a[3] + b[5], a[1] + b[6]});
    dp[0] = *max_element(all(dp));
    return dp;
}

array<int, K> to(char c) {
    array<int, K> res;
    fill(all(res), 0);
    if (c == 'a') {
        res[0] = 1;
        res[2] = 1;
        res[3] = 1;
        res[4] = 1;
        res[5] = 1;
        res[6] = 1;
    } else if (c == 'b') {
        res[0] = 1;
        res[1] = 1;
        res[3] = 1;
        res[4] = 1;
        res[5] = 1;
        res[6] = 1;
    } else if (c == 'c') {
        res[0] = 1;
        res[1] = 1;
        res[2] = 1;
        res[3] = 1;
        res[5] = 1;
        res[6] = 1;
    }
    return res;
}

void build(int v, int l, int r, string &s) {
    if (r - l == 1) {
        t[v] = to(s[l]);
        return;
    }

    int m = (l + r) / 2;
    build(v * 2 + 1, l, m, s);
    build(v * 2, m, r, s);
    t[v] = merge(t[v * 2 + 1], t[v * 2]);
}

void update(int v, int l, int r, int pos, char type) {
    if (r - l == 1) {
        t[v] = to(type);
        return;
    }
    int m = (l + r) / 2;
    if (pos < m)
        update(v * 2 + 1, l, m, pos, type);
    else
        update(v * 2, m, r, pos, type);
    t[v] = merge(t[v * 2 + 1], t[v * 2]);
}

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    build(1, 0, n, s);
    while (q--) {
        int pos;
        char c;
        cin >> pos >> c;
        update(1, 0, n, pos - 1, c);
        cout << n - *max_element(all(t[1])) << '\n';
    }
}