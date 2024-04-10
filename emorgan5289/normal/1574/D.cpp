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

ll n;
vector<vector<ll>> a;

ll val(array<int, 10> x) {
    ll s = 0;
    for (int i = 0; i < n; i++)
        s += a[i][x[i]];
    return s;
}

bool cmp(array<int, 10> x, array<int, 10> y) {
    ll vx = val(x), vy = val(y);
    return vx == vy ? x < y : vx > vy;
}

set<array<int, 10>, decltype(&cmp)> s(cmp);
set<array<int, 10>> banned;

vector<array<int, 10>> adj(array<int, 10> x) {
    vector<array<int, 10>> out;
    for (int j = n-1; j >= 0; j--) {
        x[j]++;
        if (x[j] < a[j].size())
            out.pb(x);
        x[j]--;
        if (x[j]) break;
    }
    return out;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        ll k; cin >> k;
        a[i].resize(k);
        for (int j = 0; j < k; j++)
            cin >> a[i][j];
        reverse(all(a[i]));
    }
    ll m; cin >> m;
    for (int i = 0; i < m; i++) {
        array<int, 10> b; b.fill(0);
        for (int j = 0; j < n; j++)
            cin >> b[j], b[j] = a[j].size()-b[j];
        banned.insert(b);
    }
    debug(banned);
    array<int, 10> x; x.fill(0);
    s.insert(x);
    while (!s.empty()) {
        x = *s.begin(); s.erase(s.begin());
        debug(x, val(x));
        if (!banned.count(x)) {
            for (int i = 0; i < n; i++)
                cout << a[i].size()-x[i] << " \n"[i == n-1];
            exit(0);
        }
        for (auto& y : adj(x)) {
            debug(y);
            s.insert(y);
        }
    }
    cout << "no solution\n";
}