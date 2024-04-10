#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    string s;
    cin >> n >> k >> s;
    
    queue<ii> q;
    string t(s);
    int mn = 0, mv = 0;
    for (;;) {
        bool ok = false;

        for (int i = 1; i < n; i++) {
            if (t[i - 1] == 'R' && t[i] == 'L') {
                mv++;
                ok = true;
                t[i - 1] = 'L';
                t[i] = 'R';
                if (!mn) q.emplace(i - 1, 0);
                i++;
            }
        }

        if (!ok) break;
        mn++;
    }

    if (k < mn || k > mv) return cout << -1, 0;

    int rd = 0;
    vi ans;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        if (cur.se != rd || k == mv + 1) {
            rd = cur.se;
            k--;

            cout << sz(ans);
            for (int i : ans) cout << ' ' << i;
            cout << '\n';

            ans.clear();
        }

        int i = cur.fi;
        s[i] = 'L';
        s[i + 1] = 'R';
        if (i && s[i - 1] == 'R') q.emplace(i - 1, rd + 1);
        if (i != n - 2 && s[i + 2] == 'L') q.emplace(i + 1, rd + 1);

        ans.pb(i + 1);
        mv--;
    }

    cout << sz(ans);
    for (int i : ans) cout << ' ' << i;

    return 0;
}