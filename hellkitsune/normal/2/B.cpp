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

int n;
signed char a[1000][1000] = {};
signed char b[1000][1000] = {};
bool c[1000][1000] = {};
int d[1000][1000];
bool prev1[1000][1000], prev2[1000][1000];
int best;
bool hasz;
int zx, zy;

int main() {
    scanf("%d", &n);
    REP(i, n) REP(j, n) {
        int x;
        scanf("%d", &x);
        if (x == 0) {
            hasz = c[i][j] = true;
            zx = i; zy = j;
            a[i][j] = b[i][j] = 100;
        } else {
            while (!(x & 1)) {
                x >>= 1;
                ++a[i][j];
            }
            while (x % 5 == 0) {
                x /= 5;
                ++b[i][j];
            }
        }
    }
    d[0][0] = a[0][0];
    for (int i = 1; i < n; ++i) {
        d[0][i] = d[0][i - 1] + a[0][i];
        prev1[0][i] = true;
        d[i][0] = d[i - 1][0] + a[i][0];
        prev1[i][0] = false;
    }
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < n; ++j) {
            if (d[i - 1][j] < d[i][j - 1]) {
                d[i][j] = d[i - 1][j] + a[i][j];
                prev1[i][j] = false;
            } else {
                d[i][j] = d[i][j - 1] + a[i][j];
                prev1[i][j] = true;
            }
        }
    best = d[n - 1][n - 1];

    d[0][0] = b[0][0];
    for (int i = 1; i < n; ++i) {
        d[0][i] = d[0][i - 1] + b[0][i];
        prev2[0][i] = true;
        d[i][0] = d[i - 1][0] + b[i][0];
        prev2[i][0] = false;
    }
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < n; ++j) {
            if (d[i - 1][j] < d[i][j - 1]) {
                d[i][j] = d[i - 1][j] + b[i][j];
                prev2[i][j] = false;
            } else {
                d[i][j] = d[i][j - 1] + b[i][j];
                prev2[i][j] = true;
            }
        }
    if (d[n - 1][n - 1] < best) {
        best = d[n - 1][n - 1];
        REP(i, n) REP(j, n)
            prev1[i][j] = prev2[i][j];
    }

    if (hasz && best > 1) {
        printf("1\n");
        for (int i = 0; i < zx; ++i)
            printf("D");
        REP(i, n - 1)
            printf("R");
        for (int i = zx; i < n - 1; ++i)
            printf("D");
        printf("\n");
        return 0;
    }
    printf("%d\n", best);
    vector<char> ans;
    for (int i = n - 1, j = n - 1; i + j > 0; ) {
        if (prev1[i][j]) {
            ans.pb('R');
            --j;
        } else {
            ans.pb('D');
            --i;
        }
    }
    reverse(ans.begin(), ans.end());
    REP(i, ans.size())
        printf("%c", ans[i]);
    printf("\n");
    return 0;
}