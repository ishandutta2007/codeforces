#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> df;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        df.push_back(a[i]);
    }
    sort(df.begin(), df.end());
    df.resize(unique(df.begin(), df.end()) - df.begin());
    for (int i = 0; i < n; ++i) a[i] = lower_bound(df.begin(), df.end(), a[i]) - df.begin();
    int m = df.size();
    vector <int> fir(m, n), lst(m, -1);
    for (int i = 0; i < n; ++i) {
        fir[a[i]] = min(fir[a[i]], i);
        lst[a[i]] = max(lst[a[i]], i);
    }
    vector <int> good(m - 1);
    for (int i = 0; i + 1 < m; ++i) {
        if (lst[i] < fir[i + 1]) good[i] = 1;
    }
    int l = -1;
    int ans = m;
    for (int i = 0; i + 1 < m; ++i) {
        if (!good[i]) {
            ans = min(ans, m - i - 1 + l + 1);
            l = i;
        }
    }
    ans = min(ans, l + 1);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int q;
    cin >> q;
    while (q--) solve();
}