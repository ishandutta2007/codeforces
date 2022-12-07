#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int d[201][201][201] = {};
char s[205];
int r = 0, g = 0, b = 0;

int main() {
    scanf("%d%s", &n, s);
    REP(i, n) if (s[i] == 'R') ++r;
    else if (s[i] == 'G') ++g;
    else ++b;
    d[1][0][0] = 1;
    d[0][1][0] = 2;
    d[0][0][1] = 4;
    REP(cnt, 201) REP(i, cnt + 1) REP(j, cnt + 1 - i) {
        int k = cnt - i - j;
        if (i && j) d[i][j][k] |= d[i - 1][j - 1][k + 1];
        if (i && k) d[i][j][k] |= d[i - 1][j + 1][k - 1];
        if (j && k) d[i][j][k] |= d[i + 1][j - 1][k - 1];
        if (i > 1) d[i][j][k] |= d[i - 1][j][k];
        if (j > 1) d[i][j][k] |= d[i][j - 1][k];
        if (k > 1) d[i][j][k] |= d[i][j][k - 1];
    }
    int res = d[r][g][b];
    if (res & 4) printf("B");
    if (res & 2) printf("G");
    if (res & 1) printf("R");
    printf("\n");
    return 0;
}