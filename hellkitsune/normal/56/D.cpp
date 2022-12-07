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

char s[1005], t[1005];
int n, m;
int d[1005][1005], p[1005][1005];
const int INF = 1e9;
vector<string> ans;

int main() {
    scanf("%s%s", s, t);
    n = strlen(s);
    m = strlen(t);
    REP(i, n + 1) REP(j, m + 1) d[i][j] = INF;
    d[0][0] = 0;
    REP(i, n + 1) REP(j, m + 1) {
        if (i < n && d[i + 1][j] > d[i][j] + 1) {
            d[i + 1][j] = d[i][j] + 1;
            p[i + 1][j] = 0;
        }
        if (j < m && d[i][j + 1] > d[i][j] + 1) {
            d[i][j + 1] = d[i][j] + 1;
            p[i][j + 1] = 1;
        }
        if (i < n && j < m && s[i] == t[j] && d[i + 1][j + 1] > d[i][j]) {
            d[i + 1][j + 1] = d[i][j];
            p[i + 1][j + 1] = 2;
        }
        if (i < n && j < m && s[i] != t[j] && d[i + 1][j + 1] > d[i][j] + 1) {
            d[i + 1][j + 1] = d[i][j] + 1;
            p[i + 1][j + 1] = 3;
        }
    }
    printf("%d\n", d[n][m]);
    while (n + m > 0) {
        ostringstream oss;
        bool flag = false;
        if (p[n][m] == 0) {
            oss << "DELETE " << m + 1;
            --n;
        } else if (p[n][m] == 1) {
            oss << "INSERT " << m << ' ' << t[m - 1];
            --m;
        } else if (p[n][m] == 3) {
            oss << "REPLACE " << m << ' ' << t[m - 1];
            --n;
            --m;
        } else {
            flag = true;
            --n;
            --m;
        }
        if (!flag) ans.pb(oss.str());
    }
    for (int i = (int)ans.size() - 1; i >= 0; --i) {
        printf("%s\n", ans[i].c_str());
    }
    return 0;
}