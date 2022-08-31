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

const int maxn = 1 << 18;
int secretp[maxn], invp[maxn];
int n;

mt19937 rng(time(0));

int lca(int u, int v) {
    while (u != v) {
        if (u > v) u /= 2;
        else v /= 2;
    }
    return u;
}

int lca3(int u, int v, int w) {
    u = invp[u]; v = invp[v]; w = invp[w];
    int a = lca(u, v), b = lca(u, w), c = lca(v, w);
    return secretp[a ^ b ^ c];
}

int qn = 0;

int query(int u, int v, int w) {
    ++qn;
#ifdef LOCAL_DEFINE
    return lca3(u, v, w);
#else
    cout << "? " << u << ' ' << v << ' ' << w << endl;
    int x;
    cin >> x;
    assert(x != -1);
    return x;
#endif
}

void answer(int v) {
    cout << "! " << v << endl;
#ifdef LOCAL_DEFINE
    assert(v == secretp[1]);
    assert(qn <= n + 420);
#endif
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;

    int h;
    cin >> h;
    n = (1 << h) - 1;
#ifdef LOCAL_DEFINE
    for1(i, n) secretp[i] = i;
    shuffle(secretp + 1, secretp + n + 1, rng);
    for1(i, n) invp[secretp[i]] = i;
#endif
    
    vector<pii> cnt(n);
    forn(i, n) cnt[i].se = i + 1;
    forn(tries, 420) {
        int u, v, w;
        while (1) {
            u = 1 + rng() % n;
            v = 1 + rng() % n;
            w = 1 + rng() % n;
            if (set<int>({u, v, w}).size() == 3) break;
        }
        ++cnt[query(u, v, w) - 1].fi;
    }
    sort(rall(cnt));
    int u = cnt[0].se, v = cnt[1].se;
//    cerr << u << ' ' << v << " v " << secretp[2] << ' ' << secretp[3] << '\n';
    for1(i, n) {
        if (i == u || i == v) continue;
        if (query(u, v, i) == i) {
            answer(i);
            break;
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}