#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
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

const int INF = 1e9;

string s1, s2;
int n, m;
int lcp[5001][5001], d1[5001] = {}, d2[5001] = {};

int main() {
    cin >> s1 >> s2;
    n = s1.length();
    m = s2.length();
    REP(i, n + 1) REP(j, n + 1) lcp[i][j] = 0;
    for (int i = n - 1; i >= 0; --i)
        for (int j = n - 1; j >= 0; --j)
            if (s1[i] == s1[j])
                lcp[i][j] = lcp[i + 1][j + 1] + 1;
            else
                lcp[i][j] = 0;
    REP(i, n) REP(j, n) if (j != i)
        d1[i] = max(d1[i], lcp[i][j]);
    REP(i, m + 1) REP(j, m + 1) lcp[i][j] = 0;
    for (int i = m - 1; i >= 0; --i)
        for (int j = m - 1; j >= 0; --j)
            if (s2[i] == s2[j])
                lcp[i][j] = lcp[i + 1][j + 1] + 1;
            else
                lcp[i][j] = 0;
    REP(i, m) REP(j, m) if (j != i)
        d2[i] = max(d2[i], lcp[i][j]);
    REP(i, n + 1) REP(j, m + 1) lcp[i][j] = 0;
    for (int i = n - 1; i >= 0; --i)
        for (int j = m - 1; j >= 0; --j)
            if (s1[i] == s2[j])
                lcp[i][j] = lcp[i + 1][j + 1] + 1;
            else
                lcp[i][j] = 0;
    int ans = INF;
    REP(i, n) REP(j, m)
        if (lcp[i][j] > max(d1[i], d2[j]))
            ans = min(ans, max(d1[i], d2[j]) + 1);
    if (ans == INF)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}