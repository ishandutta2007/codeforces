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
#define mt make_tuple
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
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N;
    scanf("%d", &N);
    vi a(N);
    forn(i, N) scanf("%d", &a[i]);
    vi b(N);
    for1(i, N - 2) b[i] = a[i] != a[i - 1] && a[i] != a[i + 1];
    int ans = 0;
    int i = 1;
    while (i < N - 1) {
        if (!b[i]) ++i;
        else {
            int j = i;
            while (b[j]) ++j;
            uax(ans, (j - i + 1) / 2);
            if ((j - i) % 2 == 1) for (int k = i; k < j; ++k) a[k] = a[i - 1];
            else for (int k = i; k < j; ++k) a[k] = (k < (i + j) / 2 ? a[i - 1] : a[j]);
            i = j;
        }
    }
    printf("%d\n", ans);
    forn(i, N) printf("%d ", a[i]);
    printf("\n");

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}