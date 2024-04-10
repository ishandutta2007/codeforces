#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)x.size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define rall(x)     x.rbegin(), x.rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("io\\in.txt", "r", stdin);
    freopen("io\\out.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vvi a(n - 2, vi(3));
    vector<set<int>> v(n + 1);
    rep(i, n - 2) {
        rep(j, 3) {
            cin >> a[i][j];
            v[a[i][j]].insert(i);
        }
    }

    vi one, two;
    for (int i = 1; i <= n; i++) {
        if (sz(v[i]) == 1) one.pb(i);
        else if (sz(v[i]) == 2) two.pb(i);
    }

    vi ans;
    vector<set<int>> v1(v);
    int i = *v1[one[0]].begin();
    rep(r, n - 3) {
        rep(j, 3) v1[a[i][j]].erase(i);

        int next = -1;
        rep(j, 3) {
            if (sz(v1[a[i][j]]) == 1) next = *v1[a[i][j]].begin();
            else if (v1[a[i][j]].empty()) ans.pb(a[i][j]);
        }
        i = next;
    }

    if (n == 5) {
        for (int i = 1; i <= 5; i++) if (sz(v[i]) == 3) ans.pb(i);
        ans.pb(two[0] == ans[1] ? two[1] : two[0]);
        ans.pb(one[1]);
    } else {
        vector<set<int>> v2(v);
        i = *v1[one[1]].begin();
        rep(r, 3) {
            rep(j, 3) v2[a[i][j]].erase(i);

            int next = -1;
            rep(j, 3) {
                if (sz(v2[a[i][j]]) == 1) next = *v2[a[i][j]].begin();
                else if (v2[a[i][j]].empty()) ans.pb(a[i][j]);
            }
            i = next;
        }
        swap(ans[n - 3], ans[n - 1]);
    }

    for (int i : ans) cout << i << ' ';

    return 0;
}