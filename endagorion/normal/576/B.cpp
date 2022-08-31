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
    vi a(N);
    forn(i, N) cin >> a[i], --a[i];
    forn(i, N) {
        if (a[i] == i) {
            cout << "YES\n";
            forn(j, N) {
                if (i != j) cout << j + 1 << ' ' << i + 1 << '\n';
            }
            return 0;
        }
    }
    vvi cc;
    vi vis(N);
    bool ok = true;
    forn(i, N) {
        if (vis[i]) continue;
        vi c;
        c.pb(i);
        int j = a[i];
        vis[i] = 1;
        while (j != i) {
            c.pb(j);
            vis[j] = 1;
            j = a[j];
        }
        cc.pb(c);
        ok &= c.size() % 2 == 0;
    }
    if (ok) forn(i, cc.size()) {
        if (cc[i].size() > 2) continue;
        cout << "YES\n";
        cout << cc[i][0] + 1 << ' ' << cc[i][1] + 1 << '\n';
        forn(j, cc.size()) {
            if (j == i) continue;
            forn(k, cc[j].size()) {
                cout << cc[j][k] + 1 << ' ' << cc[i][k % 2] + 1 << '\n';
            }
        }
        return 0;
    }
    cout << "NO\n";

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}