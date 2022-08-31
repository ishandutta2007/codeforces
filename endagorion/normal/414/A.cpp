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
    freopen("output.txt", "wt", stdout);
#endif

    int N, K;
    scanf("%d%d", &N, &K);
    if (K < N / 2 || (N == 1 && K > 0)) {
        printf("-1\n");
        return 0;
    }
    if (N == 1) {
        printf("1\n");
        return 0;
    }
    forn(i, 2 * (N / 2 - 1)) {
        printf("%d ", 1000000000 - i);
    }
    printf("%d %d ", 2 * (K - (N / 2 - 1)), 3 * (K - (N / 2 - 1)));
    if (N % 2 == 1) {
        printf("1 ");
    }
    printf("\n");

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}