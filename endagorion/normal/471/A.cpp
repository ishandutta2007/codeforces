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

    vi a(6);
    forn(i, 6) cin >> a[i];
    sort(all(a));
    bool el = false, bear = false;
    do {
        if (a[0] == a[1] && a[1] == a[2] && a[2] == a[3]) {
            if (a[4] == a[5]) el = true;
            else bear = true;
        }
    } while (next_permutation(all(a)));
    if (el) cout << "Elephant\n";
    else if (bear) cout << "Bear\n";
    else cout << "Alien\n";

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}