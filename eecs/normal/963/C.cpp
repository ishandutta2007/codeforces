#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef __int128 i128;
const int maxn = 200010;
int n, ans;
ll g, a[maxn], b[maxn], c[maxn];
set<ll> S1, S2;
vector<ll> V1, V2;
map<pair<ll, ll>, ll> mp;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld %lld", &a[i], &b[i], &c[i]);
        g = __gcd(g, c[i]);
        S1.insert(a[i]), S2.insert(b[i]);
        mp[{a[i], b[i]}] = c[i];
    }
    for (ll x : S1) V1.push_back(x);
    for (ll x : S2) V2.push_back(x);
    if (1LL * V1.size() * V2.size() != n) puts("0"), exit(0);
    vector<vector<ll>> V(V1.size(), vector<ll>(V2.size()));
    for (int i = 0; i < V1.size(); i++) {
        for (int j = 0; j < V2.size(); j++) {
            V[i][j] = mp[{V1[i], V2[j]}];
        }
    }
    for (int i = 0; i + 1 < V1.size(); i++) {
        for (int j = 0; j + 1 < V2.size(); j++) {
            ll a = V[i][j], b = V[i][j + 1];
            ll c = V[i + 1][j], d = V[i + 1][j + 1];
            if ((i128)a * d != (i128)b * c) puts("0"), exit(0);
        }
    }
    for (ll i = 1; i * i <= g; i++) if (!(g % i)) {
        ans++;
        if (i * i < g) ans++;
    }
    printf("%d\n", ans);
    return 0;
}