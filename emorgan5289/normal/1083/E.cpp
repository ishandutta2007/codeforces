#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ull 1000000000000000000
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#pragma GCC optimize ("O3")
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
ifstream fin("../../input.in");
#define cin fin
#endif

tuple<ll, ll, ll> b[1000005];
#define slope(j) float(s-c[c.size()-j][1])/(x-c[c.size()-j][0])
#define delta(i, j) float(c[i][1]-c[j][1])/(c[i][0]-c[j][0])

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; fin >> n;
    for (int i = 0; i < n; i++) {
        ll x, y, a; fin >> x >> y >> a;
        b[i] = {x, y, a};
    }
    sort(b, b+n);
    vector<array<ll, 2>> c = {{0, 0}};
    for (int i = 0; i < n; i++) {
        ll x, y, a; tie(x, y, a) = b[i];

        ll l = 0, r = c.size()-1;
        while (l < r) {
            ll m = (l+r)/2;
            ll d = (m == c.size()-1 ? 0 : delta(m, m+1));
            if (d < y) r = m;
            else l = m+1;
        }
        ll s = c[l][1] + y*(x-c[l][0]) - a;

        if (c.size() && s < c.back()[1]) continue;
        while (c.size() > 1 && slope(1) >= slope(2))
            c.pop_back();
        c.push_back({x, s});
        debug(x, y, a);
        debug(c);
    }

    cout << c.back()[1] << "\n";
}