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

template<class T>
bool uin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool uax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const i64 P = 1000000000 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N, M;
    cin >> N >> M;
    string p;
    cin >> p;
    int K = p.size();
    vi z(K);
    int L = 0, R = 0;
    for1(i, K - 1) {
        if (R < i) L = R = i;
        z[i] = min(z[i - L], R - i);
        while (i + z[i] < K && p[z[i]] == p[i + z[i]]) ++z[i], L = i, R = i + z[i];
    }
    vi x(M);
    forn(i, M) cin >> x[i], --x[i];
    x.pb(1e9);
    i64 res = 1;
    L = 0, R = 0;
    int j = 0;
    forn(i, N) {
        if (x[j] == i) {
            if (i < R && z[i - L] < R - i) {
                res = 0;
                break;
            }
            L = i, R = i + K;
            ++j;
        }
        if (i >= R) res *= 26, res %= P;
    }
    cout << res << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}