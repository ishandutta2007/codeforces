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
array<int, 3> a[N];
int c[N], p[N], n, m, k;
vector<array<int, 2>> u[N];

void ev(int i, int t, int d) {
    if (u[i].empty() || u[i].back()[0] != t) u[i].pb({t, d});
    else u[i].back()[1] += d;
}

void ins(int i, int t, int d) {
    c[i] += d;
    ll y = p[i], w = 0;
    int j = i-1;
    while (j < m-1 && p[j+1] < p[i]+k) w += c[++j];
    for (ll x = y; x > y-k; x--) {
        while (i > 0 && p[i-1] >= x) w += c[--i];
        while (p[j] >= x+k) w -= c[j--];
        ev(w, t, 1), ev(w-d, t, -1);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a[2*i] = {x, 1, y};
        a[2*i+1] = {x+k, 0, y};
        p[i] = y;
    }
    sort(a, a+2*n), sort(p, p+n);
    m = unique(p, p+n)-p;
    for (int i = 0; i < 2*n; i++) {
        auto& [x, b, y] = a[i];
        ins(lower_bound(p, p+m, y)-p, x, b ? 1 : -1);
    }
    for (int i = 1; i <= n; i++) {
        ll x = 0, r = 0;
        for (int j = 0; j < u[i].size(); j++) {
            if (j > 0) r += x*(u[i][j][0]-u[i][j-1][0]);
            x += u[i][j][1];
        }
        cout << r << "\n";
    }
}