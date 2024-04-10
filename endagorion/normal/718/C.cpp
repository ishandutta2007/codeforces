#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
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

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const i64 P = 1000000000 + 7;

struct TM {
    i64 a, b, c, d;

    void norm() {
        a %= P; b %= P; c %= P; d %= P;
    }

    TM(i64 _a = 0, i64 _b = 0, i64 _c = 0, i64 _d = 0)
        : a(_a)
        , b(_b)
        , c(_c)
        , d(_d)
    {
        norm();
    }

    TM operator*(const TM &m) const {
        return TM(a * m.a + b * m.c, a * m.b + b * m.d, c * m.a + d * m.c, c * m.b + d * m.d);
    }

    TM operator+(const TM &m) const {
        return TM(a + m.a, b + m.b, c + m.c, d + m.d);
    }
};

struct TNode {
    int L, R;
    int l, r;
    TM m, val;
};

TM mdeg(TM x, i64 d) {
    TM res(1, 0, 0, 1);
    while (d) {
        if (d & 1) res = res * x;
        x = x * x;
        d /= 2;
    }
    return res;
}

const int MAXN = 210000, MAXT = 210000;
TNode t[MAXT];
int tc = 0;
i64 a[MAXN];

int buildTree(int L, int R) {
    int n = tc++;
    t[n].L = L;
    t[n].R = R;
    t[n].val = TM(1, 0, 0, 1);
    if (R - L == 1) {
        t[n].m = mdeg(TM(1, 1, 1, 0), a[L]);
    } else {
        int M = (L + R) / 2;
        t[n].l = buildTree(L, M);
        t[n].r = buildTree(M, R);
        t[n].m = t[t[n].l].m + t[t[n].r].m;
    }
    return n;
}
                    
void mul(int n, int L, int R, TM m) {
    if (L <= t[n].L && t[n].R <= R) {
        t[n].val = t[n].val * m;
        t[n].m = t[n].m * m;
        return;
    }
    if (max(L, t[n].L) >= min(R, t[n].R)) return;
    mul(t[n].l, L, R, m);
    mul(t[n].r, L, R, m);
    t[n].m = (t[t[n].l].m + t[t[n].r].m) * t[n].val;
}

TM sum(int n, int L, int R) {
    if (L <= t[n].L && t[n].R <= R) return t[n].m;
    if (max(L, t[n].L) >= min(R, t[n].R)) return TM();
    return t[n].val * (sum(t[n].l, L, R) + sum(t[n].r, L, R));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif
    
    int n, q;
    cin >> n >> q;
    forn(i, n) cin >> a[i];
    buildTree(0, n);
    forn(i, q) {
        int tt;
        cin >> tt;
        if (tt == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            --l;
            mul(0, l, r, mdeg(TM(1, 1, 1, 0), x));
        } else {
            int l, r;
            cin >> l >> r;
            --l;
            i64 ans = sum(0, l, r).b;
            if (ans < 0) ans += P;
            cout << ans << '\n';
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}