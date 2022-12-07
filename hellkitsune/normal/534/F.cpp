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
char s[5][21];
int a[5], b[20];
set<int> vis;
int ans[20];
vector<int> pat[4];
int cur[5] = {};
int mul[5];
bool rem[20][5];

void go(int pos, int mask) {
    if (vis.count((pos << 24) | mask))
        return;
    vis.insert((pos << 24) | mask);
    REP(i, n) {
        if (cur[i] > 2 * a[i]) return;
        if (cur[i] + m - pos < 2 * a[i] - 1) return;
    }
    if (pos == m) {
        REP(i, n) REP(j, m) {
            if (ans[j] & (1 << i)) s[i][j] = '*';
            else s[i][j] = '.';
        }
        REP(i, n) s[i][m] = '\0';
        REP(i, n) printf("%s\n", s[i]);
        exit(0);
    }
    for (int mmask : pat[b[pos]]) {
        REP(i, n) rem[pos][i] = false;
        REP(i, n) {
            if (((mmask & (1 << i)) == 0) != ((cur[i] & 1) == 0))
                ++cur[i], mask += mul[i], rem[pos][i] = true;
        }
        ans[pos] = mmask;
        go(pos + 1, mask);
        REP(i, n) {
            if (rem[pos][i])
                --cur[i], mask -= mul[i];
        }
    }
}

int main() {
    mul[0] = 1;
    for (int i = 1; i < 5; ++i) mul[i] = 21 * mul[i - 1];
    scanf("%d%d", &n, &m);
    REP(i, n) scanf("%d", a + i);
    REP(i, m) scanf("%d", b + i);
    REP(mask, 1 << n) {
        bool flag = true;
        int cnt = 0;
        REP(i, n) if (mask & (1 << i)) {
            if (flag) {
                ++cnt;
                flag = false;
            }
        } else {
            flag = true;
        }
        pat[cnt].pb(mask);
    }
    go(0, 0);
    return 0;
}