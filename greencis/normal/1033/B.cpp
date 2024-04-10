#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

bool check(ll x) {
    for (ll i = 2; i * i <= x; ++i)
        if (x % i == 0)
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        if (a - b == 1 && check(a + b))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}