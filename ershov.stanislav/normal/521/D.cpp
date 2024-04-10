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

const ll INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;
const int MOD = 1e9 + 7;

using namespace std;

int k, n, m;
long long a[111111], mx[111111], mxj[111111];
int typej[111111];
vector<pair<long double, int> > ans;
vector<pair<long long, int> > add[111111];

int main() {
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    scanf("%d%d%d", &k, &n, &m);
    for (int i = 1; i <= k; i++) {
        int r;
        scanf("%d", &r);
        a[i] = r;
    }
    for (int j = 0; j < n; j++) {
        int t, i, b;
        scanf("%d%d%d", &t, &i, &b);
        if (t == 1) {
            if (mx[i] < b) {
                mxj[i] = j + 1;
            }
            mx[i] = max(mx[i], (ll)b);
        } else if (t == 2) {
            add[i].pb(mp(b, j + 1));
        } else {
            ans.pb(mp(b, j + 1));
        }
        typej[j + 1] = t;
    }
    for (int i = 1; i<= k; i++) {
        if (mx[i] > a[i]) {
            add[i].pb(mp(mx[i] - a[i], mxj[i]));
        }
        sort(add[i].begin(), add[i].end());
        reverse(add[i].begin(), add[i].end());
        for (int j = 0; j < (int) add[i].size(); j++) {
//            cout << add[i][j].fs << ' ';
            ans.pb(mp(((long double) a[i] + add[i][j].fs) / a[i], add[i][j].sc));
            a[i] = a[i] + add[i][j].fs;
        }
//        cout << endl;
    }
//    cout << endl;
    vector<int> res;
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
//    for (int i = 0; i < ans.size(); i++) {
//        cout << ans[i].fs << ' ' << ans[i].sc << endl;
//    }
    for (int i = 0; i < m && i < (int) ans.size(); i++) {
        res.pb(ans[i].sc);
    }
    printf("%d\n", (int) res.size());
    vector<int> res2[3];
    for (int i = 0; i < (int) res.size(); i++) {
        res2[typej[res[i]] - 1].pb(res[i]);
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < (int) res2[i].size(); j++) {
            printf("%d ", res2[i][j]);
        }
    }
    return 0;
}