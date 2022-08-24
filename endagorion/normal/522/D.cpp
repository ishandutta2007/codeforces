#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

template<class T>
bool uin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool uax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const int MAXN = 600000;
const int INF = 1e9;

struct TQuery {
    int l, r, i;

    TQuery(int l = 0, int r = 0, int i = 0)
        : l(l)
        , r(r)
        , i(i)
    {
    }

    bool operator<(const TQuery &q) const {
        return l > q.l;
    }
};

int ans[MAXN];
int fenw[MAXN];
int a[MAXN];
TQuery qs[MAXN];

void fenw_set(int i, int x) {
    for (; i < MAXN; i |= i + 1) {
        uin(fenw[i], x);
    }
}

int fenw_get(int i) {
    int res = INF;
    for (; i >= 0; i &= i + 1, --i) {
        uin(res, fenw[i]);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N, M;
    scanf("%d%d", &N, &M);
    forn(i, N) scanf("%d", &a[i]);
    forn(i, M) scanf("%d%d", &qs[i].l, &qs[i].r), --qs[i].l, --qs[i].r, qs[i].i = i;
    sort(qs, qs + M);
    forn(i, M) ans[i] = INF;
    forn(i, MAXN) fenw[i] = INF;
    map<int, int> prv;

    int cur = 0;
    ford(i, N) {
        if (prv.count(a[i])) fenw_set(prv[a[i]], prv[a[i]] - i);
        prv[a[i]] = i;
        while (cur < M && qs[cur].l == i) {
            ans[qs[cur].i] = fenw_get(qs[cur].r);
            if (ans[qs[cur].i] == INF) ans[qs[cur].i] = -1;
            ++cur;
        }
    }
    assert(cur == M);
    forn(i, M) printf("%d\n", ans[i]);

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}