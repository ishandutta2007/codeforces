#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);

    ll n;
    cin >> n;

    ll a = 0;
    while (true) {
        a = a * 10 + 9;
        if (a > n) {
            a /= 10;
            break;
        }
    }
    n -= a;
    ll ans = 0;
    while (n) ans += n % 10, n /= 10;
    while (a) ans += a % 10, a /= 10;
    cout << ans;
}