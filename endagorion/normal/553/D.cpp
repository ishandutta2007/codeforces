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
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

struct TRat {
    int a, b;

    bool operator<(const TRat &r) const {
        return 1LL * a * r.b < 1LL * b * r.a;
    }

    bool operator==(const TRat &r) const {
        return !(*this < r) && !(r < *this);
    }
};

const int MAXN = 150000;

vi e[MAXN];
int s[MAXN], cnt[MAXN], dead[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N, M, K;
    cin >> N >> M >> K;
    forn(i, K) {
        int x;
        cin >> x;
        --x;
        s[x] = 1;
    }

    forn(i, M) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        e[x].pb(y);
        e[y].pb(x);
    }
    forn(i, N) {
        if (s[i]) continue;
        for (int u: e[i]) ++cnt[u];
    }
    set<pair<TRat, int> > q;
    TRat best = {0, 1};
    forn(i, N) {
        if (s[i]) continue;
        q.insert(mp(TRat({cnt[i], (int)e[i].size()}), i));
    }

    while (!q.empty()) {
        uax(best, q.begin()->fi);
        int v = q.begin()->se;
        q.erase(q.begin());
        dead[v] = 1;
        for (int u: e[v]) {
            if (s[u] || dead[u]) continue;
            q.erase(mp(TRat({cnt[u], (int)e[u].size()}), u));
            --cnt[u];
            q.insert(mp(TRat({cnt[u], (int)e[u].size()}), u));
        }
    }

    forn(i, N) dead[i] = cnt[i] = 0;
    forn(i, N) {
        if (s[i]) continue;
        for (int u: e[i]) ++cnt[u];
    }
    forn(i, N) {
        if (s[i]) continue;
        q.insert(mp(TRat({cnt[i], (int)e[i].size()}), i));
    }

    vi ans;
    while (!q.empty()) {
        if (q.begin()->fi == best) {
            forn(i, N) {
                if (!s[i] && !dead[i]) ans.pb(i + 1);
            }
            break;
        }
        int v = q.begin()->se;
        q.erase(q.begin());
        dead[v] = 1;
        for (int u: e[v]) {
            if (s[u] || dead[u]) continue;
            q.erase(mp(TRat({cnt[u], (int)e[u].size()}), u));
            --cnt[u];
            q.insert(mp(TRat({cnt[u], (int)e[u].size()}), u));
        }
    }
    cout << ans.size() << '\n';
    for (int x: ans) cout << x << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}