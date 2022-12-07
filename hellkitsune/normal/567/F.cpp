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

int n, k, N;
int x[100], y[100], sg[100];
int re[77][77];
LL d[77][77], nd[77][77];
char s[10];

bool isOK(int from, int to, int i, int j) {
    for (int pos = from; pos <= to; ++pos) if (re[pos][i] == 0 || re[pos][i] == 1 || re[pos][i] == 3) {
        return false;
    }
    for (int pos = from; pos <= to; ++pos) if (re[pos][j] == 0 || re[pos][j] == 1 || re[pos][j] == 3) {
        return false;
    }
    if (re[i][j] == 1 || re[i][j] == 2) return false;
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    REP(i, k) {
        scanf("%d%s%d", x + i, s, y + i), --x[i], --y[i];
        int len = strlen(s);
        if (len == 1) {
            if (s[0] == '=') sg[i] = 0;
            else if (s[0] == '<') sg[i] = 1;
            else sg[i] = 2;
        } else {
            if (s[0] == '<') sg[i] = 3;
            else sg[i] = 4;
        }
    }
    int cnt = 0;
    REP(i, k) if (x[i] == y[i]) {
        if (sg[i] == 1 || sg[i] == 2) {
            printf("0\n");
            return 0;
        }
    } else {
        if (x[i] > y[i]) {
            if (sg[i] == 1) sg[i] = 2;
            else if (sg[i] == 2) sg[i] = 1;
            else if (sg[i] == 3) sg[i] = 4;
            else if (sg[i] == 4) sg[i] = 3;
            swap(x[i], y[i]);
        }
        x[cnt] = x[i];
        y[cnt] = y[i];
        sg[cnt] = sg[i];
        ++cnt;
    }
    k = cnt;
    N = 2 * n;
    REP(i, N) REP(j, N) re[i][j] = -1;
    REP(i, k) {
        re[x[i]][y[i]] = sg[i];
        int rev = sg[i];
        if (rev == 1) rev = 2;
        else if (rev == 2) rev = 1;
        else if (rev == 3) rev = 4;
        else if (rev == 4) rev = 3;
        re[y[i]][x[i]] = rev;
    }
    LL ans = 0;
    REP(l, N - 1) {
        int r = n - 2 - l;
        bool ok = true;
        REP(i, l) REP(j, 2) if (re[i][l + j] == 0 || re[i][l + j] == 2 || re[i][l + j] == 4) {
            ok = false;
        }
        REP(i, r) REP(j, 2) if (re[l + j][l + 2 + i] == 0 || re[l + j][l + 2 + i] == 1 || re[l + j][l + 2 + i] == 3) {
            ok = false;
        }
        if (re[l][l + 1] == 1 || re[l][l + 1] == 2) {
            ok = false;
        }
        if (!ok) {
            continue;
        }
        REP(i, N) REP(j, N) d[i][j] = 0;
        d[l][l + 1] = 1;
        REP(i, n - 1) {
            memset(nd, 0, sizeof nd);
            REP(i, N) REP(j, N) if (d[i][j]) {
                int ii = i - 1, jj = i - 2;
                if (jj >= 0) {
                    if (isOK(i, j, ii, jj))
                        nd[i - 2][j] += d[i][j];
                }
                ii = j + 1, jj = j + 2;
                if (jj < N) {
                    if (isOK(i, j, ii, jj))
                        nd[i][j + 2] += d[i][j];
                }
                ii = i - 1, jj = j + 1;
                if (ii >= 0 && jj < N) {
                    if (isOK(i, j, ii, jj))
                        nd[i - 1][j + 1] += d[i][j];
                }
            }
            memcpy(d, nd, sizeof d);
        }
        ans += d[0][N - 1];
    }
    printf("%I64d\n", ans);
    return 0;
}