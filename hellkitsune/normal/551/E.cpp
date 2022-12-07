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

LL a[500000];
map<int, int> l[1000], r[1000];
int n, q, x, N;
LL off[1000] = {};

void mapSegment(int i) {
    l[i].clear();
    r[i].clear();
    int from = i << 9;
    int to = min(from + 512, n);
    for (int j = from; j < to; ++j) if (a[j] + off[i] <= 1000000000) {
        auto it = r[i].find(a[j]);
        if (it == r[i].end()) {
            l[i][a[j]] = j;
            r[i][a[j]] = j;
        } else {
            it->second = j;
        }
    }
}

int main() {
    scanf("%d%d", &n, &q);
    REP(i, n) scanf("%d", &x), a[i] = x;
    N = (n + 511) >> 9;
    for (int i = 0; i < N; ++i) {
        mapSegment(i);
    }
    REP(query, q) {
        int qq;
        scanf("%d", &qq);
        if (qq == 1) {
            int ql, qr, val;
            scanf("%d%d%d", &ql, &qr, &val), --ql, --qr;
            int fi = -1, la = -1;
            for (int i = ql; i <= qr; ) {
                if ((i & 511) || (i + 511 > qr)) {
                    a[i] += val;
                    if (fi == -1) {
                        fi = i >> 9;
                    }
                    la = i >> 9;
                    ++i;
                } else {
                    off[i >> 9] += val;
                    i += 512;
                }
            }
            if (fi != -1) mapSegment(fi);
            if (la != fi) mapSegment(la);
        } else {
            int ql = -1, qr = -1, val;
            scanf("%d", &val);
            for (int i = 0; i < N; ++i) {
                LL v = val - off[i];
                if (v < 0 || v > 1000000000) continue;
                auto it = l[i].find(v);
                if (it != l[i].end()) {
                    ql = it->second;
                    break;
                }
            }
            if (ql != -1) for (int i = N - 1; i >= 0; --i) {
                LL v = val - off[i];
                if (v < 0 || v > 1000000000) continue;
                auto it = r[i].find(v);
                if (it != r[i].end()) {
                    qr = it->second;
                    break;
                }
            }
            if (ql == -1) printf("%d\n", -1);
            else printf("%d\n", qr - ql);
        }
    }
    return 0;
}