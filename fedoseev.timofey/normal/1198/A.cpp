#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, I;
    cin >> n >> I;
    I *= 8;
    I /= n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    vector <int> b = a;
    b.resize(unique(b.begin(), b.end()) - b.begin());
    int cnt = (1 << min(31, I));
    int ans = 1e9;
    for (int l = 0; l < (int)b.size(); ++l) {
        int r = min((int)b.size(), l + cnt);
        int cnt1 = lower_bound(a.begin(), a.end(), b[l]) - a.begin();
        int cnt2 = a.end() - upper_bound(a.begin(), a.end(), b[r - 1]);
        ans = min(ans, cnt1 + cnt2);
    }
    cout << ans << '\n';
}