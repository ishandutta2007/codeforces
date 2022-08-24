#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

int nex[200000];

struct TQ {
    int l, r;
    int x;

    TQ(int l = 0, int r = 0, int x = 0)
        : l(l)
        , r(r)
        , x(x)
    {
    }
};

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    nex[0] = 0;
    for (int i = 1; i < 200000; ++i) {
        nex[i] = nex[i - 1] + ((i & (i - 1)) ? 1 : 2);
    }
    int N, M;
    cin >> N >> M;
    vector< vector<TQ> > add(N + 1);
    forn(i, M) {
        int t;
        cin >> t;
        if (t == 1) {
            int lev, l, r, x;
            cin >> lev >> l >> r >> x;
            add[lev].pb(TQ(l, r, x));
        } else {
            int lev, p;
            cin >> lev >> p;
            int l = p, r = p;
            set<int> s;
            while (lev <= N) {
                forn(i, add[lev].size()) {
                    if (!(l > add[lev][i].r || add[lev][i].l > r)) {
                        s.insert(add[lev][i].x);
                    }
                }
                ++lev;
                r = nex[r];
                l = nex[l - 1] + 1;
            }
            cout << s.size() << '\n';
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}