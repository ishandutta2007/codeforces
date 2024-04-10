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

int a[1 << 24];

void calc_sum(int m, int i, int k) {
    if (i < 0) {
        return;
    }
    calc_sum(m, i - 1, k);
    calc_sum(m + (1 << i), i - 1, k);
    forn(j, 1 << i) {
        a[m + (1 << i) + j] += a[m + j];
    }
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N;
    cin >> N;
    forn(i, N) {    
        string s;
        cin >> s;
        int m = 0;
        forn(j, 3) {
            m |= 1 << (s[j] - 'a');
        }
        ++a[m];
    }

    calc_sum(0, 23, 24);
    int ans = 0;
    forn(i, (1 << 24)) {
        a[i] = N - a[i];
        ans ^= a[i] * a[i];
//        cout << i << ' ' << a[i] << '\n';
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}