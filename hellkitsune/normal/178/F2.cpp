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

int n, k;
char s[505];
int t[100005][26] = {}, cnt[100005] = {}, p[100005], pind[100005], dpos[100005], mul[100005];
bool used[100005];
int sz = 1, dsz = 0;
int d[2005][2005];
int f[2005], g[2005];

int main() {
    scanf("%d%d", &n, &k);
    cnt[0] = n;
    REP(i, n) {
        scanf("%s", s);
        int len = strlen(s);
        int pos = 0;
        REP(i, len) {
            int let = s[i] - 'a';
            if (!t[pos][let]) {
                t[pos][let] = sz;
                p[sz] = pos;
                pind[sz] = let;
                ++sz;
            }
            pos = t[pos][let];
            ++cnt[pos];
        }
    }
    REP(i, sz) used[i] = true, mul[i] = 1;
    for (int i = sz - 1; i > 0; --i) {
        REP(j, 26) if (t[i][j] && cnt[t[i][j]] == cnt[i]) {
            t[p[i]][pind[i]] = t[i][j];
            ++mul[t[i][j]];
            used[i] = false;
            break;
        }
    }
    for (int i = sz - 1; i >= 0; --i) if (used[i]) {
        dpos[i] = dsz;
        int mx = min(k, cnt[i]), cur = 0;
        REP(j, mx + 1) f[j] = 0;
        REP(j, 26) if (t[i][j]) {
            int pos = t[i][j];
            int mx2 = min(k, cnt[pos]);
            int *h = d[dpos[pos]];
            int newCur = min(mx, cur + mx2);
            for (int q = 0; q <= newCur; ++q) g[q] = 0;
            for (int q = 0; q <= cur; ++q) {
                int upTo = min(mx2, mx - q);
                for (int w = 0; w <= upTo; ++w) {
                    g[q + w] = max(g[q + w], f[q] + h[w]);
                }
            }
            cur = newCur;
            for (int q = 0; q <= cur; ++q) f[q] = g[q];
        }
        d[dsz][0] = f[0];
        for (int j = 1; j <= mx; ++j) d[dsz][j] = max(d[dsz][j - 1], f[j]);
        if (i) REP(j, mx + 1) d[dsz][j] += mul[i] * (j * (j - 1)) / 2;
        ++dsz;
    }
    cout << d[dpos[0]][k] << endl;
    return 0;
}