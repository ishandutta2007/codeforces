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

const int N = 5e5 + 500, M = 5e4 + 500;
const int MAGIC = 900;

ll a[N];
int l[M], r[M], t[M], y[M], x[M], n, q;
ll add2[N];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    scanf("%d%d", &n, &q);

    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }

    for (int i = 0; i < q; i++) {
        scanf("%d", t + i);
        if (t[i] == 1) {
            scanf("%d%d%d", l + i, r + i, x + i);
        } else {
            scanf("%d", y + i);
        }
    }

    vector<int> borders;
    vector<vector<pair<ll, int> > > vv;
    vector<ll> add;

    int qq = 0;

    for (int i = 0; i < q; i++) {
        if (i % MAGIC == 0) {
            for (int j = max(i - MAGIC, 0); j < i; j++) {
                if (t[j] == 1) {
                    add2[l[j]] += x[j];
                    add2[r[j] + 1] -= x[j];
                }
            }
            for (int j = 1; j <= n; j++) {
                a[j] += add2[j];
                add2[j + 1] += add2[j];
                add2[j] = 0;
            }

            borders.clear();
            borders.pb(1);
            borders.pb(n + 1);
            for (int j = i; j < i + MAGIC && j < q; j++) {
                if (t[j] == 1) {
                    borders.pb(l[j]);
                    borders.pb(r[j] + 1);
                }
            }
            sort(all(borders));
            borders.resize(distance(borders.begin(), unique(all(borders))));
            qq = (int) borders.size();
            vv.clear();
            add.clear();
            vv.resize(qq);
            add.resize(qq);
            for (int j = 0; j < qq - 1; j++) {
                for (int k = borders[j]; k < borders[j + 1]; k++) {
                    vv[j].eb(a[k], k);
                }
                sort(all(vv[j]));
            }
        }
        if (t[i] == 2) {
            int mny = INF, mxy = -INF;
            for (int j = 0; j < qq - 1; j++) {
                int k1 = (int) (lower_bound(all(vv[j]), mp(y[i] - add[j], -INF)) - vv[j].begin());
                int k2 = (int) (upper_bound(all(vv[j]), mp(y[i] - add[j], INF)) - vv[j].begin());
                if (k1 < (int) vv[j].size() && vv[j][k1].fs == y[i] - add[j]) {
                    mny = min(mny, vv[j][k1].sc);
                    mxy = max(mxy, vv[j][k2 - 1].sc);
                }
            }
            if (mny < INF) {
                printf("%d\n", mxy - mny);
            } else {
                printf("-1\n");
            }
        } else {
            for (int j = 0; j < qq && borders[j] <= r[i]; j++) {
                if (borders[j] >= l[i]) {
                    add[j] += x[i];
                }
            }
        }
    }

    return 0;
}