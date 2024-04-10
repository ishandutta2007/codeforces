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

int n, m;
char s[1000][1005];
int xpos[1000], ypos[1000];
int empt = 0;
LL tot = 0;

int main() {
    scanf("%d%d", &n, &m);
    empt = n * m;
    REP(i, n) scanf("%s", s[i]);
    REP(i, n) {
        xpos[i] = -1;
        REP(j, m) if (s[i][j] == 'X') {
            xpos[i] = j;
            --empt;
            break;
        }
    }
    REP(j, m) {
        ypos[j] = -1;
        REP(i, n) if (s[i][j] == 'X') {
            ypos[j] = i;
            break;
        }
    }
    REP(i, n) for (int j = i + 1; j < n; ++j) {
        int cnt1, cnt2;
        cnt1 = cnt2 = m;
        if (xpos[i] != -1) --cnt1;
        if (xpos[j] != -1) --cnt2;
        tot += (LL)cnt1 * cnt2 * (j - i) * 2;
    }
    REP(i, m) for (int j = i + 1; j < m; ++j) {
        int cnt1, cnt2;
        cnt1 = cnt2 = n;
        if (ypos[i] != -1) --cnt1;
        if (ypos[j] != -1) --cnt2;
        tot += (LL)cnt1 * cnt2 * (j - i) * 2;
    }
    for (int beg = 0; beg < n; ) if (xpos[beg] != -1) {
        int end = beg + 1;
        while (end < n && xpos[end] > xpos[end - 1]) ++end;
        for (int i = beg; i < end; ++i) for (int j = i; j < end; ++j) {
            int mul = 4;
            if (j == i) mul = 2;
            tot += xpos[i] * (m - 1 - xpos[j]) * mul;
        }
        beg = end;
    } else {
        ++beg;
    }
    for (int beg = 0; beg < n; ) if (xpos[beg] != -1) {
        int end = beg + 1;
        while (end < n && xpos[end] != -1 && xpos[end] < xpos[end - 1]) ++end;
        for (int i = beg; i < end; ++i) for (int j = i; j < end; ++j) {
            int mul = 4;
            if (j == i) mul = 2;
            tot += (m - 1 - xpos[i]) * xpos[j] * mul;
        }
        beg = end;
    } else {
        ++beg;
    }
    for (int beg = 0; beg < m; ) if (ypos[beg] != -1) {
        int end = beg + 1;
        while (end < m && ypos[end] > ypos[end - 1]) ++end;
        for (int i = beg; i < end; ++i) for (int j = i; j < end; ++j) {
            int mul = 4;
            if (j == i) mul = 2;
            tot += ypos[i] * (n - 1 - ypos[j]) * mul;
        }
        beg = end;
    } else {
        ++beg;
    }
    for (int beg = 0; beg < m; ) if (ypos[beg] != -1) {
        int end = beg + 1;
        while (end < m && ypos[end] != -1 && ypos[end] < ypos[end - 1]) ++end;
        for (int i = beg; i < end; ++i) for (int j = i; j < end; ++j) {
            int mul = 4;
            if (j == i) mul = 2;
            tot += (n - 1 - ypos[i]) * ypos[j] * mul;
        }
        beg = end;
    } else {
        ++beg;
    }
    double ans = tot / ((double)empt * empt);
    printf("%.12f\n", ans);
    return 0;
}