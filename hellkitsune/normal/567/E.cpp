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
vector<PII> g[100000], rev[100000];
int from[100000], to[100000], w[100000];
LL dist[100000] = {}, distR[100000] = {};
const LL INF = 1e14;
int s, t;
int ways[2][100000] = {}, waysR[2][100000] = {};
const int MOD[2] = {1000000007, 1000000009};

struct Cmp {
    inline bool operator()(const int &lhs, const int &rhs) const {
        if (dist[lhs] != dist[rhs]) return dist[lhs] < dist[rhs];
        return lhs < rhs;
    }
};

struct CmpR {
    inline bool operator()(const int &lhs, const int &rhs) const {
        if (distR[lhs] != distR[rhs]) return distR[lhs] < distR[rhs];
        return lhs < rhs;
    }
};

set<int, Cmp> q;
set<int, CmpR> qr;

int main() {
    scanf("%d%d%d%d", &n, &m, &s, &t), --s, --t;
    REP(i, m) {
        scanf("%d%d%d", from + i, to + i, w + i), --from[i], --to[i];
        g[from[i]].pb(mp(to[i], w[i]));
        rev[to[i]].pb(mp(from[i], w[i]));
    }
    REP(i, n) dist[i] = INF;
    dist[s] = 0;
    q.insert(s);
    ways[0][s] = ways[1][s] = 1;
    while (!q.empty()) {
        int v = *q.begin();
        q.erase(q.begin());
        for (PII to : g[v]) if (dist[to.first] > dist[v] + to.second) {
            q.erase(to.first);
            dist[to.first] = dist[v] + to.second;
            REP(z, 2) ways[z][to.first] = ways[z][v];
            q.insert(to.first);
        } else if (dist[to.first] == dist[v] + to.second) {
            REP(z, 2) {
                ways[z][to.first] += ways[z][v];
                if (ways[z][to.first] >= MOD[z]) {
                    ways[z][to.first] -= MOD[z];
                }
            }
        }
    }
    REP(i, n) distR[i] = INF;
    distR[t] = 0;
    qr.insert(t);
    waysR[0][t] = waysR[1][t] = 1;
    while (!qr.empty()) {
        int v = *qr.begin();
        qr.erase(qr.begin());
        for (PII to : rev[v]) if (distR[to.first] > distR[v] + to.second) {
            qr.erase(to.first);
            distR[to.first] = distR[v] + to.second;
            REP(z, 2) waysR[z][to.first] = waysR[z][v];
            qr.insert(to.first);
        } else if (distR[to.first] == distR[v] + to.second) {
            REP(z, 2) {
                waysR[z][to.first] += waysR[z][v];
                if (waysR[z][to.first] >= MOD[z]) {
                    waysR[z][to.first] -= MOD[z];
                }
            }
        }
    }
    LL tot = dist[t];
    REP(i, m) {
        if (dist[from[i]] + w[i] + distR[to[i]] == tot) {
            bool flag = true;
            REP(z, 2) {
                int curW = (LL)ways[z][from[i]] * waysR[z][to[i]] % MOD[z];
                if (curW != ways[z][t]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                printf("YES\n");
            } else if (w[i] > 1) {
                printf("CAN 1\n");
            } else {
                printf("NO\n");
            }
        } else {
            LL targ = tot - dist[from[i]] - distR[to[i]] - 1;
            if (targ < 1) {
                printf("NO\n");
            } else {
                printf("CAN %d\n", (int)(w[i] - targ));
            }
        }
    }
    return 0;
}