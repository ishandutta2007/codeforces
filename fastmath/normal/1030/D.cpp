#include <bits/stdc++.h>

using namespace std;

#define int long long

void print(int a, int b) {
    cout << "YES\n";
    cout << "0 0\n";
    cout << a << " 0\n";
    cout << "0 " << b << '\n';
    exit(0);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    
    int a, b;

    a = n << 1;
    b = m;
    if ((__gcd(a, k) * __gcd(b, k)) % k == 0) {
        int d = __gcd(a, k);
        a /= d;
        int ost = k / d;
        b /= ost;
        if (a <= n && b <= m) print(a, b);
    }

    a = n;
    b = m << 1;
    if ((__gcd(a, k) * __gcd(b, k)) % k == 0) {
        int d = __gcd(b, k);
        b /= d;
        int ost = k / d;
        a /= ost;
        if (a <= n && b <= m) print(a, b);
    }

    cout << "NO\n";
    return 0;
}