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

int n;
int l[5555], r[5555];
int x;

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", l + i, r + i);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (l[i] > x) {
            vector<int> v;
            int mn = INF;
            for (int j = i; j < n; j++) {
                mn = min(mn, r[j]);
                if (l[j] > x) {
                    v.pb(min(l[j], mn));
                }
            }
            sort(all(v));
            if (v.size() >= 2) {
                v[v.size() - 2] = max(v[v.size() - 2], x);
                ans += abs(v[v.size() - 2] - x);
                x = v[v.size() - 2];
            }
            if (x < l[i]) {
                ans += l[i] - x;
            }
            if (x > r[i]) {
                ans += x - r[i];
            }
        } else if (r[i] < x) {
            vector<int> v;
            int mx = -INF;
            for (int j = i; j < n; j++) {
                mx = max(mx, l[j]);
                if (r[j] < x) {
                    v.pb(max(r[j], mx));
                }
            }
            sort(all(v));
            reverse(all(v));
            if (v.size() >= 2) {
                v[v.size() - 2] = min(v[v.size() - 2], x);
                ans += abs(v[v.size() - 2] - x);
                x = v[v.size() - 2];
            }
            if (x < l[i]) {
                ans += l[i] - x;
            }
            if (x > r[i]) {
                ans += x - r[i];
            }
        }
    }
    cout << ans << endl;
    return 0;
}