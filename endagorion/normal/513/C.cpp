#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
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
    vi l(N), r(N);
    forn(i, N) cin >> l[i] >> r[i];
    double ans = 0.0;
    forn(i, N) {
        for (int c = l[i]; c <= r[i]; ++c) {
            forn(j, N) {
                if (i == j) continue;
                double q = 1.0 * c / (r[i] - l[i] + 1);
                if (j < i) q *= 1.0 * max(0, r[j] - max(l[j], c) + 1) / (r[j] - l[j] + 1);
                else q *= 1.0 * max(0, r[j] - max(l[j], c + 1) + 1) / (r[j] - l[j] + 1);
                forn(k, N) {
                    if (k == i || k == j) continue;
                    if (k < i) q *= 1.0 * max(0, min(c - 1, r[k]) - l[k] + 1) / (r[k] - l[k] + 1);
                    else q *= 1.0 * max(0, min(c, r[k]) - l[k] + 1) / (r[k] - l[k] + 1);
                }
                ans += q;
            }
        }
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}