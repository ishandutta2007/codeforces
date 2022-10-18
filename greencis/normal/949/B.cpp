#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll n, x;
int q;

ll solve2(ll n, ll x);

ll solve(ll n, ll x) {
    if (x % 2 == 0)
        return x / 2 + 1;
    return (n + 1) / 2 + (n % 2 == 0 ? solve(n / 2, (x - 1) / 2) : solve2(n / 2, (x - 1) / 2));
}

ll solve2(ll n, ll x) {
    if (x % 2 == 1)
        return x / 2 + 1;
    return n / 2 + (n % 2 == 0 ? solve2(n / 2, x / 2) : solve((n + 1) / 2, x / 2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    while (q--) {
        cin >> x;
        cout << solve(n, x - 1) << "\n";
    }
}