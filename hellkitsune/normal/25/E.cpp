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

string s[3];
int p[222222];
int d[3][3];
int len[3];

int KMP(string s, int len) {
    int n = (int)s.length();
    for (int i = 1; i < n; ++i) {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j])
            j = p[j - 1];
        if (s[i] == s[j])
            ++j;
        p[i] = j;
        if (j == len) return len;
    }
    return p[n - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    REP(i, 3) cin >> s[i];
    REP(i, 3) len[i] = (int)s[i].length();
    REP(i, 3) REP(j, 3) if (i != j)
        d[i][j] = KMP(s[i] + "#" + s[j], (int)s[i].length());
    int ans = 1e9;
    REP(i, 3) REP(j, 3) if (j != i) REP(k, 3) if (k != i && k != j) {
        int cur = len[i] + len[j] + len[k] - d[j][i];
        if (d[j][i] == len[j]) {
            cur -= d[k][i];
        } else {
            cur -= d[k][j];
        }
        ans = min(ans, cur);
    }
    cout << ans << endl;
    return 0;
}