#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <ctime>
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
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)((n) - 1); i >= 0; --i)
#define fornn(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define debugv(a) forn(i, a.size()) cerr << a[i] << ' '; cerr << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

typedef long long i64;
typedef pair<i64, i64> pi64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

typedef long double ld;

string norm(string t) {
    forn(i, t.size()) {
        if (t[i] >= 'a' && t[i] <= 'z') t[i] += 'A' - 'a';
    }
    return t;
}

map<string, pii> dp;
map<string, vector<string> > edges;

void dfs(const string &t, pii s) {
    if (dp.count(t)) return;
    dp[t] = s;
    if (edges.count(t)) for (auto x: edges[t]) dfs(x, s);
}

int rcount(const string &s) {
    int c = 0;
    forn(i, s.size()) if (s[i] == 'R') ++c;
    return c;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<string> s(N);
    forn(i, N) {
        cin >> s[i];
        s[i] = norm(s[i]);
    }
    int M;
    cin >> M;
    vector<pair<pii, string> > f;
    forn(i, M) {
        string u, v;
        cin >> u >> v;
        v = norm(v);
        u = norm(u);
        edges[v].pb(u);
        f.pb(mp(mp(rcount(v), v.size()), v));
    }
    sort(all(f));
    for (auto x: f) {
        dfs(x.second, x.first);
    }
    i64 a = 0, b = 0;
    forn(i, N) {
        pii l = dp.count(s[i]) ? dp[s[i]] : mp(rcount(s[i]), (int)s[i].size());
        l = min(l, mp(rcount(s[i]), (int)s[i].size()));
        a += l.first;
        b += l.second;
    }
    cout << a << ' ' << b << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}