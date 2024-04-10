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

int a[2000011];
int prv[2000011];

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N;
    cin >> N;
    forn(i, N) {
        int x;
        cin >> x;
        a[x] = 1;
    }

    prv[1] = 0;
    for (int i = 2; i <= 2000000; ++i) {
        if (a[i - 1]) prv[i] = i - 1;
        else prv[i] = prv[i - 1];
    }
    int ans = 0;
    for (int i = 1; i <= 1000000; ++i) {
        if (!a[i]) continue;
//        cerr << i << '\n';
        for (int k = 2; i * k <= 2000000; ++k) {
//            cerr << prv[i * k] << '\n';
            ans = max(ans, prv[i * k] % i);
        }
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}