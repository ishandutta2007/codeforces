#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int long long

// s[i] + l ... s[i] + r
//     s[j] + l ...  s[j] + r

// s[j] + l <= s[i] + r
// s[j] - s[i] <= r - l
// ans -= (s[i] + r) - (s[j] + l) + 1
// ans -= (s[i] - s[j]) + (r - l + 1)

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    int q;
    cin >> q;
    vector <int> l(q), r(q);
    for (int i = 0; i < q; ++i) {
        int lf, rg;
        cin >> lf >> rg;
        l[i] = lf;
        r[i] = rg;
    }
    vector <int> ans(q);
    vector <int> qr(q);
    iota(qr.begin(), qr.end(), 0);
    sort(qr.begin(), qr.end(), [&] (int i, int j) {
        return r[i] - l[i] < r[j] - l[j]; 
    });
    set <pair <int, int>> kek;
    for (int i = 1; i < n; ++i) kek.insert({a[i] - a[i - 1], i});
    int cnt = 0;
    int sum = 0;
    for (auto i : qr) {
        while (!kek.empty() && kek.begin()->first <= r[i] - l[i]) {
            ++cnt;
            sum += kek.begin()->first;
            kek.erase(kek.begin());
        }
        ans[i] = (n - cnt) * (r[i] - l[i] + 1) + sum;
    }
    for (int i = 0; i < q; ++i) {
        cout << ans[i] << ' ';
    }
}