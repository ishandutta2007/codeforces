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

const int maxn = 110000;
int par[maxn], vis[maxn];
i64 s[maxn];
int l[maxn], r[maxn];
multiset<i64> sums;

int root(int x) {
    if (x == par[x]) return x;
    return par[x] = root(par[x]);
}

void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return;
    par[x] = y;
    sums.erase(sums.find(s[x]));
    s[y] += s[x];
    uin(l[y], l[x]);
    uax(r[y], r[x]);
    sums.insert(s[y]);
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
    vi a(n);
    forn(i, n) cin >> a[i];
    vi p(n);
    forn(i, n) cin >> p[i], --p[i];
    forn(i, n) par[i] = i, s[i] = a[i], l[i] = i, r[i] = i + 1;
    sums.insert(0);
    vi64 ans(n);
    ford(i, n) {
        ans[i] = *sums.rbegin();
        int x = p[i];
        vis[x] = 1;
        sums.insert(a[x]);
        if (x && vis[x - 1]) unite(x, x - 1);
        if (x + 1 < n && vis[x + 1]) unite(x, x + 1);
    }
    for (i64 x: ans) cout << x << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}