#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
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
#define mt make_tuple
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
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 210000;
vi divs[maxn + 1];
int a[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    for1(d, maxn) for1(z, maxn / d) divs[z * d].pb(d);
    int n;
    cin >> n;
    n /= 2;
    forn(i, n) cin >> a[i];

    int mx = 0;
    vi ans(2 * n + 1);
    bool ok = true;
    forn(i, n) {
        int mmx = 2e9, mmy = 2e9;
        for (int d: divs[a[i]]) {
            int dd = a[i] / d;
            if (dd <= d) break;
            if (d % 2 != dd % 2) continue;
            int x = (dd - d) / 2, y = (dd + d) / 2;
            if (x > mx && y < mmy) mmx = x, mmy = y;
        }
        if (mmx > 2e8) {
            ok = false;
            break;
        }                        
//        cerr << mx << ' ' << mmx << ' ' << mmy << '\n';
        ans[2 * i + 1] = mmx;
        ans[2 * i + 2] = mmy;
        mx = mmy;
    }
    if (ok) {
        cout << "Yes\n";
        forn(i, 2 * n) cout << 1LL * (ans[i + 1] - ans[i]) * (ans[i + 1] + ans[i]) << ' ';
        cout << '\n';
    } else cout << "No\n";

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}