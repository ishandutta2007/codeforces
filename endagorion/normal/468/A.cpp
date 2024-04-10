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

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    if (N < 4) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    int ec = 0;
    if (N % 2 == 1) {
        cout << "5 - 3 = 2\n";
        cout << "1 + 2 = 3\n";
    } else ec = 1;
    for (int i = N; i > 5; i -= 2) {
        cout << i << " - " << i - 1 << " = " << 1 << '\n';
        ++ec;
    }
    cout << "4 * 3 = 12\n12 * 2 = 24\n";
    forn(i, ec) cout << "24 * 1 = 24\n";

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}