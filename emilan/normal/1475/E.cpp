#include <bits/stdc++.h>

using namespace std;

template <typename T>
vector<vector<T>> comb_matrix(int mx, T mod) {
    vector<vector<T>> comb(mx + 1);
    for (int n = 0; n <= mx; n++) {
        comb[n].assign(n + 1, 1);
        for (int r = 1; r < n; r++) {
            comb[n][r] = (comb[n - 1][r - 1] + comb[n - 1][r]) % mod;
        }
    }
    return comb;
}

const int kN = 1000;
const int kMod = 1e9 + 7;

void solve() {
    static auto comb = comb_matrix(kN + 1, kMod);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    sort(begin(a), end(a));

    int i = n - k;
    int l = int(lower_bound(begin(a), end(a), a[i]) - begin(a));
    int r = int(upper_bound(begin(a), end(a), a[i]) - begin(a));

    cout << comb[r - l][r - i] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}