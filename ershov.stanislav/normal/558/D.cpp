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

const int N = 1e6 + 100;

int h, q;
map<ll, int> open;

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d", &h, &q);
    if (q == 0 && h == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (q == 0 && h != 1) {
        cout << "Data not sufficient!" << endl;
        return 0;
    }
    for (int j = 0; j < q; j++) {
        int i, ans;
        ll l, r;
        scanf(" %d "LLD" "LLD" %d", &i, &l, &r, &ans);
        l -= (1ll << (i - 1));
        r -= (1ll << (i - 1));
        r++;
//        cout << l << ' ' << r << endl;
        l *= (1ll << (h - i));
        r *= (1ll << (h - i));
        if (ans) {
            open[l]++;
            open[r]--;
        } else {
            open[0]++;
            open[l]--;
            open[r]++;
            open[1ll << (h - 1)]--;
        }
    }
    ll ans = 0;
    int cur = 0;
    ll prv = -1;
    for (auto k : open) {
        if (cur == q && k.fs > prv + 1) {
            cout << "Data not sufficient!" << endl;
            return 0;
        }
        cur += k.sc;
        assert(cur <= q);
        if (cur == q) {
            if (ans) {
                cout << "Data not sufficient!" << endl;
                return 0;
            } else {
                ans = k.fs + (1ll << (h - 1));
                prv = k.fs;
            }
        }
    }
    if (ans == 0) {
        printf("Game cheated!\n");
    } else {
        printf(LLD"\n", ans);
    }
    return 0;
}