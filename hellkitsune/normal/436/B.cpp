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

int n, m, k;
char s[2000][2005];
int a[2000];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    REP(i, n)
        scanf("%s", s[i]);
    REP(i, m)
        a[i] = 0;
    for (int i = 1; i < n; ++i) REP(j, m) {
        if (s[i][j] == 'U') {
            if ((i & 1) == 0)
                ++a[j];
        } else if (s[i][j] == 'R') {
            if (j + i < m)
                ++a[j + i];
        } else if (s[i][j] == 'L') {
            if (j - i >= 0)
                ++a[j - i];
        }
    }
    REP(i, m)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}