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

int n, l, r, x;
int c[20];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    cin >> n >> l >> r >> x;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    int ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        int sum = 0, cnt = 0, mx = 0, mn = INF;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum += c[i];
                cnt++;
                mx = max(mx, c[i]);
                mn = min(mn, c[i]);
            }
        }
        if (sum >= l && sum <= r && mx - mn >= x && cnt >= 2) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}