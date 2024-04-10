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

int t[1000];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N;
    scanf("%d", &N);
    int res = 0;
    forn(i, N) {
        forn(j, N) {
            int x;
            scanf("%d", &x);
            if (i == j){
                res ^= x;
            }
        }
    }
    int M;
    scanf("%d", &M);
    forn(i, M) {
        int t;
        scanf("%d", &t);
        if (t == 1 || t == 2) {
            int x;
            scanf("%d", &x);
            res ^= 1;
        } else {
            printf("%d", res);
        }
    }
    printf("\n");

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}