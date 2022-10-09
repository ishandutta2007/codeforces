#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

const int K = 17;
const int N = (1 << K);

pair<long long, long long> sp[K][N];
int pw[N];

long long getMin(int l, int r) {
    int k = pw[r - l];
    return min(sp[k][l].first, sp[k][(r - (1 << k))].first);
}

long long getMax(int l, int r) {
    int k = pw[r - l];
    return max(sp[k][l].second, sp[k][(r - (1 << k))].second);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        a[i] -= c;
    }

    vector<long long> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
        sp[0][i] = {pref[i + 1], pref[i + 1]};
    }
    pw[1] = 0;
    for (int i = 2; i <= n; ++i)
        pw[i] = pw[i / 2] + 1;

    for (int k = 1; k < K; ++k) {
        for (int i = 0; i + (1 << (k - 1)) < n; ++i) {
            sp[k][i].first = min(sp[k - 1][i].first, sp[k - 1][i + (1 << (k - 1))].first);
            sp[k][i].second = max(sp[k - 1][i].second, sp[k - 1][i + (1 << (k - 1))].second);
        }
    }
    vector<long long> ans(q);
    int ind = 0;
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l;
        if (pref[r] - pref[l] != 0) {
            cout << -1 << '\n';
        } else if (getMax(l, r) - pref[l] > 0) {
            cout << -1 << '\n';
        } else {
            cout << max(abs(getMin(l, r) - pref[l]), abs(getMax(l, r) - pref[l])) << '\n';
        }
        ++ind;
    }
}