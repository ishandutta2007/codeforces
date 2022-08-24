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

const int maxn = 400000;
int cnt[maxn];
pii a[maxn];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int N, P;
    scanf("%d%d", &N, &P);
    forn(i, N) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
        ++cnt[x];
        ++cnt[y];
        if (x > y) swap(x, y);
        a[i] = mp(x, y);
    }
    i64 res = 0;
    vi cc(N);
    forn(i, N) cc[i] = cnt[i];
    sort(all(cc));
//    forn(i, N) cerr << cc[i] << '\n';
    int i = 0, j = N;
    while (i < N) {
        while (j > 0 && cc[j - 1] + cc[i] >= P) --j;
        res += (N - max(j, i + 1));

        ++i;
    }
    i = 0;
    sort(a, a + N);
    while (i < N) {
        int j = i;
        while (j < N && a[j] == a[i]) ++j;
        int d = j - i;

        int x = a[i].first, y = a[i].second;
        if (cnt[x] + cnt[y] >= P && cnt[x] + cnt[y] - d < P) --res;

        i = j;
    }
    cout << res << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}