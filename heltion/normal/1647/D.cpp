#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    auto isPrime = [&](int n) {
        for (int i = 2; i * i <= n; i += 1) if (n % i == 0) return 0;
        return 1;
    };
    auto fmpf = [&](int n) {
        for (int i = 2; i * i <= n; i += 1) if (n % i == 0) return i;
        return n;
    };
    int t;
    for (cin >> t; t; t -= 1) {
        int x, d;
        cin >> x >> d;
        int r = 0;
        while (x % d == 0) {
            x /= d;
            r += 1;
        }
        if (r == 1) cout << "NO\n";
        else if (r == 2) cout << (isPrime(x) ? "NO\n" : "YES\n");
        else if (isPrime(d))
            cout << (isPrime(x) ? "NO\n" : "YES\n");
        else {
            int p = fmpf(d), dd = d, dr = 0, xd = x, xr = 0;
            while (dd % p == 0) {
                dd /= p;
                dr += 1;
            }
            while (xd % p == 0) {
                xd /= p;
                xr += 1;
            }
            if (xd != 1 or dd != 1) cout << "YES\n";
            else {
                int s = r * dr + xr;
                if (dr == 2 and s == 7) cout << "NO\n";
                else cout << "YES\n";
            }
        }
    }
    return 0;
}