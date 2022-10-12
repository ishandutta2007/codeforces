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

const int N = 2005, L = 1e6+5;
array<int, 2> at[N], bt[N];
int d[L];
vector<array<int, 2>> a, b;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> at[i][0] >> at[i][1];
    for (int i = 0; i < m; i++)
        cin >> bt[i][0] >> bt[i][1];
    fill(d, d+L, -1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (at[i][0] > bt[j][0] || at[i][1] > bt[j][1])
                continue;
            d[bt[j][0]-at[i][0]] = max(d[bt[j][0]-at[i][0]], bt[j][1]-at[i][1]);
        }
    ll ans = inf_ll;
    for (int i = L-2; i >= 0; i--) {
        d[i] = max(d[i], d[i+1]);
        ans = min(ans, ll(i+d[i]+1));
        if (d[i] > 0) debug(i, d[i]);
    }
    cout << ans << "\n";
}