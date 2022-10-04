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
    int n, x;
    cin >> n >> x;
    vector <ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    ll ans = 0;
    ll A = 0, B = 0, C = 0;
    for (int i = 0; i < n; ++i) {
        A += a[i];
        A = max(A, 0LL);
        B += a[i] * x;
        B = max(B, A);
        C += a[i];
        C = max(C, B);
        ans = max(ans, C);
    }
    cout << ans << '\n';
}