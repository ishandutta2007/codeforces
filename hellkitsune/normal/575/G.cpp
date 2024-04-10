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
vector<int> g[10][100000];
int zdist[100000], zpre[100000];
int pre[100000], pred[100000];
queue<int> q;
vector<pair<int, bool> > vq, nq;
const int INF = 1e9;
vector<int> ans;

int main() {
    scanf("%d%d", &n, &m);
    REP(i, m) {
        int from, to, w;
        scanf("%d%d%d", &from, &to, &w);
        g[w][from].pb(to);
        g[w][to].pb(from);
    }
    REP(i, n) zdist[i] = INF;
    zdist[n - 1] = 0;
    q.push(n - 1);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : g[0][v]) if (zdist[to] == INF) {
            zdist[to] = zdist[v] + 1;
            zpre[to] = v;
            q.push(to);
        }
    }
    if (zdist[0] != INF) {
        printf("0\n%d\n0", zdist[0] + 1);
        for (int v = 0; v != n - 1; v = zpre[v]) {
            printf(" %d", zpre[v]);
        }
        printf("\n");
        return 0;
    }
    REP(i, n) pre[i] = -1;
    pre[0] = 0;
    vq.pb(mp(0, false));
    while (true) {
        REP(i, 10) {
            bool eq = false;
            for (auto v : vq) {
                if (!v.second) eq = false;
                for (int to : g[i][v.first]) if (pre[to] == -1) {
                    pre[to] = v.first;
                    pred[to] = i;
                    nq.pb(mp(to, eq));
                    eq = true;
                }
            }
        }
        vq.clear();
        swap(vq, nq);
        int best = -1;
        for (auto v : vq) {
            if (best != -1 && !v.second) break;
            if (zdist[v.first] != INF && (best == -1 || zdist[best] > zdist[v.first])) {
                best = v.first;
            }
        }
        if (best != -1) {
            ans.pb(best);
            for (int v = best; v != 0; v = pre[v]) {
                ans.pb(pre[v]);
                printf("%d", pred[v]);
            }
            printf("\n");
            reverse(ans.begin(), ans.end());
            for (int v = best; v != n - 1; v = zpre[v]) {
                ans.pb(zpre[v]);
            }
            printf("%d\n", (int)ans.size());
            for (int x : ans) printf("%d ", x);
            printf("\n");
            return 0;
        }
    }
    return 0;
}