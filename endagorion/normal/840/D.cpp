#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
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
typedef pair<i64, i64> pi64;
typedef double ld;
typedef unsigned long long ui64;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 310000, TRIES = 80;
int a[maxn];
vi levs[maxn], revs[maxn];
int qx[maxn][TRIES], ans[maxn][TRIES];
int l[maxn], r[maxn], k[maxn];
int bq = 0;

int cnt[maxn];

ui64 seed = 0;

ui64 nxt() {
    seed ^= ui64(102938711);
    seed *= ui64(109293);
    seed ^= seed >> 13;
    seed += ui64(1357900102873);
//    cerr << seed << '\n';
    return seed;
}

int uniform(int n) {
    return nxt() % n;
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
    forn(i, q) {
        cin >> l[i] >> r[i] >> k[i];
//        scanf("%d%d%d", &l[i], &r[i], &k[i]);
        --l[i];
        levs[l[i]].pb(i);
        revs[r[i]].pb(i);
        forn(j, TRIES) qx[i][j] = a[l[i] + uniform(r[i] - l[i])];
    }

    forn(i, n) {
        ++cnt[a[i]];
        for (int q: levs[i + 1]) forn(j, TRIES) ans[q][j] -= cnt[qx[q][j]];
        for (int q: revs[i + 1]) forn(j, TRIES) ans[q][j] += cnt[qx[q][j]];
    }

    forn(i, q) {
        int x = 1e9;
        int len = r[i] - l[i];
        forn(j, TRIES) {
            if (ans[i][j] * k[i] > len) uin(x, qx[i][j]);
        }
        if (x > 1e8) x = -1;
        cout << x << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}