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

int n, m, k;
char s[100][105];
int d[100][100][11], p[100][100][11], pq[100][100][11];
string ans;

int main() {
    scanf("%d%d%d", &n, &m, &k), ++k;
    REP(i, n) scanf("%s", s[i]);
    REP(i, n) REP(j, m) REP(q, k) d[i][j][q] = -1;
    REP(i, m) d[n - 1][i][(s[n - 1][i] - '0') % k] = s[n - 1][i] - '0';
    for (int i = n - 1; i > 0; --i) {
        REP(j, m - 1) REP(q, k) if (d[i][j][q] != -1) {
            int cnt = d[i][j][q] + s[i - 1][j + 1] - '0';
            int mo = cnt % k;
            if (d[i - 1][j + 1][mo] < cnt) {
                d[i - 1][j + 1][mo] = cnt;
                p[i - 1][j + 1][mo] = 0;
                pq[i - 1][j + 1][mo] = q;
            }
        }
        for (int j = 1; j < m; ++j) REP(q, k) if (d[i][j][q] != -1) {
            int cnt = d[i][j][q] + s[i - 1][j - 1] - '0';
            int mo = cnt % k;
            if (d[i - 1][j - 1][mo] < cnt) {
                d[i - 1][j - 1][mo] = cnt;
                p[i - 1][j - 1][mo] = 1;
                pq[i - 1][j - 1][mo] = q;
            }
        }
    }
    int best = 0;
    for (int i = 1; i < m; ++i) if (d[0][i][0] > d[0][best][0]) {
        best = i;
    }
    if (d[0][best][0] == -1) {
        printf("-1\n");
        return 0;
    }
    int q = 0;
    printf("%d\n", d[0][best][0]);
    REP(i, n - 1) {
        if (p[i][best][q] == 0) {
            ans += 'R';
            q = pq[i][best][q];
            --best;
        } else {
            ans += 'L';
            q = pq[i][best][q];
            ++best;
        }
    }
    reverse(ans.begin(), ans.end());
    printf("%d\n%s\n", best + 1, ans.c_str());
    return 0;
}