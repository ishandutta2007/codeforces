#include <bits/stdc++.h>

using namespace std;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

const int kM = 20;
const ll kMod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    array<int, 1 << kM> zeta = {};
    for (int x : a) zeta[x]++;
    for (int i = 0; i < kM; i++) {
        for (int msk = 0; msk < 1 << kM; msk++) if (~msk >> i & 1) {
            zeta[msk] += zeta[msk ^ (1 << i)];
        }
    }

    vector<ll> pow2(n + 1, 1);
    for (int i = 0; i < n; i++) {
        pow2[i + 1] = pow2[i] * 2 % kMod;
    }

    ll ans = 0;
    for (int msk = 0; msk < 1 << kM; msk++) {
        ans += (__builtin_parity(msk) ? -1 : 1) * pow2[zeta[msk]];
    }
    ans %= kMod;
    if (ans < 0) ans += kMod;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}