#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int phi[200105];

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll binpow(ll x, ll deg, ll m) {
    if (!deg) return 1 % m;
    if (deg & 1LL)
        return (x * binpow(x, deg - 1, m)) % m;
    x = binpow(x, deg / 2, m);
    return (x * x) % m;
}

ll solve(ll a, ll b, ll m) {
    if (!b) return 0;
    ll g = gcd(gcd(a, b), m);
    a /= g;
    b /= g;
    m /= g;
    return (b * binpow(a, phi[m] - 1, m)) % m;
}

int n, m, x, ban[200105], dp[200105], to[200105], revvd[200105];
vector<int> v[200105], vd;

int main()
{
    for (int i = 2; i < 200105; ++i)
        phi[i] = i;
    for (int i = 2; i < 200105; ++i) {
        if (phi[i] != i) continue;
        for (int j = i; j < 200105; j += i)
            phi[j] -= phi[j] / i;
    }

    cin >> n >> m;
    while (n--) {
        cin >> x;
        ban[x] = 1;
    }

    for (int i = 0; i < m; ++i) {
        if (ban[i])
            continue;
        int g = gcd(i, m);
        v[g].push_back(i);
    }
    for (int i = 0; i <= m; ++i) {
        if (v[i].size())
            vd.push_back(i), revvd[i] = vd.size() - 1;
    }

    int all_mx = 0, all_mxi = -1;
    for (int i = m; i >= 1; --i) {
        if (!v[i].size())
            continue;
        int idx = revvd[i];
        int mx = 0, mxi = -1;
        for (int j = idx + 1; j < vd.size(); ++j) {
            if (vd[j] % i)
                continue;
            if (dp[vd[j]] > mx)
                mx = dp[vd[j]], mxi = vd[j];
        }
        dp[i] = mx + v[i].size();
        to[i] = mxi;
        if (dp[i] > all_mx)
            all_mx = mx, all_mxi = i;
    }

    int cur = 1;
    int idx = all_mxi;
    vector<int> ans;
    while (idx > 0) {
        for (int j = 0; j < v[idx].size(); ++j) {
            int go = solve(cur, v[idx][j], m);
            ans.push_back(go);
            cur = v[idx][j];
        }
        idx = to[idx];
    }

    cout << ans.size() << endl;
    for (size_t i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}