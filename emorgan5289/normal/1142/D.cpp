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

vector<int> mul(vector<int> a, vector<int> b) {
    vector<int> c(12);
    for (int i = 0; i < 12; i++)
        c[i] = b[a[i]];
    return c;
}

vector<int> tree[1<<17][17];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    ll n = s.size();
    vector<vector<int>> v(10, vector<int>(12));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 11; j++)
            if (i < j)
                v[i][j] = (10+j*(j-1)/2+i)%11;
            else
                v[i][j] = 11;
        v[i][11] = 11;
    }
    for (int i = 0; i < n; i++)
        tree[i][0] = v[s[i]-'0'];
    for (int i = 1; i < 17; i++)
        for (int j = 0; j < n; j++)
            if (j+(1<<i) <= n)
                tree[j][i] = mul(tree[j][i-1], tree[j+(1<<(i-1))][i-1]);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int x = s[i]-'0', j = i+1;
        if (x == 0) continue;
        for (int k = 16; k >= 0; k--) {
            if (j+(1<<k) <= n && tree[j][k][x] != 11)
                x = tree[j][k][x], j += 1<<k;
        }
        debug(i, j);
        ans += j-i;
    }
    cout << ans << "\n";
}