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

const int len = 3, L10 = 1000;
const int maxn = 200001;
const int T = L10 * (maxn / len / 9 + 1);

char d[2][T];
bool bord[maxn];

bool get_dp(int i, int j);

bool rec(int i, int x, int s) {
    if (!x) return get_dp(i - 1, s);
    if (rec(i, 0, s + x)) return true;
    for (int p = 10; p <= x; p *= 10) if (rec(i, x / p, s + x % p)) return true;
    return false;
}

bool get_dp(int i, int j) {
    if (i == 0) return j < 10;
    if (d[i - 1][j / 9] != -1) return d[i - 1][j / 9];
    return d[i - 1][j / 9] = (rec(i, j, 0) ? 1 : 0);
}

bool restore(int i, int x, int s, vi &v) {
    if (i == 0) return x < 10;
    if (!x) {
        if (!get_dp(i - 1, s)) return false;
        vi u;
        reverse(all(v));
        forn(i, v.size()) {
            if (i) cout << '+';
            cout << v[i];
        }
        cout << '\n';
        assert(restore(i - 1, s, 0, u));
        return true;
    }
    v.pb(x);
    if (restore(i, 0, s + x, v)) return true;
    v.pop_back();
    vi z;
    for (int p = 10; p <= x; p *= 10) {
        v.pb(x % p);
        if (restore(i, x / p, s + x % p, v)) return true;
        v.pop_back();
    } 
    return false;    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    forn(i, 2) forn(j, T) d[i][j] = -1;
    string s;
    int n;
    cin >> n >> s;
    while (1) {
        int sum = 0;
        int L = 0;
        forn(i, n + 1) bord[i] = 0;
        while (L < n) {
            int R = L + 1 + rand() % len;
            uin(R, n);
            bord[R] = 1;
            int x = 0;
            while (L < R) x = 10 * x + s[L] - '0', ++L;
            sum += x;
        }
        assert(sum / 9 < T);
        if (get_dp(2, sum)) {
            forn(i, n) {
                if (bord[i]) cout << '+';
                cout << s[i];
            }
            cout << '\n';
            vi v;
            assert(restore(2, sum, 0, v));
            break;
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}