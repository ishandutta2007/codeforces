#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li
#define err if(debug_out)cout

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2e5 + 13;
const int LOGN = 20;
const int K = 22;
const int M = 998244353;//1e9 + 7;
const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

bool dp[N], dp1[N];

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    if(n == 1) {
        cout << 0 << endl;
        return;
    }

    li ans = 0;
    li sum = 0;
    for(int i = 0; i < n; i++) {
        ans += a[i] * a[i] * (n - 2);
        ans += b[i] * b[i] * (n - 2);
        sum += a[i] + b[i];
    }

    for(int i = 0; i <= n * 100; i++) {
        dp[i] = false;
    }

    dp[0] = true;
    for(int i = 0; i < n; i++) {
        for(int j = n * 100; j >= 0; j--) {
            if(dp[j]) {
                dp1[j + a[i]] = true;
                dp1[j + b[i]] = true;
            }
        }

        for(int j = 0; j <= n * 100; j++) {
            dp[j] = dp1[j];
            dp1[j] = false;
        }
    }

    li res = INF64;
    for(int i = 0; i <= n * 100; i++) if(dp[i]) {
        res = min(res, i * 1ll * i + (sum - i) * 1ll * (sum - i));
    }

    cout << ans + res << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}