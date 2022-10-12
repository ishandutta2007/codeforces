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

const int N = 2e5+5;
int a[4][N], v[2];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            v[i/2] += a[i][j];
        }

    if (v[0] != v[1]) {
        cout << "-1\n";
        return 0;
    }

    array<vector<int>, 4> s;
    ll ans = 0;

    auto check = [&](int i, int j) {
        while (!s[i].empty() && !s[j].empty()) {
            ans += abs(s[i].back()-s[j].back())+abs(i%2-j%2);
            a[i][s[i].back()] = 0;
            a[j][s[j].back()] = 0;
            s[i].pop_back(), s[j].pop_back();
        }
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++)
            if (a[j][i]) s[j].pb(i);
        check(0, 2);
        check(1, 3);
        check(0, 3);
        check(1, 2);
    }

    cout << ans << "\n";
}