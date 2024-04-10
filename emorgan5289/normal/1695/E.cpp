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

vector<vector<array<int, 2>>> adj;
vector<vector<int>> cyc;
vector<int> ve, v;

void dfs(int i) {
    cyc.back().pb(i);
    v[i] = 1;
    for (auto& [j, e] : adj[i]) {
        if (!ve[e]) {
            ve[e] = 1;
            if (v[j])
                cyc.back().pb(j);
            else
                dfs(j);
            cyc.back().pb(i);
        }
    }
}

string f(string s, int x) {
    string y;
    for (int i = 0; i < x; i++)
        y += s;
    return y;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    adj.assign(2*n+1, {});
    ve.assign(n, 0);
    v.assign(2*n+1, 0);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        adj[x].pb({y, i});
        adj[y].pb({x, i});
    }
    for (int i = 1; i <= 2*n; i++) {
        cyc.pb({});
        dfs(i);
        cyc.back().pop_back();
    }
    bool ok = 1;
    vector<int> a, b;
    string s1, s2, s3, s4;
    for (auto& c : cyc) {
        int m = c.size()/2;
        if (m == 0)
            continue;
        if (m == 1)
            ok = 0;
        for (int i = 0; i < m; i++) {
            a.pb(c[i]);
            b.pb(c[c.size()-i-1]);
        }
        if (m%2 == 0) {
            s1 += f("LR", m/2);
            s2 += f("LR", m/2);
            s3 += "U" + f("LR", m/2-1) + "U";
            s4 += "D" + f("LR", m/2-1) + "D";
        } else {
            s1 += f("LR", m/2) + "U";
            s2 += f("LR", m/2) + "D";
            s3 += "U" + f("LR", m/2);
            s4 += "D" + f("LR", m/2);
        }
    }
    if (ok) {
        cout << "2 " << n << "\n";
        for (int i = 0; i < n; i++)
            cout << a[i] << " \n"[i == n-1];
        for (int i = 0; i < n; i++)
            cout << b[i] << " \n"[i == n-1];
        cout << s1 << "\n";
        cout << s2 << "\n";
        cout << s3 << "\n";
        cout << s4 << "\n";
    } else
        cout << "-1\n";
}