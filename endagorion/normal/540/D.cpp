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

double prob[3][101][101][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    for1(i, 100) {
        prob[0][i][0][0] = prob[1][0][i][0] = prob[2][0][0][i] = 1.0;
    }
    forn(i, 101) forn(j, 101) forn(k, 101) {
        int z = !!i + !!j + !!k;
        if (z <= 1) continue;
        double coef = 1.0 / (i * j + i * k + j * k);
        forn(y, 3) prob[y][i][j][k] += (i * j * (j ? prob[y][i][j - 1][k] : 0.0) + j * k * (k ? prob[y][i][j][k - 1] : 0.0) + k * i * (i ? prob[y][i - 1][j][k] : 0.0)) / (i * j + j * k + k * i);
    }

    int A, B, C;
    cin >> A >> B >> C;
    forn(y, 3) cout << prob[y][A][B][C] << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}