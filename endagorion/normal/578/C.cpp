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

double f(const vi &a, double x) {
    double s = 0.0, mins = 0, maxs = 0;
    forn(i, a.size()) {
        s += a[i] + x;
        uin(mins, s);
        uax(maxs, s);
    }
    return maxs - mins;
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
    vi a(N);
    forn(i, N) cin >> a[i];
    double l = -1e9, r = 1e9;
    int A = 11, B = 10;
    forn(its, 100) {
        double m1 = (A * l + B * r) / (A + B);
        double m2 = (B * l + A * r) / (A + B);
        double f1 = f(a, m1), f2 = f(a, m2);
        if (f1 < f2) r = m2;
        else l = m1;
    }
    cout << f(a, l) << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}