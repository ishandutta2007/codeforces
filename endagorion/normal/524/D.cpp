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

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N, M, T;
//    cin >> N >> M >> T;
    scanf("%d%d%d\n", &N, &M, &T);
    int ms = 0;
    vi q;
    vi id(N, -1);
    vector<vi> a(86400);
    forn(i, N) {
        int h, m, s;
        scanf("%d:%d:%d\n", &h, &m, &s);
        int t = 3600 * h + 60 * m + s;
        a[t].pb(i);
    }

    int nz = 0;
    int fs = -1;
    forn(t, 86400) {
        if (t >= T) {
            for (int x: a[t - T]) {
                --q[id[x]];
                if (q[id[x]] == 0) --nz;
            }
        }

        for (int x: a[t]) {
            if (nz < M) ++fs, q.pb(0);
            id[x] = fs;
            if (!q[fs]) ++nz;
            ++q[fs];
        }
        ms = max(ms, nz);
    }
    if (ms < M) cout << "No solution\n";
    else {
        cout << fs + 1 << '\n';
        for (int x: id) {
            cout << x + 1 << '\n';
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}