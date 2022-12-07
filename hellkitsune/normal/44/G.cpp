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
int x[100000], y[100000], xx[100000], yy[100000], z[100000], ord[100000], tmp[100000];
bool used[100000];
const int ROOT = 256, MASK = 255, BITS = 8;
vector<int> revX[400], revY[400];
set<int> se;
map<int, int> ma;
int mac;
int tot;

bool cmp(const int &lhs, const int &rhs) {
    return z[lhs] < z[rhs];
}

void rearr(int *x) {
    REP(i, n) tmp[i] = x[ord[i]];
    REP(i, n) x[i] = tmp[i];
}

unsigned char fen[400][515][515] = {};

inline void fenInc(unsigned char (*fen)[515], int y, int X) {
    for (; y < 515; y |= y + 1) {
        for (int x = X; x < 515; x |= x + 1) {
            ++fen[y][x];
        }
    }
}

inline void fenDec(unsigned char (*fen)[515], int y, int X) {
    for (; y < 515; y |= y + 1) {
        for (int x = X; x < 515; x |= x + 1) {
            --fen[y][x];
        }
    }
}

inline unsigned char fenGet(unsigned char (*fen)[515], int y, int X) {
    unsigned char ret = 0;
    for (; y >= 0; y = (y & (y + 1)) - 1) {
        for (int x = X; x >= 0; x = (x & (x + 1)) - 1) {
            ret += fen[y][x];
        }
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d%d%d%d%d", x + i, xx + i, y + i, yy + i, z + i);
    REP(i, n) ord[i] = i;
    sort(ord, ord + n, cmp);
    rearr(x);
    rearr(y);
    rearr(xx);
    rearr(yy);
    rearr(z);
    REP(i, n) used[i] = true;
    tot = (n + MASK) >> BITS;
    REP(i, tot) {
        int from = i << BITS;
        int to = min((i + 1) << BITS, n);
        for (int j = from; j < to; ++j) {
            se.insert(x[j]);
            se.insert(xx[j]);
        }
        mac = 0;
        vector<int> &reX = revX[i];
        reX.resize(se.size());
        for (int j : se) ma[j] = mac, reX[mac] = j, ++mac;
        for (int j = from; j < to; ++j) {
            x[j] = ma[x[j]];
            xx[j] = ma[xx[j]];
        }
        se.clear();
        ma.clear();
        for (int j = from; j < to; ++j) {
            se.insert(y[j]);
            se.insert(yy[j]);
        }
        mac = 0;
        vector<int> &reY = revY[i];
        reY.resize(se.size());
        for (int j : se) ma[j] = mac, reY[mac] = j, ++mac;
        for (int j = from; j < to; ++j) {
            y[j] = ma[y[j]];
            yy[j] = ma[yy[j]];
        }
        se.clear();
        ma.clear();
    }
    REP(i, n) {
        int pos = i >> BITS;
        fenInc(fen[pos], yy[i], xx[i]);
        fenInc(fen[pos], y[i], x[i]);
        fenDec(fen[pos], yy[i], x[i]);
        fenDec(fen[pos], y[i], xx[i]);
    }
    scanf("%d", &m);
    REP(i, m) {
        int cx, cy;
        scanf("%d%d", &cx, &cy);
        int ans = 0;
        REP(j, tot) {
            if (cx > revX[j].back() || cy > revY[j].back()) {
                continue;
            }
            int ax, axx, ay, ayy;
            auto it = lower_bound(revX[j].begin(), revX[j].end(), cx);
            if (*it == cx) {
                axx = it - revX[j].begin();
                ax = axx - 1;
            } else {
                axx = (it - revX[j].begin()) - 1;
                ax = axx;
            }
            it = lower_bound(revY[j].begin(), revY[j].end(), cy);
            if (*it == cy) {
                ayy = it - revY[j].begin();
                ay = ayy - 1;
            } else {
                ayy = (it - revY[j].begin()) - 1;
                ay = ayy;
            }
            bool ok = false;
            for (int ty = max(0, ay); ty <= ayy; ++ty) if (!ok) for (int tx = max(0, ax); tx <= axx; ++tx) {
                if (fenGet(fen[j], ty, tx) > 0) {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                int from = j << BITS;
                int to = min((j + 1) << BITS, n);
                for (int k = from; k < to; ++k) if (used[k] && revX[j][x[k]] <= cx && cx <= revX[j][xx[k]] &&
                                                    revY[j][y[k]] <= cy && cy <= revY[j][yy[k]]) {
                    used[k] = false;
                    ans = ord[k] + 1;
                    fenInc(fen[j], yy[k], x[k]);
                    fenInc(fen[j], y[k], xx[k]);
                    fenDec(fen[j], yy[k], xx[k]);
                    fenDec(fen[j], y[k], x[k]);
                    break;
                }
                assert(ans > 0);
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}