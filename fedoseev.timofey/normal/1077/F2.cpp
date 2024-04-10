#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll Inf = 1e18;

struct Queue {
    deque <pair <int, ll>> q;
    void push(int i, ll x) {
        while (!q.empty() && q.back().second <= x) q.pop_back();
        q.push_back(make_pair(i, x));
    }
    void pop(int i, ll x) {
        if (!q.empty() && q.front() == make_pair(i, x)) q.pop_front();
    }
    ll get() {
        if (q.empty()) return -Inf;
        return q.front().second;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, k, x;
    cin >> n >> k >> x;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <vector <ll>> dp(x + 1, vector <ll> (n + 1, -Inf));
    dp[0][0] = 0;
    for (int i = 1; i <= x; ++i) {
        Queue mnq;
        for (int j = 1; j <= n; ++j) {
            mnq.push(j - 1, dp[i - 1][j - 1]);
            if (j - k - 1 >= 0) mnq.pop(j - k - 1, dp[i - 1][j - k - 1]);
            dp[i][j] = max(dp[i - 1][j], a[j - 1] + mnq.get());
        }
    }
    ll ans = -Inf;
    for (int i = n - k + 1; i <= n; ++i) ans = max(ans, dp[x][i]);
    if (ans < -Inf / 2) cout << "-1\n";
    else {
        cout << ans << '\n';
    }
}