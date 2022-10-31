#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const ll INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;
const int MOD = 1e9 + 7;

using namespace std;

int n, k;
string num;

ll ck[111111], ck1[111111], sum[111111];

ll power(ll a, int p) {
    ll ans = 1;
    while (p) {
        if (p & 1) {
            ans = (ans * a) % MOD;
        }
        p >>= 1;
        a = (a * a) % MOD;
    }
    return ans;
}

int main() {
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    cin >> n >> k;
    cin >> num;
    if (k == 0) {
        for (int i = 0; i <= n+10; i++) {
            ck[i] = 1;
        }
    } else if (k == 1){
        ck1[0] = 1;
        for (int i = k; i < n+10; i++) {
            ck[i] = i;
            ck1[i] = 1;
        }
    } else {
        ck[k] = 1;
        ck1[k-1] = 1;
        for (int i = k + 1; i < n+10; i++) {
            ck[i] =( (ck[i - 1] * i )% MOD * power(i - k, MOD - 2) ) % MOD;
        }
        for (int i = k; i < n+10; i++) {
            ck1[i] =( (ck1[i - 1] * i )% MOD * power(i - k + 1, MOD - 2)) % MOD;
        }
    }
    for (int i = k-1; i < n - 2; i++) {
        ck1[i] = (ck1[i] * power(10, n - 2 - i)) % MOD;
    }
    for (int i = 1; i <= n; i++) {
        sum[i] = (sum[i - 1] + ck1[n - 1 - i]) % MOD;
    }
    ll ans = 0;
//    cout << ck1[0] << ' ' << ck1[1] << ' ' << ck1[2] << ' ' << ck1[3];
    for (int i = 0; i < n; i++) {
        ans = (ans + ( (num[i] - '0') * ck[i] ) % MOD * power(10, n - i - 1) ) % MOD;
        ans = (ans + (num[i] - '0') * sum[n - 1 - i]) % MOD;
    }
    cout << ans;
    return 0;
}