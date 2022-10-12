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

vector<int> solve_even(vector<ll> a) {
    ll n = a.size();
    vector<vector<int>> cyc;
    vector<int> v(n, 0), x(n), p(n);
    map<ll, vector<int>> g;
    for (int i = 0; i < n; i++)
        g[a[i]].pb(i);
    for (auto& [_, w] : g) {
        for (int i = 0; i < w.size(); i += 2)
            x[w[i]] = w[i+1], x[w[i+1]] = w[i];
    }
    for (int i = 0; i < n; i++) {
        if (v[i]) continue;
        cyc.pb({});
        for (int j = i; !v[j]; j = n-1-x[j]) {
            cyc.back().pb(j);
            cyc.back().pb(x[j]);
            v[j] = v[x[j]] = 1;
        }
        for (int j = 2; j < cyc.back().size(); j++)
            p[cyc.back()[j]] = cyc.back()[(j+1)%cyc.back().size()];
    }
    for (int i = 0; i+1 < cyc.size(); i++) {
        p[cyc[i][0]] = cyc[i+1][2%cyc[i+1].size()];
        p[cyc[i][1]] = cyc[i+1][1];
    }
    if (cyc.size() == 0) {
        p[cyc[0][0]] = cyc[0][1];
        p[cyc[0][1]] = cyc[0][2%cyc[0].size()];
    } else {
        p[cyc[cyc.size()-1][0]] = cyc[0][1];
        p[cyc[cyc.size()-1][1]] = cyc[0][2%cyc[0].size()];
    }
    return p;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> a(n);
        vector<int> p;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        debug(a);
        map<ll, int> f;
        for (int i = 0; i < n; i++)
            f[a[i]]++;
        int odd = 0;
        for (auto& [x, fx] : f)
            if (fx%2 == 1) odd++;
        if (odd != n%2) {
            cout << "NO\n";
            continue;
        }
        if (n%2 == 0)
            p = solve_even(a);
        else {
            bool ok = 0;
            for (int i = 0; i < n; i++)
                if (i != n/2 && f[a[i]]%2 == 1) {
                    a[i] = a[n/2];
                    a.erase(a.begin()+n/2);
                    p = solve_even(a);
                    for (int j = 0; j < n-1; j++)
                        if (p[j] >= n/2) p[j]++;
                    p.insert(p.begin()+n/2, n/2);
                    swap(p[i], p[n/2]);
                    ok = 1;
                    break;
                }
            if (!ok) {
                cout << "NO\n";
                continue;
            }
        }
        vector<int> q(n);
        for (int i = 0; i < n; i++)
            q[p[i]] = i;
        cout << "YES\n";
        for (int i = 0; i < n; i++)
            cout << q[i]+1 << " \n"[i == n-1];
    }
}