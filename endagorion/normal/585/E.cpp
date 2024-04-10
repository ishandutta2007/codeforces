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

const int maxa = 10000000, maxn = 500001;
const i64 P = 1000000000 + 7;
int cnt[maxa + 1], cntdiv[maxa + 1], cntmul[maxa + 1], cop[maxa + 1];
int p2[maxa + 1];
int mu[maxa + 1];

void add(int &x, int y) {
    x += y;
    if (x < 0) x += P;
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
    p2[0] = 1;
    for1(i, n) p2[i] = p2[i - 1] * 2 % P;

    forn(i, n) {
        int x;
        cin >> x;
        ++cnt[x];
    }
/*    for1(i, maxa) {
        int ub = maxa / i;
//        if (!cnt[i]) continue;
        fore(j, 1, ub) cntdiv[i * j] += cnt[i];
    }*/

    for1(i, maxa) {
        int ub = maxa / i;
        for1(j, ub) cntmul[i] += cnt[i * j];
    }

    for1(i, maxa) cntdiv[i] = p2[cntmul[i]] - 1;
    for (int i = maxa; i >= 1; --i) {
        int ub = maxa / i;
        if (!cntdiv[i]) continue;
        fore(j, 2, ub) add(cntdiv[i], -cntdiv[i * j]);
    }

    mu[1] = 1;
    for1(i, maxa) {
        int ub = maxa / i;
        if (!mu[i]) continue;
        fore(j, 2, ub) mu[i * j] -= mu[i];
    }

    for1(i, maxa) {
        int ub = maxa / i;
        int add = mu[i] * cntmul[i];
        if (!add) continue;
        for1(j, ub) cop[i * j] += add;
    }

//    for1(i, maxa) if (cntdiv[i]) cerr << i << ' ' << cntdiv[i] << ' ' << cop[i] << '\n';


    i64 ans = 0;
    fore(d, 2, maxa) (ans += 1LL * cop[d] * cntdiv[d]) %= P;
    if (ans < 0) ans += P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}