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
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

const int maxw = 30000;
const i64 P = 1000000000 + 7;

int ways[2][maxw];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    ways[0][0] = 1;
    i64 ans = 0;
    int N;
    cin >> N;
    forn(i, N) {
        int x;
        cin >> x;
        ans += ways[i & 1][x];
        ans %= P;
        int ii = (i & 1) ^ 1;
        forn(j, maxw) {
            ways[ii][j] = 0;
        }
        ways[ii][0] = 1;
        forn(j, maxw / 2) {
            ways[ii][j + x] += ways[i & 1][j];
            ways[ii][j + x] %= P;

            ways[ii][abs(j - x)] += ways[i & 1][j];
            ways[ii][abs(j - x)] %= P;
        }
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}