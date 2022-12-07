#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

const LL INF = 2e9;

int n, m;
int a[1000][1000];
int d[4][1000][1000];

void filld(int x) {
    d[x][0][0] = a[0][0];
    for (int i = 1; i < n; ++i) d[x][i][0] = d[x][i - 1][0] + a[i][0];
    for (int j = 1; j < m; ++j) d[x][0][j] = d[x][0][j - 1] + a[0][j];
    for (int i = 1; i < n; ++i) for (int j = 1; j < m; ++j)
        d[x][i][j] = max(d[x][i - 1][j], d[x][i][j - 1]) + a[i][j];
}

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) REP(j, m)
        scanf("%d", a[i] + j);
    filld(0);
    REP(i, n) reverse(a[i], a[i] + m);
    filld(1);
    REP(j, m) REP(i, n >> 1) swap(a[i][j], a[n - 1 - i][j]);
    filld(2);
    REP(i, n) reverse(a[i], a[i] + m);
    filld(3);
    REP(j, m) REP(i, n >> 1) swap(a[i][j], a[n - 1 - i][j]);
    REP(i, n) {
        reverse(d[1][i], d[1][i] + m);
        reverse(d[2][i], d[2][i] + m);
    }
    REP(j, m) REP(i, n >> 1) {
        swap(d[2][i][j], d[2][n - 1 - i][j]);
        swap(d[3][i][j], d[3][n - 1 - i][j]);
    }
    /*REP(x, 4) REP(i, n) REP(j, m)
        d[x][i][j] -= a[i][j];*/
    /*REP(x, 4) {
        REP(i, n) {
            REP(j, m) cout << d[x][i][j] << ' ';
            cout << endl;
        }
        cout << endl;
    }*/
    LL ans = 0;
    for (int i = 1; i < n - 1; ++i) for (int j = 1; j < m - 1; ++j) {
        LL w1 = d[0][i - 1][j] + (LL)d[2][i + 1][j] + d[1][i][j + 1] + (LL)d[3][i][j - 1];
        LL w2 = d[0][i][j - 1] + (LL)d[2][i][j + 1] + d[1][i - 1][j] + (LL)d[3][i + 1][j];
        ans = max(max(ans, w1), w2);
    }
    cout << ans << endl;
    return 0;
}