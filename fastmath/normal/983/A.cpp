#include <bits/stdc++.h>

using namespace std;
#define int long long

int gcd(int a, int b) {
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int p, q, b;
        cin >> p >> q >> b;
        q /= gcd(p, q);
        while (true) {
            if (q == 1) break;
            int d = gcd(q, b);
            if (d == 1) break;
            while (q % d == 0) q /= d;
        }
        if (q == 1) cout << "Finite\n";
        else cout << "Infinite\n";
    }

    return 0;
}