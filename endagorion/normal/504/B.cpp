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

const int MAXN = 300000;

int fenw[MAXN];
int p[MAXN], q[MAXN];
int r1[MAXN], r2[MAXN];

void add(int i, int x) {
    while (i < MAXN) {
        fenw[i] += x;
        i = i | (i + 1);
    }
}

int sum(int i) {
    int res = 0;
    while (i >= 0) {
        res += fenw[i];
        i &= i + 1; --i;
    }
    return res;
}

void perm_to_fn(int N, int *p, int *r) {
    forn(i, MAXN) fenw[i] = 0;
    ford(i, N) {
        r[N - i - 1] = sum(p[i]);
        add(p[i], 1);
    }
}

void fn_to_perm(int N, int *r1, int *p) {
    forn(i, MAXN) fenw[i] = 0;
    forn(i, N) add(i, 1);
    ford(i, N) {
        int l = -1, r = N + 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (sum(m) > r1[i]) r = m;
            else l = m;
        }
        p[N - i - 1] = r;
        add(r, -1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N;
    cin >> N;
    forn(i, N) cin >> p[i];
    forn(i, N) cin >> q[i];
    perm_to_fn(N, p, r1);
    perm_to_fn(N, q, r2);
    forn(i, N) {
        r1[i] += r2[i];
        r1[i + 1] += r1[i] / (i + 1);
        r1[i] %= i + 1;
    }
    fn_to_perm(N, r1, p);
    forn(i, N) cout << p[i] << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}