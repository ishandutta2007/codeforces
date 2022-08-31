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
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

bool found(const vi64 &a, i64 x) {
    return x <= a.back() && *lower_bound(all(a), x) == x;
}

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    i64 N, L, X, Y;
    cin >> N >> L >> X >> Y;
    vi64 a(N);
    forn(i, N) cin >> a[i];
    bool fx = false, fy = false;
    forn(i, N) {
        if (found(a, a[i] + X)) fx = true;
        if (found(a, a[i] + Y)) fy = true;
    }
    if (fx && fy) {
        cout << 0 << '\n';
        return 0;
    }
    if (fx) {
        cout << 1 << '\n' << Y << '\n';
        return 0;
    }
    if (fy) {
        cout << 1 << '\n' << X << '\n';
        return 0;
    }
    forn(i, N) {
        if (found(a, a[i] + X + Y)) {
            cout << 1 << '\n' << a[i] + X << '\n';
            return 0;
        }
        if (found(a, a[i] + Y - X)) {
            if (a[i] + Y < L) {
                cout << 1 << '\n' << a[i] + Y << '\n';
                return 0;
            }
            if (a[i] - X > 0) {
                cout << 1 << '\n' << a[i] - X << '\n';
                return 0;
            }
        }
    }
    cout << 2 << '\n' << X << ' ' << Y << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}