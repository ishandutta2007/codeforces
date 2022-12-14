#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

const int mod = 1e9 + 7;

int cnt[71], 
    dp[71][1 << 19],
    primes[] = {
        2, 3, 5, 7, 11, 13, 17, 19,
        23, 29, 31, 37, 41, 43, 47,
        53, 59, 61, 67
    };

ll modExp2(int e) {
    ll r = 1, b = 2;
    for (; e; e >>= 1, b = b * b % mod) {
        if (e & 1) r = r * b % mod;
    }
    return r;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    dp[0][0] = 1;
    for (int i = 1; i <= 70; i++) {
        int bits = 0;
        for (int t = i, j = 0; j < 19; j++) {
            while (t % primes[j] == 0) {
                bits ^= 1 << j;
                t /= primes[j];
            }
        }

        for (int j = 0; j < 1 << 19; j++) {
            if (!cnt[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = 
                (dp[i - 1][j] + dp[i - 1][j ^ bits]) *
                modExp2(cnt[i] - 1) % mod;
        }
    }

    cout << (dp[70][0] + mod - 1) % mod;
}