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
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

// computes totient(i) for i from 0 to n in O(nlogn) time
vector<int> totientsieve(int n) {
    vector<int> p(n+1);
    iota(p.begin(), p.end(), 0);
    for (int i = 2; i <= n; i++)
        if (p[i] == i) for (int j = i; j <= n; j += i)
            p[j] = p[j]/i*(i-1);
    return p;
}

const int N = 1e6+5;
auto tot = totientsieve(N);

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, k; cin >> n >> k;
    if (k == 1) {
        cout << "3\n"; exit(0);
    }
    vector<ll> f(n+1), st;
    for (ll i = 3; i <= n; i++)
        f[tot[i]]++;
    for (int i = 0; i <= n; i++)
        while (f[i]--) st.pb(i);
    ll ans = 2;
    for (int i = 0; i < k; i++)
        ans += st[i];
    cout << ans << "\n";
}