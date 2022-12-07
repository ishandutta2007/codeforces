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

int sz[2], k, q;
int pos[200000][2];
int from[200000][2], to[200000][2];
bool ok[200000] = {};
int ord[200000], qord[200000];
int st[1 << 19];
const int off = 1 << 18;
const int INF = 1e9;

void stBuild() {
    memset(st, 0, sizeof st);
}

void stUpdate(int pos, int val) {
    st[off + pos] = val;
    for (pos = (pos + off) >> 1; pos >= 1; pos >>= 1)
        st[pos] = min(st[pos << 1], st[(pos << 1) | 1]);
}

int stGet(int v, int L, int R, int l, int r) {
    if (l > r) return INF;
    if (L == l && R == r) return st[v];
    int mid = (L + R) >> 1;
    return min(stGet(v << 1, L, mid, l, min(r, mid)),
               stGet((v << 1) | 1, mid + 1, R, max(l, mid + 1), r));
}

bool cmp(const int &lhs, const int &rhs) {
    return pos[lhs][0] < pos[rhs][0];
}

bool qcmp(const int &lhs, const int &rhs) {
    return to[lhs][0] < to[rhs][0];
}

int main() {
    scanf("%d%d%d%d", sz, sz + 1, &k, &q);
    REP(i, k) scanf("%d%d", pos[i], pos[i] + 1);
    REP(qq, q) scanf("%d%d%d%d", from[qq], from[qq] + 1, to[qq], to[qq] + 1);
    REP(z, 2) {
        REP(i, k) ord[i] = i;
        sort(ord, ord + k, cmp);
        REP(i, q) qord[i] = i;
        sort(qord, qord + q, qcmp);
        stBuild();
        int ind = 0, qind = 0;
        for (int i = 1; i <= 100000; ++i) {
            while (ind < k && pos[ord[ind]][0] == i) {
                stUpdate(pos[ord[ind]][1], pos[ord[ind]][0]);
                ++ind;
            }
            while (qind < q && to[qord[qind]][0] == i) {
                if (stGet(1, 0, off - 1, from[qord[qind]][1], to[qord[qind]][1]) >= from[qord[qind]][0]) {
                    ok[qord[qind]] = true;
                }
                ++qind;
            }
        }
        REP(i, k) swap(pos[i][0], pos[i][1]);
        REP(i, q) swap(from[i][0], from[i][1]), swap(to[i][0], to[i][1]);
    }
    REP(i, q) if (ok[i]) printf("YES\n");
    else printf("NO\n");
    return 0;
}