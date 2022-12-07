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

int n, l;
LL t[200001], x[200001], y[200001];
int resX[2000001], resY[2000001];
int g[2000001];

bool solve(LL *x, int *res) {
    REP(i, l) g[i] = -1;
    int dLo = -l, dHi = l;
    REP(i, n) {
        int tt = t[i] % l;
        if (g[tt] == -1) {
            g[tt] = i;
        } else {
            int j = g[tt];
            LL a = x[i] - x[j];
            LL b = (t[i] - t[j]) / l;
            if (a % b != 0) return false;
            LL d = a / b;
            if (d > l || d < -l) return false;
            if ((d ^ l) & 1) return false;
            if (dLo == dHi && dLo != d) return false;
            dLo = dHi = d;
        }
    }
    int pre = 0;
    g[l] = g[0];
    for (int i = 1; i <= l; ++i) if (g[i] != -1) {
        if (i == l && pre == 0) break;
        int p = g[pre];
        int q = g[i];
        int v = i - pre;
        LL whole = (t[q] - t[p] - v) / l;
        if (((x[q] - x[p]) ^ (t[q] - t[p])) & 1) return false;
        //d = (x[q] - x[p] + [-v;v]) / whole;
        if (whole == 0) {
            if (abs(x[q] - x[p]) > v) return false;
            pre = i;
            continue;
        }
        LL xp = x[p], xq = x[q];
        if (whole < 0) {
            whole = -whole;
            swap(xp, xq);
        }
        LL tmp = (xq - xp - v) / whole;
        if ((xq - xp - v) % whole != 0 && xq - xp - v > 0)
            ++tmp;
        if (tmp < -l) tmp = -l - 1;
        if (tmp > l) tmp = l + 1;
        dLo = max(dLo, (int)tmp);
        tmp = (xq - xp + v) / whole;
        if ((xq - xp + v) % whole != 0 && xq - xp + v < 0)
            --tmp;
        if (tmp < -l) tmp = -l - 1;
        if (tmp > l) tmp = l + 1;
        dHi = min(dHi, (int)tmp);
        pre = i;
    }
    if ((dLo ^ l) & 1) ++dLo;
    if ((dHi ^ l) & 1) --dHi;
    if (dLo > dHi) return false;
    int d = dLo;
    res[0] = 0, res[l] = d;
    pre = 0;
    for (int i = 1; i <= l; ++i) if (g[i] != -1) {
        if (i == l && pre == 0) break;
        int p = g[pre];
        int q = g[i];
        int v = i - pre;
        LL whole = (t[q] - t[p] - v) / l;
        //d * whole + x[p] + dif = x[q]
        LL dif = x[q] - x[p] - d * whole;
        for (int j = pre + 1; j <= i; ++j) {
            if (dif > 0) --dif, res[j] = res[j - 1] + 1;
            else ++dif, res[j] = res[j - 1] - 1;
        }
        assert(dif == 0);
        pre = i;
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &l), ++n;
    t[0] = x[0] = y[0] = 0;
    for (int i = 1; i < n; ++i) {
        scanf("%I64d%I64d%I64d", t + i, x + i, y + i);
        x[i] += y[i];
        y[i] = x[i] - 2 * y[i];
    }
    if (!solve(x, resX) || !solve(y, resY)) {
        printf("NO\n");
        return 0;
    }
    for (int i = 1; i <= l; ++i) {
        int dx = resX[i] - resX[i - 1];
        int dy = resY[i] - resY[i - 1];
        if (dx == -1) {
            if (dy == -1) printf("L");
            else printf("D");
        } else {
            if (dy == -1) printf("U");
            else printf("R");
        }
    }
    printf("\n");
    return 0;
}