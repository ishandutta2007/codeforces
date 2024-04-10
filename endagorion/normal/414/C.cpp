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

int a[1 << 20], buf[1 << 20];
i64 inv[21], rinv[21];
int p[21];

void count_inv(int b, int l) {
    if (l == 0) return;
    int bb = b + (1 << (l - 1));
    count_inv(b, l - 1);
    count_inv(bb, l - 1);
    int ll = 1 << (l - 1);

    int i = 0, j = 0;
    int c = 0;
    while (i < ll || j < ll) {
        int x = 2e9;
        if (i < ll) x = min(x, a[b + i]);
        if (j < ll) x = min(x, a[bb + j]);
        int ii = i, jj = j;
        while (ii < ll && a[b + ii] == x) {
            buf[c++] = a[b + ii++];
        }
        while (jj < ll && a[bb + jj] == x) {
            buf[c++] = a[bb + jj++];
        }
        inv[l] += 1LL * (ii - i) * j;
        rinv[l] += 1LL * (jj - j) * i;
        i = ii;
        j = jj;
    }
    forn(i, (1 << l)) {
        a[b + i] = buf[i];
    }
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N;
    scanf("%d", &N);
    forn(i, 1 << N) {
        scanf("%d", &a[i]);
    }
    count_inv(0, N);
    int M;
    scanf("%d", &M);

    forn(i, M) {
        int x;
        scanf("%d", &x);
        for (int j = 1; j <= x; ++j) {
            p[j] ^= 1;
        }
        i64 sum = 0;
        for (int j = 1; j <= N; ++j) {
            sum += (p[j] == 0 ? inv[j] : rinv[j]);
        }
        printf("%I64d\n", sum);
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}