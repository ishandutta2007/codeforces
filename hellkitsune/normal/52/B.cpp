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
typedef long long LL;
typedef pair<int, int> PII;

int r[1000] = {}, c[1000] = {};
char s[1000][1005];
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) scanf("%s", s[i]);
    REP(i, n) REP(j, m) if (s[i][j] == '*') {
        ++r[i];
        ++c[j];
    }
    LL ans = 0;
    REP(i, n) REP(j, m) if (s[i][j] == '*') {
        ans += (r[i] - 1) * (c[j] - 1);
    }
    cout << ans << endl;
    return 0;
}