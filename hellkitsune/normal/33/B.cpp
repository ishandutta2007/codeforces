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

int d[26][26];
char s[100005], t[100005];
int len, n;
const int INF = 1e9;
char from[5], to[5];
int dist[26][26];
char let[26][26];

int main() {
    scanf("%s%s%d", s, t, &n);
    int len = strlen(s);
    if (len != (int)strlen(t)) {
        printf("-1\n");
        return 0;
    }
    REP(i, 26) REP(j, 26) d[i][j] = INF;
    REP(i, 26) d[i][i] = 0;
    REP(i, n) {
        int w;
        scanf("%s%s%d", from, to, &w);
        d[from[0] - 'a'][to[0] - 'a'] = min(d[from[0] - 'a'][to[0] - 'a'], w);
    }
    REP(k, 26) REP(i, 26) REP(j, 26) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }
    REP(i, 26) REP(j, 26) {
        int res = INF;
        REP(k, 26) if (res > d[i][k] + d[j][k]) {
            res = d[i][k] + d[j][k];
            let[i][j] = char('a' + k);
        }
        dist[i][j] = res;
    }
    int ans = 0;
    REP(i, len) {
        int cur = dist[s[i] - 'a'][t[i] - 'a'];
        if (cur == INF) {
            printf("-1\n");
            return 0;
        }
        ans += cur;
        s[i] = let[s[i] - 'a'][t[i] - 'a'];
    }
    printf("%d\n%s\n", ans, s);
    return 0;
}