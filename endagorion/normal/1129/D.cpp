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

const i64 P = 998244353;

const int maxn = 110000, BL = 100, BC = maxn / BL + 1;
int INF = 1e8;
int a[maxn], last[maxn][2];
int mul[maxn];
int bord[BC], lazy[BC], ptr[BC];
i64 bsum[BC];
i64 dp[maxn];
vector<pii> sortv[BC];

int K;
int B;

i64 ans = 0;

void rebuild(int bi) {
//    cerr << "rebuild " << bi << ' ' << bsum[bi] << "\n";
    (ans -= bsum[bi]) %= P;
    sortv[bi] = {{-2 * INF, 0}};
    int L = bord[bi], R = bord[bi + 1];
    vi ord(R - L);
    iota(all(ord), L);
    sort(all(ord), [&](int i, int j){return mul[i] < mul[j];});
    fore(i, L, R - 1) mul[i] += lazy[bi];
    lazy[bi] = 0;
    for (int i: ord) {
        if (mul[i] > sortv[bi].back().fi) sortv[bi].pb({mul[i], 0});
        (sortv[bi].back().se += dp[i]) %= P;
    }
    sortv[bi].pb({2 * INF, 0});
    bsum[bi] = 0;
    ptr[bi] = 0;
    while (sortv[bi][ptr[bi]].fi <= K) {
        (bsum[bi] += sortv[bi][ptr[bi]].se) %= P;
        ++ptr[bi];
    }
    (ans += bsum[bi]) %= P;
//    cerr << "/rebuild " << bi << ' ' << bsum[bi] << "\n";
}

void move_ptr(int bi) {
//    cerr << "move " << bi << ' ' << bsum[bi] << "\n";
    (ans -= bsum[bi]) %= P;
    auto &sv = sortv[bi];
    while (sv[ptr[bi]].fi + lazy[bi] <= K) {
        (bsum[bi] += sv[ptr[bi]].se) %= P;
        ++ptr[bi];
    }
    while (ptr[bi] && sv[ptr[bi] - 1].fi + lazy[bi] > K) {
        --ptr[bi];
        (bsum[bi] -= sv[ptr[bi]].se) %= P;
    }
    (ans += bsum[bi]) %= P;
//    cerr << "/move " << bi << ' ' << bsum[bi] << "\n";
}

void add_seg(int L, int R, int delta) { 
//    cerr << "+ " << L << ' ' << R << ' ' << delta << '\n';
    forn(i, B) {
        int bl = bord[i], br = bord[i + 1];
        if (max(L, bl) >= min(R, br)) continue;
        if (L <= bl && br <= R) {
            lazy[i] += delta;
            move_ptr(i);
        } else {
            fore(j, max(L, bl), min(R, br) - 1) mul[j] += delta;
            rebuild(i);
        }
    }
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
    cin >> n >> K;
    forn(i, n) cin >> a[i], --a[i];
    forn(i, n) forn(z, 2) last[i][z] = -1;

    forn(i, n + 1) mul[i] = INF;
    mul[0] = 0;

    while (B * BL < n + 1) {
        ++B;
        bord[B] = min(B * BL, n + 1);
    }
    dp[0] = 1;
    forn(bi, B) rebuild(bi);
    forn(i, n) {
        int x = a[i];
        add_seg(last[x][0] + 1, i + 1, 1);
        add_seg(last[x][1] + 1, last[x][0] + 1, -1);
        dp[i + 1] = ans;

/*        cerr << i + 1 << ' ' << ans << '\n';
        forn(j, n) cerr << mul[j] + lazy[j / BL] << ' ';
        cerr << '\n';*/
        //add_seg(i + 1, i + 2, -INF);
        mul[i + 1] = 0;
        rebuild((i + 1) / BL);
        last[x][1] = last[x][0];
        last[x][0] = i;
    }

    i64 res = dp[n];
    if (res < 0) res += P;
    cout << res << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}