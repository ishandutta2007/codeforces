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

const int maxn = 210000;
int par[maxn], sz[maxn], vis[maxn];

int root(int v) {
    if (par[v] == v) return v;
    return par[v] = root(par[v]);
}

void unite(int v, int u) {
    v = root(v);
    u = root(u);
    if (v == u) return;
    sz[v] += sz[u];
    par[u] = v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int m;
    string s;
    cin >> m >> s;
    int n = s.size();
    vvi pos(26);
    vi cnt(26);
    forn(i, n) pos[s[i] - 'a'].pb(i), ++cnt[s[i] - 'a'];
    forn(i, n) par[i] = i, sz[i] = 1;
    ford(i, 26) {
        bool ok = true;
        for (int v: pos[i]) {
            int s = 1;
            if (v && vis[v - 1]) s += sz[root(v - 1)];
            if (v + 1 < n && vis[v + 1]) s += sz[root(v + 1)];
            if (s < m) {
                vis[v] = 1;
                --cnt[i];
                if (v && vis[v - 1]) unite(v, v - 1);
                if (v + 1 < n && vis[v + 1]) unite(v, v + 1);
            } else ok = false;
        }
        if (!ok) break;
    }                  
    forn(i, 26) cout << string(cnt[i], 'a' + i);
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}