#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include <assert.h>
#include <array>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

int n;
const int N = (1 << 18);

array<long long, 2> t[2 * N];

void update(int v, int l, int r, int L, int R, int val) {
    if (r <= L || R <= l)
        return;
    if (L <= l && r <= R) {
        t[v][0] = val;
        t[v][1] = min(0, val);
        return;
    }

    int m = (l + r) / 2;
    update(v * 2 + 1, l, m, L, R, val);
    update(v * 2, m, r, L, R, val);
    t[v][0] = t[v * 2 + 1][0] + t[v * 2][0];
    t[v][1] = min(t[v * 2 + 1][0] + t[v * 2][1], t[v * 2 + 1][1]);
}

int solve(vector<int> _a) {
    fill(t, t + min(n * 4, N * 2), array<long long, 2> {0, 0});
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        a[i].first = _a[i];
        a[i].second = i + 1;
    }
    sort(rall(a));
    int ans = 0;
    for (auto i : a) {
        update(1, 0, n, i.second - 1, i.second, i.first);
        ++ans;
        // cout << i.first << ' ' << i.second << ' ' << t[1][1] << ' ' << t[1][0] << '\n';
        // for (int i = 0; i < 4 * n; ++i)
        //     cout << t[i][0] << ':' << t[i][1] << '\n';
        if (t[1][1] < 0) {
            --ans;
            update(1, 0, n, i.second - 1, i.second, 0);
        }
    }

    return ans;
}

int stupid(vector<int> a) {
    vector<vector<long long>> dp(n + 1, vector<long long> (n + 1, -1));
    dp[0][0] = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dp[i][j] < 0)
                continue;
            if (dp[i][j] + a[i] >= 0) {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + a[i]);
            }
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        }
    }
    for (int i = 0; i <= n; ++i) {
        if (dp.back()[i] >= 0)
            ans = max(ans, i);
    }
    return ans;
}

void gen() {
    static mt19937 rnd(777);
    n = 5;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        a[i] = rnd() % 20 - 10;
    if (solve(a) != stupid(a)) {
        cout << n << '\n';
        for (int i : a)
            cout << i << ' ';
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // SOLVE
    // solve();
    // for (int i = 0; i < 100; ++i)
    //     gen();
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cout << solve(a) << '\n';
}