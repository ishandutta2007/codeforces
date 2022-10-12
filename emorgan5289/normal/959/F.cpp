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

const int N = 1e5+5;
int a[N], ans[N];
set<int, greater<>> b;
vector<array<int, 2>> qry[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < q; i++) {
        int l, x; cin >> l >> x;
        qry[l-1].pb({i, x});
    }
    int f = 1;
    for (int i = 0; i < n; i++) {
        for (int x : b)
            a[i] = min(a[i], x^a[i]);
        if (a[i]) b.insert(a[i]);
        else f = (2*f)%int(1e9+7);
        for (auto& [j, x] : qry[i]) {
            for (int y : b)
                x = min(x, x^y);
            ans[j] = x ? 0 : f;
        }
    }
    for (int i = 0; i < q; i++)
        cout << ans[i] << "\n";
}