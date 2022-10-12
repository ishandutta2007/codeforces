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

const int N = 2e5+5;
vector<int> adj[N];
ll a[N], c[N], s[N], m[N];

void dfs(int i) {
    if (adj[i].size() == 0) c[i]++;
    for (auto& j : adj[i]) {
        dfs(j), c[i] += c[j];
        s[i] += s[j], m[i] = max(m[i], m[j]);
    }
    ll r = min(m[i]*c[i]-s[i], a[i]);
    s[i] += r, a[i] -= r;
    if (a[i] > 0)
        m[i] += 1+(a[i]-1)/c[i];
    s[i] += a[i];
    debug(i, s[i], m[i]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int x; cin >> x; x--;
        adj[x].pb(i);
    }
    for (int i = 0; i < n; i++)
        cin >> a[i];
    dfs(0);
    cout << m[0] << "\n";
}