#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int long long

int gcd(int a, int b) {
    return (b == 0 ? a : gcd(b, a % b));
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    int l = 1;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        l = lcm(l, x);
        l = gcd(l, k);
    }
    if (l == k) cout << "Yes\n";
    else cout << "No\n";
}