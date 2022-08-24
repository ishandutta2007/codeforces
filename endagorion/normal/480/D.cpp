#include <iostream>
#include <vector>
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
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

struct TBox {
    int in, out, w, s, v;
    int id;

    TBox(int in = 0, int out = 0, int w = 0, int s = 0, int v = 0, int id = 0)
        : in(in)
        , out(out)
        , w(w)
        , s(s)
        , v(v)
        , id(id)
    {
    }
};

TBox allb[1000];
vector<TBox> byFin[2000];

int dp[1001][1001];
int mem[1001][1001];

int getDp(int id, int S) {
    if (S < 0) return -1e9;
    if (dp[id][S] != -1) return dp[id][S];
    int &res = dp[id][S];
    TBox &b = allb[id];
    //dp[id][b.in] = 0;
    mem[id][b.in] = 0;
    for (int t = b.in + 1; t <= b.out; ++t) {
        mem[id][t] = mem[id][t - 1];
        for (TBox &bb: byFin[t]) {
            if (bb.id == b.id) continue;
            if (bb.in < b.in) continue;
            int res = mem[id][bb.in] + bb.v + getDp(bb.id, min(S - bb.w, bb.s));
            mem[id][t] = max(mem[id][t], res);
        }
    }
    return res = mem[id][b.out];
}

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N, S;
    cin >> N >> S;
    allb[0] = TBox(0, 2 * N, 0, S, 0, 0);
    byFin[2 * N].pb(allb[0]);
    forn(i, 1001) forn(j, 1001) dp[i][j] = -1;
    forn(i, N) {
        TBox &b = allb[i + 1];
        b.id = i + 1;
        cin >> b.in >> b.out >> b.w >> b.s >> b.v;
        byFin[b.out].pb(b);
    }
    cout << getDp(0, S) << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}