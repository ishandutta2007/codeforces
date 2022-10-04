#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int K = 15;

bool ok[1 << K];
bool dp[1 << K];
int prv[1 << K];

pair <int, int> go[1 << K][K];

pair <int, int> ans[K];

void rec(int mask) {
    if (prv[mask] == mask) {
        for (int i = 0; i < K; ++i) {
            if (mask & (1 << i)) {
                ans[i] = go[mask][i];
            }
        }
    } else {
        rec(prv[mask]);
        rec(mask ^ prv[mask]);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int k;
    cin >> k;
    map <int, int> where;
    vector <vector <int>> who(k);
    vector <ll> have(k);
    ll sum = 0;
    for (int i = 0; i < k; ++i) {
        int n;
        cin >> n;
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            sum += x;
            have[i] += x;
            who[i].push_back(x);
            where[x] = i;
        }
    }
    if (sum % k != 0) {
        cout << "No\n";
        return 0;
    }
    ll need = sum / k;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < who[i].size(); ++j) {
            vector <int> used(k);
            used[i] = 1;
            int cur = i;
            ll x = who[i][j];
            bool bad = false;
            vector <int> gs = {i};
            vector <int> tk;
            tk.push_back(x);
            while (true) {
                ll nb = need - (have[cur] - x);
                if (!where.count(nb)) {
                    bad = true;
                    break;
                }
                int id = where[nb];
                if (!used[id]) {
                    x = nb;
                    gs.push_back(id);
                    tk.push_back(nb);
                    cur = id;
                    used[id] = 1;
                } else {
                    if (id != i) {
                        bad = true;
                    }
                    if (nb != who[i][j]) {
                        bad = true;
                    }
                    break;
                }
            }
            if (!bad) {
                int mask = 0;
                for (int id : gs) mask |= (1 << id);
                ok[mask] = 1;
                for (int i = 0; i < (int)gs.size(); ++i) {
                    go[mask][gs[i]] = {tk[i], gs[(i - 1 + (int)gs.size()) % gs.size()]};
                }
            }
        }
    }
    for (int mask = 1; mask < (1 << k); ++mask) {
        if (ok[mask]) {
            dp[mask] = 1;
            prv[mask] = mask;
        } else {
            for (int smask = mask; smask > 0; smask = (smask - 1) & mask) {
                if (dp[smask] && dp[mask ^ smask]) {
                    dp[mask] = 1;
                    prv[mask] = smask;
                    break;
                }
            }
        }
    }
    if (!dp[(1 << k) - 1]) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    rec((1 << k) - 1);
    for (int i = 0; i < k; ++i) {
        cout << ans[i].first << ' ' << ans[i].second + 1 << '\n';
    }
}