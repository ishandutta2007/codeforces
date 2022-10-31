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

int n, m, ans[N];
pair<ll, int> a[N];
pair<ll, ll> segm1[N];
vector<pair<pair<ll, ll>, int > > segm;

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf(LLD" "LLD, &segm1[i].fs, &segm1[i].sc);
        if (i > 0) {
            segm.eb(mp(segm1[i].sc - segm1[i - 1].fs, segm1[i].fs - segm1[i - 1].sc), i);
        }
    }
    for (int i = 0; i < m; i++) {
        scanf(LLD, &a[i].fs);
        a[i].sc = i + 1;
    }
    sort(all(segm));
    sort(a, a + m);
    multiset<pair<ll, int> > magic;
    for (int i = 0, j = 0; i < n - 1; i++) {
        while (j < m && a[j].fs <= segm[i].fs.fs) {
            magic.insert(a[j]);
            j++;
        }
        multiset<pair<ll, int> >::iterator jj = magic.lower_bound(mp(segm[i].fs.sc, 0));
        if (jj == magic.end()) {
            cout << "No" << endl;
            return 0;
        } else {
            ans[segm[i].sc] = jj->sc;
            magic.erase(jj);
        }
    }
    cout << "Yes\n";
    for (int i = 1; i < n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}