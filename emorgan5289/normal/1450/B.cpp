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

const int N = 105;
int x[N], y[N], adj[N][N];
int n, k;

void solve() {
    for (int i = 0; i < n; i++)
        if (accumulate(adj[i], adj[i]+n,0) == n) {
            cout << 1 << "\n";
            return;
        }
    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> x[i] >> y[i];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                adj[i][j] = abs(x[i]-x[j])+abs(y[i]-y[j]) <= k;
        solve();
    }
}