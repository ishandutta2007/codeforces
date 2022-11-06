#include <bits/stdc++.h>
using namespace std;

// #define int long long
// #define double long double

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int ms = 1e6+5;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

int can[ms];
int sum[ms];
int divisors[ms];

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie();
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j += i) {
            divisors[j]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        // can[i] = divisors[i];
        // for(int k = 1; k <= i; k++) if(i%k == 0) can[i]++;
        can[i] = (divisors[i] + sum[i-1]) % mod;
        sum[i] = (can[i] + sum[i-1]) % mod;
        // for(int k = 1; k < i; k++) {
        //     can[i] = (can[i] + can[k])%mod;
        // }
        // ans = (ans + n/i) % mod;
    }
    // cout << can[n] << endl;
    cout << can[n] << endl;
    // cout << ans << endl;
    return 0;
}