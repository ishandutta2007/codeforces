#include <cstdio>
#include <cmath>
#include <cstring>
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

int n;
int a[1000][1000];
int b[2][500];

int main() {
    scanf("%d", &n);
    int m = n / 2;
    REP(i, m) b[1][i] = i;
    REP(i, m) b[0][m - 1 - i] = m + i;
    REP(i, n) a[i][i] = 0;
    for (int i = 1; i <= n - 1; ++i) {
        REP(j, m) a[b[0][j]][b[1][j]] = a[b[1][j]][b[0][j]] = i;
        int tmp = b[1][0];
        REP(j, m - 1) b[1][j] = b[1][j + 1];
        b[1][m - 1] = b[0][m - 1];
        for (int j = m - 1; j > 1; --j) b[0][j] = b[0][j - 1];
        b[0][1] = tmp;
    }
    REP(i, n) {
        REP(j, n) printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}