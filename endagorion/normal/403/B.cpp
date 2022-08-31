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
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

int GCD(int a, int b) {
    return b == 0 ? a : GCD(b, a % b);
}

set<int> bad;

int score(int x) {
    int res = 0;
    for (int i = 2; i * i <= x; ++i) {
        while (x % i == 0) {
            x /= i;
            res += bad.count(i) ? -1 : 1;
        }
    }
    if (x > 1) res += bad.count(x) ? -1 : 1;
    return res;
}

int a[10000], sa[10001];
int g[10000], sg[10001];
int d[5001][5001];

void relax(int &x, int y) {
    x = max(x, y);
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N, M;
    cin >> N >> M;
    forn(i, N) cin >> a[i];
    forn(i, M) {
        int x;
        cin >> x;
        bad.insert(x);
    }
    forn(i, N) sa[i] = score(a[i]);
    g[0] = a[0]; sg[0] = sa[0];
    for (int i = 1; i < N; ++i) {
        g[i] = GCD(g[i - 1], a[i]);
        sg[i] = score(g[i]);
    }
    g[N] = 1;
    sg[N] = 0;
    
    forn(i, N + 1) forn(j, N + 1) d[i][j] = -1e9;
    d[N][N] = 0;
    for (int i = N; i > 0; --i) {
        for (int j = i; j <= N; ++j) {
            relax(d[i - 1][i - 1], d[i][j] + sa[i - 1] - sg[i - 1]);
            relax(d[i - 1][j], d[i][j] + sa[i - 1] - sg[j]);
        }
    }
    cout << *max_element(d[0], d[0] + N + 1) << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}