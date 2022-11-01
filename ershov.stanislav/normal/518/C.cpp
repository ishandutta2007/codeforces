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

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef DEBUG
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif

using namespace std;

const int N = 1e5 + 100;

int n, m, k, a[N], rev[N];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        rev[a[i]] = i;
    }
    ll ans = m;
    for (int i = 0; i < m; i++) {
        int b;
        scanf("%d", &b);
        int pos = rev[b];
        if (pos != 1) {
            ans += (pos - 1) / k;
            swap(a[pos], a[pos - 1]);
            rev[a[pos]] = pos;
            rev[a[pos - 1]] = pos - 1;
        }
    }
    cout << ans << endl;
    return 0;
}