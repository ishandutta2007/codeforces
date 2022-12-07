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

bool g[1000] = {};
char s[1000][1005];
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) scanf("%s", s[i]);
    int ans = 0;
    REP(j, m) {
        bool flag = false;
        REP(i, n - 1) if (!g[i] && s[i][j] > s[i + 1][j]) {
            flag = true;
            break;
        }
        if (flag) {
            ++ans;
            continue;
        }
        REP(i, n - 1) if (s[i][j] < s[i + 1][j])
            g[i] = true;
    }
    printf("%d\n", ans);
    return 0;
}