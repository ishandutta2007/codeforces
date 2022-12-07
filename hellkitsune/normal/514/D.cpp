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

int n, m, k;
int a[5][100005], st[5][17][100005];
int p[100005];

void buildSt() {
    int curP = 0;
    REP(i, 100005) {
        if ((1 << (curP + 1)) < i) {
            ++curP;
        }
        p[i] = curP;
    }
    REP(z, m) {
        REP(i, n) st[z][0][i] = a[z][i];
        for (int i = 1; i < 17; ++i) {
            REP(j, n - (1 << i) + 1) {
                st[z][i][j] = max(st[z][i - 1][j], st[z][i - 1][j + (1 << (i - 1))]);
            }
        }
    }
}

int getSt(int z, int from, int to) {
    int curP = p[to - from + 1];
    return max(st[z][curP][from], st[z][curP][to - (1 << curP) + 1]);
}

int best = -1, bestD[5] = {}, curD[5];

bool alright(int from, int to) {
    REP(i, m) curD[i] = getSt(i, from, to);
    int tot = 0;
    REP(i, m) tot += curD[i];
    return tot <= k;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    REP(i, n) REP(j, m) {
        scanf("%d", a[j] + i);
    }
    buildSt();
    int l = 0;
    REP(r, n) {
        while (l <= r && !alright(l, r)) ++l;
        if (l <= r && r - l + 1 > best) {
            best = r - l + 1;
            REP(i, m) bestD[i] = curD[i];
        }
    }
    REP(i, m) cout << bestD[i] << ' ';
    cout << endl;
    return 0;
}