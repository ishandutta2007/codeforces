#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vector<vi> to(n + 1);
    rep(i, n - 1) {
        int x;
        cin >> x;
        to[x].push_back(i + 2);
    }

    vi cnt(n);
    function<int(int)> dfs = [&](int i) {
        if (to[i].empty()) {
            cnt[1]++;
            return 1;
        }
        int cur = 0;
        for (int x : to[i]) {
            cur += dfs(x);
        }
        cnt[cur]++;
        return cur;
    };
    dfs(1);

    int cur = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        while (sum < i) {
            cur++;
            sum += cnt[cur];
        }
        cout << cur << ' ';
    }
}