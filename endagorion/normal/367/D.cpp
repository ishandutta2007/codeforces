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

int a[100000];
int c[20];
int bad[1 << 20];

int N, M, D;

int cmask() {
    int r = 0;
    forn(i, M) {
        if (c[i]) {
            r += (1 << i);
        }
    }
    return r;
}

int popcount(int x) {
    int r = 0;
    while (x) {
        r += x % 2;
        x /= 2;
    }
    return r;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    scanf("%d%d%d", &N, &M, &D);
    forn(i, M) {
        int Q;
        scanf("%d", &Q);
        forn(j, Q) {
            int x;
            scanf("%d", &x);
            --x;
            a[x] = i;
        }
    }
    forn(i, D) {
        ++c[a[i]];
    }
    bad[cmask()] = 1;
//    cout << cmask() << '\n';
    for (int i = D; i < N; ++i) {
        --c[a[i - D]];
        ++c[a[i]];
        bad[cmask()] = 1;
//        cout << cmask() << '\n';
    }
    int ans = M + 1;
    forn(i, 1 << M) {
        if (!bad[i]) {
            continue;
        }
        forn(j, M) {
            bad[i | (1 << j)] = 1;
        }
    }    
    forn(i, 1 << M) {
        if (!bad[i]) {
            ans = min(ans, M - popcount(i));
        }
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}