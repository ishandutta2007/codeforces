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

const int MAXN = 2000;

int a[MAXN][MAXN];

bool ok(vi &v, int p = -1) {
    if (v.size() == 1) return true;
    //int u = v[0];
    int root = v[0];
    forn(i, v.size()) {
        if (a[0][v[i]] < a[0][root]) root = v[i];
    }
//    cerr << root << ' ' << v.size() << '\n';
    int u;
    forn(i, v.size()) {
        if (v[i] != root) {
            u = v[i];
            break;
        }
    }
    if (p != -1) {
        forn(i, v.size()) {
            if (a[p][v[i]] != a[p][root] + a[root][v[i]]) return false;
        }
    }
    vi vu;
    forn(i, v.size()) {
        if (v[i] == root) {
            continue;
        }
        if (a[u][v[i]] > a[u][root] + a[root][v[i]]) return false;
        if (a[u][v[i]] < a[u][root] + a[root][v[i]]) {
            vu.pb(v[i]);
            swap(v[i], v.back());
            v.pop_back();
            --i;
        }
    }
    forn(i, vu.size()) forn(j, v.size()) {
        if (a[vu[i]][v[j]] != a[vu[i]][root] + a[root][v[j]]) return false;
    }
    return ok(vu, root) && ok(v);
}

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N;
    scanf("%d", &N);
    forn(i, N) forn(j, N) scanf("%d", &a[i][j]);
    bool g = true;
    forn(i, N) {
        g &= a[i][i] == 0;
        forn(j, i) {
            g &= a[i][j] == a[j][i];
            g &= a[i][j] > 0;
        }
    }
    vi a(N);
    forn(i, N) a[i] = i;
    if (g) g &= ok(a);
    cout << (g ? "YES" : "NO") << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}