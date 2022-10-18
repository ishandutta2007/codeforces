#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n;
ll p, q, b;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    while (n--) {
        cin >> p >> q >> b;
        if (!p) cout << "Finite\n";
        else {
            ll g = __gcd<ll>(p, q);
            p /= g;
            q /= g;
            while (true) {
                g = __gcd<ll>(q, b);
                if (g == 1)
                    break;
                while (q % g == 0)
                    q /= g;
            }
            if (q > 1) cout << "Infinite\n";
            else cout << "Finite\n";
        }
    }
}