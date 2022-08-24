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

const int maxn = 1100000;
int mind[maxn + 1], rad[maxn + 1], smrad[maxn + 1], lp[maxn + 1], grlp[maxn];
int plp[maxn + 1], iplp[maxn + 1];
int byrad[maxn + 1], bygrlp[maxn + 1];

const i64 P = 1000000000 + 7;
i64 fact[maxn];
vi ps;

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

    forn(i, maxn + 1) mind[i] = i;
    rad[1] = smrad[1] = 1;
    lp[1] = grlp[1] = 1;
    byrad[1] = 1;
    bygrlp[1] = 1;
    fore(i, 2, n) {
        if (mind[i] == i) ps.pb(i);
        int j = i / mind[i];
        rad[i] = rad[j] * (j % mind[i] ? mind[i] : 1);
        lp[i] = max(mind[i], lp[j]);
        if (1LL * lp[i] * lp[i] > n) {
            grlp[i] = n / lp[i];
            smrad[i] = rad[i] / lp[i];
        } else {
            grlp[i] = 0;
            smrad[i] = rad[i];
        }
        ++byrad[rad[i]];
        if (i == mind[i] && grlp[i]) ++bygrlp[grlp[i]];

        for (int p: ps) {
            if (p > i || 1LL * p * i > maxn) break;
            mind[i * p] = p;
        }
    }

    fact[0] = 1;
    for1(i, n) fact[i] = i * fact[i - 1] % P;

    bool ok = true;
    for1(i, n) {
        int x;
        cin >> x;
        if (x == 0) continue;
        if (smrad[i] != smrad[x] || grlp[i] != grlp[x]) {
            ok = false;
            break;
        }

        --byrad[rad[i]];
        if (grlp[i]) {
            int p1 = lp[i], p2 = lp[x];
            if (plp[p1] && plp[p1] != p2) ok = false;
            if (iplp[p2] && iplp[p2] != p1) ok = false;
            if (!ok) break;
            if (!plp[p1]) --bygrlp[grlp[i]];
            plp[p1] = p2;
            iplp[p2] = p1;
        }
    }

    i64 ans = 1;
    for1(gr, n) {
//        if (bygrlp[gr]) cerr << gr << ' ' << bygrlp[gr] << '\n';
        (ans *= fact[bygrlp[gr]]) %= P;
    }
    for1(i, n) (ans *= fact[byrad[i]]) %= P;
    if (!ok) ans = 0;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}