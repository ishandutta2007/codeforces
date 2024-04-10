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

map<pi64, int> cache;
const i64 INF = 2e17;

i64 rgt(i64 x, int k) {
    if (!k) return x + 1;
    if (x > 10000LL) {  
        i64 add = 1;
        forn(i, k) {
            if (add > 1e14) {
                add = INF;
            }
            add *= 10000LL + 1;
        }
        return x + add;
    }
    if (k == 1) return x + min(x, 10000LL) + 1;
    i64 y = x;
    forn(j, min(10000LL, x) + 1) {
        y = rgt(y, k - 1);
        if (y > INF) return INF;
    }
    return y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;

    i64 L = 1, R = 10004205361450474 + 1;
    ford(k, 5) {
        vi64 move;
        i64 x = L;
        while (x < R) {
            x = rgt(x, k);
            if (x - 1 < R) move.pb(x - 1);
        }
        if (move.empty()) move.pb(L);
        assert(move.size() <= L && move.size() <= 10000);
        cout << move.size() << ' ';
        for (i64 x: move) cout << x << ' ';
        cout << endl;
        int ans;
        cin >> ans;
        assert(ans != -2);
        if (ans == -1) return 0;
        if (ans == 0) R = move[0];
        else if (ans == move.size()) L = move.back() + 1;
        else L = move[ans - 1] + 1, R = move[ans];
    }
    assert(false);

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}