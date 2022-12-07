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

int len;
char alp[33], s[222];
int n, m;
bool g[200][200][2][2] = {};
int con[200][2];
char minV, minC;
int f;

bool go(int pos);

bool check(int pos, int col) {
    bool ok = true;
    for (int i = pos + 1; i < n; ++i) {
        if (g[pos][i][col][0]) ++con[i][0];
        if (g[pos][i][col][1]) ++con[i][1];
        if (con[i][0] && con[i][1]) {
            ok = false;
            for (int j = pos + 1; j <= i; ++j) {
                if (g[pos][j][col][0]) --con[j][0];
                if (g[pos][j][col][1]) --con[j][1];
            }
            break;
        }
    }
    if (ok) {
        if (!go(pos + 1)) {
            ok = false;
            for (int i = pos + 1; i < n; ++i) {
                if (g[pos][i][col][0]) --con[i][0];
                if (g[pos][i][col][1]) --con[i][1];
            }
        }
    }
    return ok;
}

bool go(int pos) {
    if (pos == n) {
        return true;
    }
    if (minV < minC) {
        if (con[pos][1] == 0) {
            s[pos] = minV;
            if (check(pos, 0)) return true;
        }
        if (con[pos][0] == 0) {
            s[pos] = minC;
            if (check(pos, 1)) return true;
        }
    } else {
        if (con[pos][0] == 0) {
            s[pos] = minC;
            if (check(pos, 1)) return true;
        }
        if (con[pos][1] == 0) {
            s[pos] = minV;
            if (check(pos, 0)) return true;
        }
    }
    return false;
}

bool solve(int pos) {
    f = pos;
    REP(i, pos) for (int j = i + 1; j < pos; ++j) {
        int v1 = alp[s[i] - 'a'] == 'C';
        int v2 = alp[s[j] - 'a'] == 'C';
        if (g[i][j][v1][1 ^ v2]) return false;
    }
    for (int i = pos; i < n; ++i) con[i][0] = con[i][1] = 0;
    REP(i, pos) for (int j = pos; j < n; ++j) {
        int v = alp[s[i] - 'a'] == 'C';
        if (g[i][j][v][0]) ++con[j][0];
        if (g[i][j][v][1]) ++con[j][1];
    }
    for (int i = pos; i < n; ++i) if (con[i][0] && con[i][1]) return false;
    return go(pos);
}

int main() {
    scanf("%s", alp);
    len = strlen(alp);
    minV = minC = 'z' + 1;
    REP(i, len) if (alp[i] == 'V') {
        minV = 'a' + i;
        break;
    }
    REP(i, len) if (alp[i] == 'C') {
        minC = 'a' + i;
        break;
    }
    scanf("%d%d", &n, &m);
    REP(i, m) {
        int pos1, v1, pos2, v2;
        scanf("%d%s", &pos1, s), --pos1;
        v1 = s[0] == 'C';
        scanf("%d%s", &pos2, s), --pos2;
        v2 = s[0] == 'C';
        g[pos1][pos2][v1][v2] = true;
        g[pos2][pos1][1 ^ v2][1 ^ v1] = true;
    }
    scanf("%s", s);
    bool ok = true;
    REP(i, n) if (ok) for (int j = i + 1; j < n; ++j) {
        int v1 = alp[s[i] - 'a'] == 'C';
        int v2 = alp[s[j] - 'a'] == 'C';
        if (g[i][j][v1][1 ^ v2]) {
            ok = false;
            break;
        }
    }
    if (ok) {
        printf("%s\n", s);
        return 0;
    }
    if (minV > 'z' || minC > 'z') {
        printf("-1\n");
        return 0;
    }
    REP(k, n) REP(i, n) REP(j, n) REP(p, 2) REP(q, 2) REP(r, 2) {
        if (g[i][k][p][q] && g[k][j][q][r]) {
            g[i][j][p][r] = true;
        }
    }
    REP(i, n) REP(j, n) if (g[i][j][0][0] && g[i][j][0][1] && g[i][j][1][0] && g[i][j][1][1]) {
        printf("-1\n");
        return 0;
    }
    for (int i = n - 1; i >= 0; --i) {
        bool was[2] = {};
        for (char c = s[i] + 1; c < 'a' + len; ++c) {
            if (alp[c - 'a'] == 'V') {
                if (was[0]) continue;
                was[0] = true;
            } else {
                if (was[1]) continue;
                was[1] = true;
            }
            s[i] = c;
            if (solve(i + 1)) {
                printf("%s\n", s);
                return 0;
            }
        }
    }
    printf("-1\n");
    return 0;
}