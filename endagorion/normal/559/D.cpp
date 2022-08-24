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
typedef long double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int MAXN = 200001;
const ld eps = 1e-13;
i64 x[MAXN], y[MAXN];
ld pw[MAXN];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
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
    forn(i, N) cin >> x[i] >> y[i];
    forn(i, N) x[i + N] = x[i], y[i + N] = y[i];
    pw[0] = 1.0;
    forn(i, N) pw[i + 1] = pw[i] * 0.5;

    ld ans = 0.0;
    forn(i, N) {
        for1(j, N - 1) {
            if (pw[j] < eps) break;
            int G = gcd(abs(x[i + j] - x[i]), abs(y[i + j] - y[i]));
            ans += 0.5 * pw[j + 1] * (-1.0 * (x[i + j] - x[i]) * (y[i + j] + y[i]) - G);
            ans += 0.5 * G * pw[N];
        }
    }
    ld coef = 1.0 - pow(0.5, N) * (1.0 + N + 0.5 * N * (N - 1));
    cout << (double)(ans / coef) + 1.0 << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}