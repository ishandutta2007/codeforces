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

char s[3000][3000];

int N, M, K;

char seec(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= M) return '.';
    return s[x][y];
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

string t = "ULDR";

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    ios::sync_with_stdio(false);

    scanf("%d%d%d", &N, &M, &K);
    forn(i, N) scanf("%s", s[i]);

    forn(y, M) {
        int cnt = 0;
        for (int x = 1; x < N; ++x) {
            forn(d, 4) {
                if (seec(x + x * dx[d], y + x * dy[d]) == t[d]) ++cnt;
            }
        }
        printf("%d ", cnt);
    }
    printf("\n");

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}