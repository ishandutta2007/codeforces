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

int n, k, a, m;
set<pair<int, int> > s;
int cnt;

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    cin >> n >> k >> a >> m;
    s.insert(mp(1, n + 1));
    cnt += (n + 1) / (a + 1);
    for (int i = 1; i <= m; i++) {
        int x;
        scanf("%d", &x);
        set<pair<int, int> > ::iterator rr = s.upper_bound(mp(x, INF));
        if (rr == s.begin()) {
            continue;
        }
        pair<int, int> cur = *(--rr);
        if (cur.sc <= x) {
            continue;
        }
        cnt -= (cur.sc - cur.fs + 1) / (a + 1);
        cnt += (x - cur.fs + 1) / (a + 1);
        cnt += (cur.sc - x) / (a + 1);
        s.erase(cur);
        if (x > cur.fs) s.insert(mp(cur.fs, x));
        if (cur.sc > x + 1) s.insert(mp(x + 1, cur.sc));
        if (cnt < k) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1;
    return 0;
}