#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

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

const int MAXN = 100000;
const int INF = 1e9;
int a[MAXN];
int b[MAXN], r[MAXN], fr[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int T;
    scanf("%d", &T);
    while (T-->0) {
        int M, K;
        scanf("%d%d", &M, &K);
        forn(i, K) scanf("%d", &a[i]);
        forn(i, M - 1) scanf("%d%d", &b[i], &r[i]), --b[i];
		forn(i, K) fr[i] = 0;
        int unc = 0;
        bool wasr = false;
        forn(i, M - 1) {
            if (r[i] && !wasr) {
                vi nonz(K);
                for (int j = i; j < M - 1; ++j) {
                    if (b[j] >= 0) nonz[b[j]] = 1;
                }
				bool afr = false;
				int x = INF;
				forn(j, K) {
					if (!nonz[j] && a[j] <= unc) {
						uin(x, a[j]);
						fr[j] = 1;
						afr = 1;
					}
				}
                assert(afr);
                unc -= x;
                wasr = true;
            }
            if (b[i] >= 0) --a[b[i]];
            else ++unc;
        }
        forn(i, K) printf("%c", "NY"[a[i] <= unc || fr[i]]);
        printf("\n");
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}