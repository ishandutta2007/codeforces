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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, w;
    cin >> n >> w;
    vi64 dans(w + 1);
    forn(i, n) {
        int l;
        cin >> l;
        vi64 a(l);
        forn(j, l) cin >> a[j];
        if (2 * l <= w) {
            vi64 pmx(l + 1, 0), smx(l + 1, 0);
            forn(j, l) pmx[j + 1] = max(pmx[j], a[j]);
            forn(j, l) smx[j + 1] = max(smx[j], a[l - j - 1]);
            forn(j, l) {
                dans[j] += pmx[j + 1] - pmx[j];
                dans[w - j] -= smx[j + 1] - smx[j];
            }
        } else {
            vi64 R(w - l + 1), L, Rm(w - l + 2), Lm{-(i64)1e18};
            Rm[0] = -1e18;
            int B = 0, A = -(w - l + 1);
            vi64 wmx(w + 1);
            forn(i, w) {
                {
                    i64 nx = B < l ? a[B] : 0LL;
                    L.pb(nx);
                    i64 z = Lm.back();
                    Lm.pb(max(nx, z));
                }
                ++B;
                {
                    if (R.empty()) {
                        while (!L.empty()) {
                            i64 x = L.back();
                            L.pop_back();
                            Lm.pop_back();
                            R.pb(x);
                            i64 z = Rm.back();
                            Rm.pb(max(x, z));
                        }
                    }
                    R.pop_back();
                    Rm.pop_back();
                }
                ++A;
//                cerr << i << ' ' << Lm.back() << ' ' << Rm.back() << '\n';
                wmx[i + 1] = max(Lm.back(), Rm.back());
            }
//            forn(i, w + 1) cerr << wmx[i] << ' ';
//            cerr << '\n';
            forn(i, w) dans[i] += wmx[i + 1] - wmx[i];
        }
    }
    i64 sum = 0;
    forn(i, w) {
        sum += dans[i];
        cout << sum << ' ';
    }
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}