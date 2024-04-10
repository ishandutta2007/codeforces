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

int b[1000000];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    ios::sync_with_stdio(false);
    int N;
    scanf("%d", &N);
    if (N <= 2) {
        cout << 0 << '\n';
        return 0;
    }
    i64 sum = 0;
    int m1 = 0, m2 = 0;
    forn(i, N) {
        scanf("%d", &b[i]);
        sum += b[i];
        if (b[i] > m1) m2 = m1, m1 = b[i];
        else if (b[i] > m2) m2 = b[i];
    }
    i64 ans = 2 * sum - 2 * m1 - m2;
    forn(i, N - 1) {
        ans -= min(b[i], b[i + 1]);
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}