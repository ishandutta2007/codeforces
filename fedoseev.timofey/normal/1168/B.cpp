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
    string s;
    cin >> s;
    int n = s.size();
    vector <int> min_r(n, n);
    for (int c = 0; c < n; ++c) {
        int l = c;
        int r = n - c - 1;
        for (int i = 1; i <= min(100, min(l, r)); ++i) {
            if (s[c - i] == s[c] && s[c] == s[c + i]) min_r[c - i] = min(min_r[c - i], c + i);
        }
    }
    ll ans = 0;
    int r = n;
    for (int i = n - 1; i >= 0; --i) {
        r = min(r, min_r[i]);
        ans += n - r;
    }
    cout << ans << '\n';
}