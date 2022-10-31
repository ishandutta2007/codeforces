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
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 2e5 + 100;

int n, m;
vector<int> x;
vector<int> x2;
vector<pair<int, int> > x3;

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        x.pb(a);
        x2.pb(a);
        x3.eb(a, i + 1);
    }
    sort(all(x));
    sort(all(x3));
    for (int i = 0; i < m; i++) {
        int cur, l;
        scanf("%d%d", &cur, &l);
        cur--;
        cur = (int) (lower_bound(all(x), x2[cur]) - x.begin());
        int ncur = (int) (upper_bound(all(x), x[cur] + l) - x.begin()) - 1;
        l -= x[ncur] - x[cur];
        cur = ncur;
        for (int j = 0; ; ) {
            int nxt = 0;
            if (j & 1) {
                nxt = (int) (upper_bound(all(x), x[cur] + l) - x.begin()) - 1;
            } else {
                nxt = (int) (lower_bound(all(x), x[cur] - l) - x.begin());
            }
            if (nxt == cur) {
                printf("%d\n", x3[(int) (lower_bound(all(x3), mp(x[cur], 0)) - x3.begin())].sc);
                break;
            } else {
                int cnt = l / abs(x[cur] - x[nxt]);
                l = l - cnt * abs(x[cur] - x[nxt]);
                j += cnt;
                if (cnt & 1) {
                    cur = nxt;
                }
            }
        }
    }
    return 0;
}