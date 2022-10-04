#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int md = 1e9 + 7;

int sub(int a, int b) {
    a -= b;
    if (a < 0) a += md;
    return a;
}

int mul(int a, int b) {
    return ((ll)a * b) % md;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector <int> pref(n + 1);
    vector <int> p2(n + 1);
    p2[0] = 1;
    for (int i = 1; i <= n; ++i) p2[i] = (p2[i - 1] * 2) % md;
    for (int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + (s[i - 1] - '0');
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        int co = pref[r + 1] - pref[l];
        int cz = (r - l + 1) - co;
        int ans = sub(p2[co], 1);
        ans += mul(sub(p2[cz], 1), ans);
        ans %= md;
        cout << ans << '\n';
    }
}