#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash
#define rank _rank

#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int MOD = 1e9 + 7;

ll power(ll a, ll p) {
    ll ans = 1;
    while (p) {
        if (p & 1) {
            ans = ans * a % MOD;
        }
        p >>= 1;
        a = (a * a) % MOD;
    }
    return ans;
}

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif
    ll ans = 0;
    ll sub = 0, add = 1;
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        ans = (ans + add) % MOD;
        add = (add * 2) % MOD;
    }
    sub = 2;
    ll d = n + 1;
    for (int i = n + 1; i <= 2 * n; i++) {
        ans = (ans + add - sub) % MOD;
        ans += MOD;
        ans %= MOD;
        add = add * 2 % MOD;
        sub = sub * 2 % MOD;
        sub = (sub + 2 * d) % MOD;
        d = (d * (i + 1) % MOD) * power(i + 1 - n, MOD - 2) % MOD;
    }
    cout << ans << endl;
    return 0;
}