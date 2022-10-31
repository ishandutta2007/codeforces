#include<bits/stdc++.h>

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

const int N = 2e5 + 100;

ll l[N], r[N];

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        scanf(LLD, &a[i]);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        l[i + 1] = l[i] | a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        r[i] |= r[i + 1] | a[i];
    }
    for (int i = 0; i < n; i++) {
        ll cur = l[i] | r[i + 1];
        ll g = a[i];
        for (int j = 0; j < k; j++) {
            g *= x;
        }
        cur |= g;
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;
}