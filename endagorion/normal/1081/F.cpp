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

const int maxn = 400;
int a[maxn];
int ors[maxn], secret[maxn];

int n;

int sum() {
//    assert(false);
    int res = 0;
    forn(i, n) res += secret[i];
    return res;
}

int cnt = 0;

int query(int l, int r) {
    cout << "? " << l + 1 << ' ' << r + 1 << endl;
    int x;
    cin >> x;
    assert(x != -1);
    return x;

    ++cnt;
    int L, R;
    if (rand() % 2) L = 0, R = r;
    else L = l, R = n - 1;
//    cerr << l << ' ' << r << ' ' << L << ' ' << R << '\n';
    fore(i, L, R) secret[i] ^= 1;
    
    return sum();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;

    srand(time(0));

    int t;
    cin >> n >> t;
//    forn(i, n) ors[i] = secret[i] = 0;//rand() % 2;
//    t = sum();
    int T = t;
//    cerr << t << '\n';

    forn(i, n - 1) {
        forn(j, 30) {
            forn(z, 2) t = query(i + 1, n - 1);
            if (t != T) break;
        }
//        cerr << i << ' ' << t << ' ' << T << '\n';
        assert((T - t + i + 1) % 2 == 0);
        a[i] = (T - t + i + 1) / 2;
//        assert(a[i] == 0 || a[i] == 1);
//        cerr << i << ' ' << a[i] << ' ' << pref << '\n';
        while (t != T) forn(z, 2) t = query(i + 1, n - 1);
    }
    a[n - 1] = T;
    ford(i, n - 1) a[i + 1] -= a[i];

    cerr << cnt << '\n';
//        cerr << a[i] << ' ' << ors[i] << '\n';
//    forn(i, n) assert(a[i] == ors[i]);
    cout << "! ";
    forn(i, n) cout << a[i];
    cout << endl;

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}