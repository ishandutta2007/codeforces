#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

vector<int> topologicalsort(vector<vector<int>>& adj) {

    int n = adj.size();
    vector<int> out, stk, in(n, 0);
    vector<bool> visited(n, 0);

    for (int i = 0; i < n; i++)
        for (int j : adj[i])
            in[j]++;
    for (int i = 0; i < n; i++)
        if (in[i] == 0)
            stk.push_back(i);

    while (!stk.empty()) {
        int i = stk.back();
        stk.pop_back();
        out.push_back(i);
        for (int j : adj[i])
            if (--in[j] == 0)
                stk.push_back(j);
    }
    return out;
}

const int N = 2e5+5;
ll a[N], b[N];
vector<vector<int>> adj, radj;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    adj.resize(n), radj.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i] != -1)
            adj[i].pb(b[i]-1);
    }
    auto p = topologicalsort(adj);
    ll ans = 0;
    for (auto& i : p) {
        ans += a[i];
        if (a[i] > 0 && b[i] != -1) {
            radj[i].pb(b[i]-1);
            a[b[i]-1] += a[i];
        } else if (b[i] != -1)
            radj[b[i]-1].pb(i);
    }
    cout << ans << "\n";
    for (auto& i : topologicalsort(radj))
        cout << i+1 << " ";
    cout << "\n";
}