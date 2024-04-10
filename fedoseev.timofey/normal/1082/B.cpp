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
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        if (c == 'G') a[i] = 1;
        else a[i] = 0;
    }
    vector <int> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }
    int r = 0;
    int ans = 0;
    for (int l = 0; l < n; ++l) {
        while (r < n && ((pref[r + 1] - pref[l] == r - l + 1) || (pref[r + 1] - pref[l] == r - l && pref[n] - (pref[r + 1] - pref[l]) >= 1))) {
            ++r;
        }
        ans = max(ans, r - l);
    }
    cout << ans << '\n';
}