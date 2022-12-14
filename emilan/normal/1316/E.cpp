#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, p, k;
    cin >> n >> p >> k;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    // [idx][position]
    vector<vector<int>> b(n, vector<int>(p));
    for (auto &v : b) {
        for (int &x : v) cin >> x;
    }

    vector<int> a_idx(n);
    iota(a_idx.begin(), a_idx.end(), 0);
    sort(a_idx.begin(), a_idx.end(), [&](int i, int j) {
        return a[i] > a[j];
    });

    ll a_val = 0;
    for (int i = 0; i < k; i++) {
        a_val += a[a_idx[i]];
    }

    ll ans = 0;
    for (int q = 0; q <= p; q++) {
        if (q > 0) a_val += a[a_idx[q - 1 + k]];

        // [position][rank]
        vector<vector<int>> b_idx1(
            p,
            vector<int>(a_idx.begin(), a_idx.begin() + q + k)
        );
        vector<vector<int>> b_idx2(
            p,
            vector<int>(a_idx.begin() + q + k, a_idx.end())
        );

        for (int i = 0; i < p; i++) {
            sort(b_idx1[i].begin(), b_idx1[i].end(), [&](int x, int y){
                return b[x][i] - a[x] > b[y][i] - a[y];
            });

            sort(b_idx2[i].begin(), b_idx2[i].end(), [&](int x, int y){
                return b[x][i] > b[y][i];
            });
        }

        vector<int> per(p);
        iota(per.begin(), per.end(), 0);
        do {
            ll cur = a_val;
            set<int> vis;

            // promote cheerleaders
            for (int r = 0; r < q; r++) {
                int i = per[r], j = 0;
                while (vis.count(b_idx1[i][j])) j++;

                int s = b_idx1[i][j];
                vis.insert(s);
                cur += b[s][i] - a[s];
            }

            // include others
            for (int r = q; r < p; r++) {
                int i = per[r], j = 0;
                while (vis.count(b_idx2[i][j])) j++;

                int s = b_idx2[i][j];
                vis.insert(s);
                cur += b[s][i];
            }

            ans = max(ans, cur);
        } while (next_permutation(per.begin(), per.end()));
    }
    cout << ans << '\n';
}