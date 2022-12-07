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

int n, m;
string s[500];
int d[500][26][26], pi[500][26][26], pj[500][26][26];
const int INF = 1e9;
int ans[500][2];

inline int calc(int v, char x, char y) {
    int ret = 0;
    for (int i = 0; i < m; i += 2) if (s[v][i] != x)
        ++ret;
    for (int i = 1; i < m; i += 2) if (s[v][i] != y)
        ++ret;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    REP(i, n) cin >> s[i];
    REP(i, 26) REP(j, 26) if (i != j) {
        d[0][i][j] = calc(0, 'a' + i, 'a' + j);
    }
    for (int v = 1; v < n; ++v) {
        REP(i, 26) REP(j, 26) if (i != j) {
            d[v][i][j] = calc(v, 'a' + i, 'a' + j);
            int mn = INF;
            REP(ii, 26) if (ii != i) REP(jj, 26) if (jj != j && jj != ii) {
                if (mn > d[v - 1][ii][jj]) {
                    mn = d[v - 1][ii][jj];
                    pi[v][i][j] = ii;
                    pj[v][i][j] = jj;
                }
            }
            d[v][i][j] += mn;
        }
    }
    int mn = INF;
    REP(i, 26) REP(j, 26) if (i != j) {
        if (mn > d[n - 1][i][j]) {
            mn = d[n - 1][i][j];
            ans[n - 1][0] = i;
            ans[n - 1][1] = j;
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        ans[i][0] = pi[i + 1][ans[i + 1][0]][ans[i + 1][1]];
        ans[i][1] = pj[i + 1][ans[i + 1][0]][ans[i + 1][1]];
    }
    cout << mn << '\n';
    REP(i, n) {
        string s(m, 'a' + ans[i][0]);
        for (int j = 1; j < m; j += 2)
            s[j] = 'a' + ans[i][1];
        cout << s << '\n';
    }
    return 0;
}