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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    cin >> n;
    vi64 l(n);
    forn(i, n) cin >> l[i];
    string type;
    cin >> type;

    i64 ans = 0;
    map<int, i64> buy;
    buy[1e9] = 1;
    forn(i, n) {
        if (type[i] == 'W') {
            ans += 2 * l[i];
            buy[1] += l[i];
            buy[3] = 5e18;
        } else if (type[i] == 'G') {
            i64 z = min(buy[1], l[i]);
            buy[1] -= z;
            ans += 2 * z + 3 * (l[i] - z);
            buy[2] += l[i] - z;
            buy[2] += 2 * z;
            buy[5] = 5e18;
        } else {
            ans += l[i];
            while (l[i]) {
                auto w = *buy.begin();
                i64 z = min(w.se, l[i]);
//                if (z) cerr << i << ' ' << w.fi << ' ' << z << '\n';
                ans += z * w.fi;
                l[i] -= z;
                buy[w.fi] -= z;
                if (!buy[w.fi]) buy.erase(w.fi);
            }
        }
    }

    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}