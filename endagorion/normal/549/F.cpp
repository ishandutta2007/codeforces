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

const int MAXN = 300001;
const int MAXK = 1000001;
int tt;
pii a[MAXN];
int cnt[2][MAXK], lu[2][MAXK];

void update(int t, int i) {
    if (lu[t][i] < tt) {
        lu[t][i] = tt;
        cnt[t][i] = 0;
    }
    ++cnt[t][i];
}

int get(int t, int i) {
    if (lu[t][i] < tt) {
        lu[t][i] = tt;
        cnt[t][i] = 0;
    }
    return cnt[t][i];
}

int N, K;

i64 solve(int l, int r) {
    if (r - l == 1) return 0;
    int m = (l + r) / 2;
    i64 res = solve(l, m) + solve(m, r);
    ++tt;
    int i = m - 1, j = m;
    int ls = 0, rs = 0;
    while (1) {
        if (i < l && j >= r) break;
        if (j >= r || (i >= l && a[i] < a[j])) {
            ls += a[i].fi; ls %= K;
            update(0, ls);
            int oldi = i;
            if (j > m) res += get(1, (-(ls - a[i].fi) + 2 * K) % K);
            --i;
            while (i >= l && a[i] < a[oldi]) {
                ls += a[i].fi; ls %= K;
                update(0, ls);
                if (j > m) res += get(1, (-(ls - a[oldi].fi) + 2 * K) % K);
                --i;
            }
        } else {
            rs += a[j].fi; rs %= K;
            update(1, rs);
            int oldj = j;
            if (i < m - 1) res += get(0, (-(rs - a[j].fi) + 2 * K) % K);
            ++j;
            while (j < r && a[j] < a[oldj]) {
                rs += a[j].fi; rs %= K;
                update(1, rs);
                if (i < m - 1) res += get(0, (-(rs - a[oldj].fi) + 2 * K) % K);
                ++j;
            }
        }
    }
    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> N >> K;
    forn(i, N) cin >> a[i].fi, a[i].se = i;
    tt = 0;
    cout << solve(0, N) << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}