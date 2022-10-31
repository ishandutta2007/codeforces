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

#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

using namespace std;

const int N = 222;

int n, f[N];
bool good[N];

long long ans = 1;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &f[i]);
    }
    for (int i = 1; i <= n; i++) {
        int len = 1, cur = f[i];
        for (; cur != i && len < 500; cur = f[cur]) {
            len++;
        }
        if (cur == i) {
            good[i] = true;
            ans = ans / gcd(ans, len) * len;
        }
    }
    int mn = 1;
    for (int i = 1; i <= n; i++) {
        int len = 0;
        for (int cur = i; !good[cur]; cur = f[cur], len++);
        mn = max(mn, len);
    }
    ll ans2 = ans;
    while (ans2 < mn) {
        ans2 += ans;
    }
    cout << ans2;
    return 0;
}