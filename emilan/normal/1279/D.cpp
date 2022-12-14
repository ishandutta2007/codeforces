#include <bits/stdc++.h>

using namespace std;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

const int kA = 1e6;
const int kMod = 998244353;

template <typename T>
T mod_inv(T x, T mod = kMod) {
    T y = mod, xs = 1, ys = 0;
    while (y > 0) {
        T q = x / y, tmp;
        tmp = x - q * y, x = y, y = tmp;
        tmp = xs - q * ys, xs = ys, ys = tmp;
    }
    return xs < 0 ? xs + mod : xs;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for (auto &v : a) {
        int m;
        cin >> m;
        v.resize(m);
        for (auto &x : v) cin >> x;
    }

    array<ll, kA + 1> item_prob = {};
    array<int, kA + 1> item_freq = {};
    for (auto &v : a) {
        for (int x : v) {
            item_prob[x] = (item_prob[x]
                    + mod_inv(ll(n) * SZ(v) % kMod)) % kMod;
            item_freq[x]++;
        }
    }

    ll ans = 0;
    for (int x = 1; x <= kA; x++) if (item_freq[x] > 0) {
        ans = (ans + item_prob[x] * item_freq[x]) % kMod;
    }
    ans = ans * mod_inv(n) % kMod;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}