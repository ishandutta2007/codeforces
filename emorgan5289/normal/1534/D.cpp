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
// #include "../../debug.cpp"
#endif

ll n;

vector<ll> qry(ll r) {
    cout << "? " << r+1 << endl;
    vector<ll> d(n);
    for (int i = 0; i < n; i++)
        cin >> d[i];
    return d;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<vector<int>> adj(n);
    auto c = qry(0);
    vector<array<int, 2>> e;
    ll t = 0;
    for (int i = 0; i < n; i++)
        if (c[i]%2 == 0) t++;
    if (t > n-t)
        for (int i = 0; i < n; i++)
            c[i]++;
    for (int i = 0; i < n; i++) {
        if (c[i]%2 == 0) {
            auto q = i == 0 ? c : qry(i);
            for (int j = 0; j < n; j++)
                if (q[j] == 1) e.pb({j, i});
        }
    }

    cout << "!\n";
    for (auto& [i, j] : e)
        cout << i+1 << " " << j+1 << "\n";
}