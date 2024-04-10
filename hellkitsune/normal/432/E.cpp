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
char a[102][102];

char findmin(int i, int j) {
    char cur = 'A';
    while (a[i - 1][j] == cur || a[i + 1][j] == cur || a[i][j - 1] == cur || a[i][j + 1] == cur)
        ++cur;
    return cur;
}

bool isLetter(char z) {
    return (z >= 'A' && z <= 'Z');
}

int main() {
    cin >> n >> m;
    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0; j <= m; ++j)
            a[i][j] = '.';
        a[i][m + 1] = '\0';
    }
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) if (a[i][j] == '.') {
        char cur = findmin(i, j);
        int maxsz = 1e9;
        for (int k = 1; k <= min(n - i, m - j); ++k)
            if (findmin(i, j + k) < cur) {
                maxsz = k;
                break;
            }
        int sz = 1;
        for (int k = 1; k <= min(maxsz, min(n - i, m - j)); ++k) {
            if (k + 1 > maxsz)
                break;
            if (a[i][j + k + 1] == cur || a[i - 1][j + k] == cur)
                break;
            if (a[i + k + 1][j] == cur || a[i + k][j - 1] == cur)
                break;
            bool flag = true;
            for (int t = 0; t <= k; ++t)
                if (isLetter(a[i + t][j + k]) || isLetter(a[i + k][j + t])) {
                    flag = false;
                    break;
                }
            for (int t = 0; t <= k; ++t)
                if (a[i + t][j + k + 1] == cur) {
                    flag = false;
                    break;
                }
            if (!flag) break;
            for (int t = 0; t <= k; ++t)
                if (a[i + k + 1][j + t] == cur) {
                    flag = false;
                    break;
                }
            if (!flag) break;
            sz = k + 1;
        }
        REP(ii, sz) REP(jj, sz)
            a[i + ii][j + jj] = cur;
    }
    for (int i = 1; i <= n; ++i)
        printf("%s\n", a[i] + 1);
    return 0;
}