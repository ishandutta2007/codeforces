#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

void solve() {
    int b, p, f, h, c;
    cin >> b >> p >> f >> h >> c;
    b /= 2;
    int ans = 0;
    if (h < c) {
        swap(h, c);
        swap(p, f);
    }
    int tk = min(b, p);
    ans += tk * h;
    b -= tk;
    tk = min(b, f);
    ans += tk * c;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) solve();
}