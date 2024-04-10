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

vi e[30];
int vis[30];

vi ord;

bool dfs(int v) {
    if (vis[v] == 2) return true;
    if (vis[v] == 1) return false;
    vis[v] = 1;
    for (int u: e[v]) {
        if (!dfs(u)) return false;
    }
    vis[v] = 2;
    ord.pb(v);
    return true;
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
    vector<string> a(N);
    forn(i, N) cin >> a[i];
    bool ok = true;
    forn(i, N - 1) {
        int j = 0;
        while (j < a[i].size() && j < a[i + 1].size() && a[i + 1][j] == a[i][j]) ++j;
        if (j == a[i + 1].size() && j < a[i].size()) ok = false;
        else if (j < a[i].size() && j < a[i + 1].size()) {
            e[a[i][j] - 'a'].pb(a[i + 1][j] - 'a');
//            cerr << a[i][j] << ' ' << a[i + 1][j] << '\n';
        }
    }
    forn(i, 26) ok &= dfs(i);
    if (!ok) cout << "Impossible\n";
    else {
        reverse(all(ord));
        forn(i, 26) cout << (char)('a' + ord[i]);
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}