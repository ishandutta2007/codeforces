#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 1, mod = 1e9 + 7;
int s[N], pow2[N];

void solve() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;

        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                s[i]++;
                if (i * i != x) s[x / i]++;
            }
        }
    }

    pow2[0] = 1;
    for (int i = 0; i < N - 1; i++) {
        pow2[i + 1] = pow2[i] << 1;
        if (pow2[i + 1] >= mod) pow2[i + 1] -= mod;
    }

    int ans = 0;
    for (int i = 1; i < N; i++) {
        int e = 0, x = i;
        for (int j = 2; j * j <= x; j++) {
            if (x % j == 0) {
                x /= j;

                if (x % j == 0) {
                    e = -1;
                    break;
                }

                e++;
            }
        }

        if (~e) {
            if (x != 1) e++;

            if (e & 1) {
                ans -= pow2[s[i]] - 1;
                if (ans < 0) ans += mod;
            } else {
                ans += pow2[s[i]] - 1;
                if (ans >= mod) ans -= mod;
            }
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}