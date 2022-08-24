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
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)((n) - 1); i >= 0; --i)
#define fornn(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define debugv(a) forn(i, a.size()) cerr << a[i] << ' '; cerr << '\n'

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

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

typedef long long i64;
typedef unsigned long long u64;
typedef pair<i64, i64> pi64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

typedef long double ld;
typedef vector<ld> vld;
typedef vector<vld> vvld;

int x[2000], b[2000], p[2000];
int ans[2000];
double dist[1001][1001];
double minD[2001];

int main() {
    ios::sync_with_stdio(false);
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
#endif

    int N, L;
    cin >> N >> L;
    x[0] = b[0] = 0;
    for1(i, N) cin >> x[i] >> b[i];
    forn(i, N + 1) forn(j, N + 1) dist[i][j] = sqrt(fabs(1.0 * abs(x[j] - x[i]) - L));
    double l = 0.0, r = 1e9;
    forn(it, 100) {
        double m = 0.5 * (l + r);
        minD[0] = 0.0;
        for1(i, N) {
            minD[i] = 1e9;
            forn(j, i) {
                if (uin(minD[i], minD[j] + dist[i][j] - m * b[i])) {
                    p[i] = j;
                }
            }
        }
        if (minD[N] < 0) {
            r = m;
            forn(i, N + 1) ans[i] = p[i];
        } else {
            l = m;
        }
    }

    vi res;
    int v = N;
    while (v != 0) {
        res.pb(v);
        v = ans[v];
    }
    reverse(all(res));
    for (int x: res) cout << x << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}