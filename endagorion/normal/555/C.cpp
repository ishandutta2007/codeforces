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

struct TSeg {
    int l, r;
    int x, y;

    TSeg(int l = 0, int r = 0, int x = 0, int y = 0)
        : l(l)
        , r(r)
        , x(x)
        , y(y)
    {
    }
    
    bool operator<(const TSeg &s) const {
        return l < s.l;
    }
};

set<TSeg> s;

void add(TSeg ss) {
    if (ss.r < ss.l) return;
    s.insert(ss);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N, Q;
    cin >> N >> Q;
    s.insert(TSeg(0, N - 1, -1, -1));
    forn(q, Q) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        --x; --y;
        swap(x, y);
        auto it = s.upper_bound(TSeg(y, 0, 0, 0));
        if (it == s.begin() || (--it)->r < y) {
            cout << 0 << '\n';
            continue;
        }
        TSeg ss = *it;
        s.erase(ss);
        if (c == 'U') {
            cout << x - ss.x << '\n';
            add(TSeg(ss.l, y - 1, ss.x, ss.y));
            add(TSeg(y + 1, ss.r, ss.x, y));
        } else {
            cout << y - ss.y << '\n';
            add(TSeg(ss.l, y - 1, x, ss.y));
            add(TSeg(y + 1, ss.r, ss.x, ss.y));
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}