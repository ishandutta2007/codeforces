#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

void change(map<int, int> &h, int x, int delta) {
    h[x] += delta;
    if (h[x] == 0) h.erase(x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif
    
    int n;
    cin >> n;
    i64 v0 = 0;
    map<int, int> lh = {{0, 0}}, rh = {{0, 0}};
    int lazyl = 0, lazyr = 0;
    map<int, vi> evs;
    forn(i, n) {
        int x, y;
        cin >> x >> y;
        evs[x + y].pb(x);
    }
    int px = 0;
    for (auto &[s, v]: evs) {
        int delta = s - px;
        lazyr += delta;
/*        cerr << s << ":\n";
        cerr << v0 << '\n';
        cerr << "L\n";
        for (auto [x, v]: lh) cerr << x + lazyl << ' ' << v << '\n';
        cerr << "R\n";
        for (auto [x, v]: rh) cerr << x + lazyr << ' ' << v << '\n';*/
        for (int x: v) {
            if (x <= lh.rbegin()->fi + lazyl) {
                change(lh, x - lazyl, 2);
                int lx = lh.rbegin()->fi + lazyl;
                v0 += abs(x - lx);
                change(lh, lx - lazyl, -1);
                change(rh, lx - lazyr, 1);
            } else if (x >= rh.begin()->fi + lazyr) {
                change(rh, x - lazyr, 2);
                int rx = rh.begin()->fi + lazyr;
                v0 += abs(x - rx);
                change(rh, rx - lazyr, -1);
                change(lh, rx - lazyl, 1);
            } else {
                change(lh, x - lazyl, 1);
                change(rh, x - lazyr, 1);
            }
        }
        px = s;
    }
    cout << v0<< '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}