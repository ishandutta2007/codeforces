#include <bits/stdc++.h>

using namespace std;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

const int kE = 20;

void solve() {
    int n, m;
    cin >> n >> m;

    array<int, kE> freq = {};
    vector<bool> vis(n + 1);
    for (int i = 2; i <= n; i++) {
        ll x = i;
        int cnt = 0;
        for (int e = 1; x <= n; e++, x *= i) if (!vis[x]) {
            vis[x] = true;
            cnt++;
        }
        freq[cnt]++;
    }

    ll ans = 1;
    int cnt = 0;
    vector<bool> sieve(m * (kE - 1) + 1);
    for (int i = 1; i < kE; i++) {
        for (int j = 1; j <= m; j++) if (!sieve[i * j]) {
            cnt++;
            sieve[i * j] = true;
        }
        ans += ll(freq[i]) * cnt;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}