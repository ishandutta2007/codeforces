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

int st[3][1 << 18], sp[1 << 18], sz[1 << 18];
const int off = 1 << 17;
int n, m, k;
char s[100005];
const int MUL[3] = {13, 11, 17}, MOD[3] = {1000000007, 1000000009, 1000000123};
int mu[3][100001], sum[3][100001];
const char Z = '0' - 1;

void stBuild() {
    REP(i, 3) {
        REP(j, n) st[i][off + j] = s[j] - Z, sz[off + j] = 1;
        for (int j = off - 1; j >= 1; --j) {
            st[i][j] = (st[i][j << 1] + (LL)st[i][(j << 1) | 1] * mu[i][sz[j << 1]]) % MOD[i];
            sz[j] = sz[j << 1] << 1;
        }
    }
    memset(sp, -1, sizeof sp);
}

void stPush(int v, int sz) {
    for (int i = v << 1; i <= ((v << 1) | 1); ++i) {
        REP(j, 3) st[j][i] = (LL)sum[j][sz] * sp[v] % MOD[j];
        if (sz > 1) sp[i] = sp[v];
    }
    sp[v] = -1;
}

int updVal = 1;
void stAssign(int v, int L, int R, int l, int r) {
    if (L == l && R == r) {
        REP(i, 3) st[i][v] = (LL)sum[i][R - L + 1] * updVal % MOD[i];
        if (L != R) sp[v] = updVal;
        return;
    }
    int mid = (L + R) >> 1;
    if (sp[v] >= 0) stPush(v, R - mid);
    if (l <= mid) stAssign(v << 1, L, mid, l, min(r, mid));
    if (r > mid) stAssign((v << 1) | 1, mid + 1, R, max(l, mid + 1), r);
    REP(i, 3) st[i][v] = (st[i][v << 1] + (LL)st[i][(v << 1) | 1] * mu[i][R - mid]) % MOD[i];
}

int stRes[2], stCnt;

void stGet(int v, int L, int R, int l, int r) {
    if (l > r) return;
    if (L == l && R == r) {
        REP(i, 3) stRes[i] = (stRes[i] + (LL)mu[i][stCnt] * st[i][v]) % MOD[i];
        stCnt += R - L + 1;
        return;
    }
    int mid = (L + R) >> 1;
    if (sp[v] >= 0) stPush(v, R - mid);
    if (l <= mid) stGet(v << 1, L, mid, l, min(r, mid));
    if (r > mid) stGet((v << 1) | 1, mid + 1, R, max(l, mid + 1), r);
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    REP(i, 3) {
        mu[i][0] = 1;
        sum[i][0] = 0;
        REP(j, n) {
            mu[i][j + 1] = (LL)mu[i][j] * MUL[i] % MOD[i];
            sum[i][j + 1] = sum[i][j] + mu[i][j];
            if (sum[i][j + 1] >= MOD[i]) sum[i][j + 1] -= MOD[i];
        }
    }
    m += k;
    scanf("%s", s);
    stBuild();
    REP(i, m) {
        int qt, from, to, x;
        scanf("%d%d%d%d", &qt, &from, &to, &x), --from, --to;
        if (qt == 1) {
            updVal = x + 1;
            stAssign(1, 0, off - 1, from, to);
        } else {
            stRes[0] = stRes[1] = stCnt = 0;
            stGet(1, 0, off - 1, from, to - x);
            int z = stRes[0], y = stRes[1];
            stRes[0] = stRes[1] = stCnt = 0;
            stGet(1, 0, off - 1, from + x, to);
            if (stRes[0] == z && stRes[1] == y) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}