#include <iostream>
#include <cassert>
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
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<long double> a(N);
    forn(i, N) cin >> a[i];
    sort(rall(a));
    long double p0 = 1.0, p1 = 0.0;
    long double ans = 0.0;
    forn(i, N) {
        p1 += a[i] * (p0 - p1);
        p0 *= 1 - a[i];
        ans = max(ans, p1);
//        cout << p1 << '\n';
    }
//    forn(i, N) p1 = max(p1, a[i]);
    printf("%.10lf\n", (double)ans);

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}