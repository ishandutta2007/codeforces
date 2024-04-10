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

const int N = 1e6+5;
int f[N], g[N];
vector<int> p[N], ans;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x <= m) f[x]++, p[x].pb(i);
    }
    for (int i = 1; i <= m; i++)
        for (int j = i; j <= m; j += i)
            g[j] += f[i];
    int x = max_element(g+1, g+m+1)-g;
    for (int i = 1; i <= x; i++)
        if (x%i == 0)
            for (int j : p[i]) ans.pb(j);
    sort(all(ans));
    cout << x << " " << g[x] << "\n";
    for (auto& i : ans)
        cout << i+1 << " ";
    cout << "\n";
}