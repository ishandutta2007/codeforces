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

const int maxa = 2100000;
const i64 P = 1000000000 + 7;
int mind[maxa + 1], did2[maxa + 1];
pii mult[maxa + 1];
int cnt[maxa + 1];
vi ps;

void upd(int p, int z) {
    if (z > mult[p].fi) mult[p] = mp(z, 0);
    if (z == mult[p].fi) ++mult[p].se;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    forn(i, maxa + 1) mind[i] = i;
    fore(i, 2, maxa) {
        if (mind[i] == i) ps.pb(i);
        for (int p: ps) {
            if (p > mind[i] || 1LL * p * i > maxa) break;
            mind[i * p] = p;
        }
    }

    int n;
    cin >> n;
    forn(i, n) {
        int p;
        cin >> p;
        ++cnt[p];
    }

    int plus1 = 0;
    ford(i, maxa) {
        if (cnt[i] && !mult[i].fi) {
            upd(i, 1);
            --cnt[i];
        }
        if (cnt[i]) {
            did2[i] = 1;
            for (int j = i - 1; j > 1; ) {
                int md = mind[j], z = 0;
                while (j % md == 0) j /= md, ++z;
                upd(md, z);
            }
            --cnt[i];
        }
        if (cnt[i]) plus1 = 1;
    }

    forn(i, maxa) {
        if (!did2[i]) continue;
        bool useless = true;
        for (int j = i - 1; j > 1; ) {
            int md = mind[j], z = 0;
            while (j % md == 0) j /= md, ++z;
            if (mult[md] == mp(z, 1)) useless = false;
        }
//        cerr << i << ' ' << useless << '\n';
        if (useless) plus1 = 1;
    }

    i64 ans = 1;
    forn(i, maxa) forn(j, mult[i].fi) (ans *= i) %= P;
    cout << (ans + plus1) % P << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}