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
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int a, b, n;
int d[40000][33] = {};

int main() {
    REP(i, 40000) REP(j, 33) d[i][j] = 1;
    scanf("%d%d%d", &a, &b, &n);
    for (int i = 1; i < 40000; ++i) {
        LL cur = 1;
        for (int j = 1; j < 33; ++j) {
            cur *= i;
            d[i][j] = cur >= n;
            if (cur >= n) break;
        }
    }
    d[39999][1] = (39999 >= n) || (n & 1);
    for (int i = 39999; i >= 1; --i) for (int j = 32; j >= 1; --j) if (d[i][j] == 0) {
        if (i == 39999 && j == 1) continue;
        if (i == 1) {
            if (d[i + 1][j] == 0 || (j < 32 && d[i][j + 1] == 0)) {
                d[i][j] = 1;
            } else if (j == 32 || d[i][j + 1] == 2) {
                d[i][j] = 2;
            }
            continue;
        }
        if (d[i + 1][j] == 0 || d[i][j + 1] == 0) {
            d[i][j] = 1;
        }
    }
    if (d[a][b] == 1) printf("Masha\n");
    else if (d[a][b] == 0) printf("Stas\n");
    else printf("Missing\n");
    return 0;
}