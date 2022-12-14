#include <bits/stdc++.h>

using namespace std;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

const int kM = 24;

void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &x : a) cin >> x;

    array<int, 1 << kM> zeta = {};
    for (auto &s : a) {
        zeta[1 << (s[0] - 'a')]++;
        zeta[1 << (s[1] - 'a')]++;
        zeta[1 << (s[2] - 'a')]++;

        zeta[1 << (s[0] - 'a') | 1 << (s[1] - 'a')]--;
        zeta[1 << (s[0] - 'a') | 1 << (s[2] - 'a')]--;
        zeta[1 << (s[1] - 'a') | 1 << (s[2] - 'a')]--;

        zeta[1 << (s[0] - 'a') | 1 << (s[1] - 'a') | 1 << (s[2] - 'a')]++;
    }

    for (int i = 0; i < kM; i++) {
        for (int msk = 0; msk < 1 << kM; msk++) if (msk >> i & 1) {
            zeta[msk] += zeta[msk ^ (1 << i)];
        }
    }

    int ans = 0;
    for (int msk = 0; msk < 1 << kM; msk++) {
        ans ^= zeta[msk] * zeta[msk];
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}