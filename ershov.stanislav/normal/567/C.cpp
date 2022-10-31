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

#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-10;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 1e5 + 100;

int n, k;
map<int, ll> dp[3];

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        if (abs(a) % k == 0) for (int j = 2; j >= 1; j--) {
            dp[j][a] += dp[j - 1][a / k];
        }
        dp[0][a]++;
    }
    ll ans = 0;
    for (auto j : dp[2]) {
        ans += j.sc;
    }
    cout << ans << endl;
    return 0;
}