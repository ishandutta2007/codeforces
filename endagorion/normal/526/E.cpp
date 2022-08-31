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

const int MAXN = 2100000;
const int LOG = 7;
int a[MAXN], nxt[MAXN];
int up[LOG][MAXN];
int N, Q;
int m;

int lens(int i) {
    int st = i;
    int res = 0;
    ford(j, LOG) {
        while (up[j][i] < st + N) {
            i = up[j][i];
            res += (1 << j);
        }
    }
    assert(res < N);
    return res + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    scanf("%d%d", &N, &Q);
    srand(113 * N + 110092 * Q);
    forn(i, N) scanf("%d", &a[i]);
    forn(i, N) a[i + N] = a[i];
    i64 sum = 0;
    forn(i, N) sum += a[i];
    forn(i, Q) {
        i64 T;
        scanf("%I64d", &T);
        if (T >= sum) {
            cout << 1 << '\n';
            continue;
        }
        i64 S = 0;
        int j = 0;
        forn(i, 2 * N) {
            while (j < 2 * N && S + a[j] <= T) S += a[j++];
            nxt[i] = j;
            S -= a[i];
        }
        nxt[2 * N] = 2 * N;
        forn(j, 2 * N + 1) up[0][j] = nxt[j];
        for1(i, LOG - 1) forn(j, 2 * N + 1) up[i][j] = up[i - 1][up[i - 1][j]];
        m = lens(0);
        int tries = 15 * N / m;
//        cerr << i << '\n';
        int st = 0;
        forn(i, tries) {
//            int st = (rand() | ((int)rand() << 16)) % N;
            int mm = lens(st);
            st = (1LL * st * 100501 + 59) % N;
            uin(m, mm);
        }
        cout << m << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}