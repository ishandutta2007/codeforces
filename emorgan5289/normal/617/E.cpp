#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const ll maxn = (1<<20) + 5;
ll n, s, out = 0;
ll a[maxn], p[maxn], f1[maxn], f2[maxn], res[maxn];
array<ll, 3> q[maxn];

bool cmp(array<ll, 3>& x, array<ll, 3>& y) {
    return x[0]/s == y[0]/s ? x[1] < y[1] : x[0] < y[0];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll m, k; cin >> n >> m >> k;
    s = sqrt(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[i] = a[i] ^ (i == 0 ? 0 : p[i-1]);
    }
    for (int i = 0; i < m; i++) {
        cin >> q[i][0] >> q[i][1]; q[i][2] = i;
    }
    sort(q, q+m, cmp);
    ll x = 0, y = -1;
    for (ll t = 0; t < m; t++) {
        auto [l, r, i] = q[t]; l--, r--;
        while (x > l) {
            x--;
            f1[p[x]]++; f2[(x == 0 ? 0 : p[x-1])]++;
            out += f1[(x == 0 ? 0 : p[x-1])^k];
        }
        while (x < l) {
            out -= f1[(x == 0 ? 0 : p[x-1])^k];
            f1[p[x]]--; f2[(x == 0 ? 0 : p[x-1])]--;
            x++;
        }
        while (y < r) {
            y++;
            f1[p[y]]++; f2[(y == 0 ? 0 : p[y-1])]++;
            out += f2[p[y]^k];
            // debug((y == 0 ? 0 : p[y-1]), f2[p[y]^k], out);
        }
        while (y > r) {
            out -= f2[p[y]^k];
            f1[p[y]]--; f2[(y == 0 ? 0 : p[y-1])]--;
            y--;
        }
        // debug(x, y);
        res[i] = out;
        // debug(out);
    }
    for (int i = 0; i < m; i++)
        cout << res[i] << "\n";
}