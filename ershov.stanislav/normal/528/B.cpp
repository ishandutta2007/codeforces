#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back

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

using namespace std;

int n;
int mx[555555];
vector<pair<ll, ll> > p;
set<int> coords;
vector<int> crds;

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, w;
        scanf("%d%d", &x, &w);
        p.pb(mp(x - w, x + w));
        coords.insert(x - w);
        coords.insert(x + w);
    }
    for (auto i : coords) {
        crds.pb(i);
    }
    for (int i = 0; i < n; i++) {
        int nl, nr;
        nl = (int) (lower_bound(all(crds), p[i].fs) - crds.begin());
        nr = (int) (lower_bound(all(crds), p[i].sc) - crds.begin());
        p[i] = mp(nr, nl);
    }
    sort(all(p));
//    for (int i = 0; i < n; i++) {
//        cout << p[i].sc << ' ' << p[i].fs << endl;
//    }
    int ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
        while (j < p[i].fs) {
            mx[j + 1] = mx[j];
            j++;
        }
        mx[p[i].fs] = max(mx[p[i].fs], mx[p[i].sc] + 1);
        ans = max(ans, mx[p[i].fs]);
    }
    cout << ans;
    return 0;
}