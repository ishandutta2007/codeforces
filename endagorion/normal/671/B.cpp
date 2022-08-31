#include <iostream>
#include <tuple>
#include <sstream>
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
    i64 k;
    cin >> n >> k;
    vi64 a(n);
    forn(i, n) cin >> a[i];
    sort(all(a));
    i64 sum = accumulate(all(a), 0LL);
    vi64 b(n);
    forn(i, n) b[i] = (sum + i) / n;
    i64 steps = 0;
    forn(i, n) steps += max(0LL, a[i] - b[i]);
    uin(k, steps);
    i64 low, high;
    {
        i64 L = b[n - 1] - 1, R = a[n - 1] + 1;
        while (R - L > 1) {
            i64 M = (L + R) / 2;
            i64 er = 0;
            forn(i, n) er += max(0LL, a[i] - M);
            (er <= k ? R : L) = M;
        }
        high = R;
    }
    {
        i64 L = a[0] - 1, R = b[0] + 1;
        while (R - L > 1) {
            i64 M = (L + R) / 2;
            i64 er = 0;
            forn(i, n) er += max(0LL, M - a[i]);
            (er <= k ? L : R) = M;
        }
        low = L;
    }
    cerr << low << ' ' << high << '\n';
    cout << high - low << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}