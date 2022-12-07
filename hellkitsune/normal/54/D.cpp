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

int n, k, len;
string p, pat, cur;
string ans;
int pf[100];
bool d[105][105] = {};
char pre[105][105];
int ind[105][105];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> p >> pat;
    p += '#';
    len = (int)p.length();
    pf[0] = 0;
    for (int i = 1; i < len; ++i) {
        int cur = pf[i - 1];
        while (cur && p[cur] != p[i])
            cur = pf[cur - 1];
        if (p[cur] == p[i])
            ++cur;
        pf[i] = cur;
    }
    d[0][0] = true;
    REP(i, n) REP(j, len) if (d[i][j]) REP(c, k) {
        char ch = 'a' + c;
        int cur = j;
        while (cur && p[cur] != ch)
            cur = pf[cur - 1];
        if (p[cur] == ch)
            ++cur;
        int pn = i - len + 2;
        if (pn < 0 || (pat[pn] == '0' && cur < len - 1) || (pat[pn] == '1' && cur == len - 1)) {
            d[i + 1][cur] = true;
            pre[i + 1][cur] = ch;
            ind[i + 1][cur] = j;
        }
    }
    REP(i, len) if (d[n][i]) {
        int ii = n;
        int jj = i;
        while (ii != 0) {
            ans += pre[ii][jj];
            jj = ind[ii][jj];
            --ii;
        }
        reverse(ans.begin(), ans.end());
        printf("%s\n", ans.c_str());
        return 0;
    }
    printf("No solution\n");
    return 0;
}