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

int n, m;
char s[100][105];
int c[100] = {};
int a[100][100];

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) scanf("%s", s[i]);
    REP(i, n) REP(j, m) if (s[i][j] == 'W') a[i][j] = 1;
    else a[i][j] = -1;
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) for (int j = m - 1; j >= 0; --j) {
        if (c[j] == a[i][j]) continue;
        int dif = a[i][j] - c[j];
        for (int k = 0; k <= j; ++k)
            c[k] += dif;
        ++ans;
    }
    printf("%d\n", ans);
    return 0;
}