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

const int N = 505;
int a[N][N], o[N], c[N*N], t;
vector<array<int, 2>> e;

void dfs(int l, int r) {
    debug(l, r);
    int x = t++, p = l;
    c[x] = a[o[l]][o[r-1]];
    for (int i = l; i <= r; i++)
        if (i == r || a[o[p]][o[i]] == c[x]) {
            if (p+1 == i)
                e.pb({o[p], x}), p = i;
            else
                e.pb({t, x}), dfs(p, i), p = i;
        }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    t = n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    iota(o, o+n, 0);
    for (int x = 0; x < n-1; x++)
        sort(o+x+1, o+n, [&](int i, int j){
            return a[o[x]][i] < a[o[x]][j];
        });
    dfs(0, n);
    cout << t << "\n";
    for (int i = 0; i < n; i++)
        cout << a[i][i] << " ";
    for (int i = n; i < t; i++)
        cout << c[i] << " \n"[i == t-1];
    cout << n+1 << "\n";
    for (auto& [x, y] : e)
        cout << x+1 << " " << y+1 << "\n";
}