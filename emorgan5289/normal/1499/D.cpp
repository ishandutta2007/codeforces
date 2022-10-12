#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

// returns a sorted list of all divisors of n in O(sqrt(n)) time.
template<typename T>
vector<T> divisors(T n) {
    vector<T> s, e;
    for (T i = 1; i <= (T)(sqrt(n)); i++)
        if (n%i == 0) {
            s.push_back(i);
            if (i*i != n) e.push_back(n/i);
        }
    for (int i = e.size()-1; i >= 0; i--)
        s.push_back(e[i]);
    return s;
}

const int N = 2e7+5;
int f[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 2; i < N; i++)
        if (!f[i])
            for (int j = i; j < N; j += i)
                f[j]++;
    int t; cin >> t;
    while (t--) {
        ll c, d, x; cin >> c >> d >> x;
        ll ans = 0;
        for (ll g : divisors(x))
            if ((g+d)%c == 0)
                ans += 1ll<<f[(g+d)/c];
        cout << ans << "\n";
    }
}