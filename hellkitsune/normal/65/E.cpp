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

struct S {
    int ind;
    bool staircase;
    S(int ind, bool staircase) : ind(ind), staircase(staircase) {}
    S() {}
};

int n, m;
vector<PII> g[100000];
bool can[100000] = {};
int vis[100000] = {};
int ind = 0;
bool flag = false;
int sind[200000], sfrom[200000], sto[200000], sc = 0;
vector<S> ans;

void mark(int v) {
    can[v] = true;
    for (PII to : g[v]) if (!can[to.first]) {
        mark(to.first);
    }
}

int findUnmarked() {
    while (ind < n && (can[ind] || (!flag && g[ind].empty()))) ++ind;
    if (ind == n && !flag) {
        flag = true;
        ind = 0;
        return findUnmarked();
    }
    return ind;
}

void dfs(int v) {
    ans.pb(S(v, false));
    vis[v] = 1;
    for (PII to : g[v]) {
        if (vis[to.first] == 0) {
            dfs(to.first);
            ans.pb(S(v, false));
        }
        if (vis[to.first] == 2) {
            int cur = findUnmarked();
            if (cur != n) {
                sind[sc] = to.second;
                sfrom[sc] = v;
                sto[sc] = cur;
                ans.pb(S(sc++, true));
                mark(cur);
                dfs(cur);
                ans.pb(S(v, false));
            }
        }
    }
    vis[v] = 2;
}

int tin[100000], fup[100000], timer = 0;
int bestInd = -1, bestFrom, bestTo;
void dfs2(int v, int p) {
    tin[v] = fup[v] = timer++;
    for (PII to : g[v]) if (to.second != p) {
        if (tin[to.first] == -1) {
            dfs2(to.first, to.second);
            if (fup[to.first] < tin[to.first] && bestInd == -1) {
                bestInd = to.second;
                bestFrom = v;
                bestTo = to.first;
            }
            fup[v] = min(tin[v], fup[to.first]);
        } else {
            if (bestInd == -1) {
                bestInd = to.second;
                bestFrom = v;
                bestTo = to.first;
            }
            fup[v] = min(tin[v], tin[to.first]);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    if (n == 1) {
        printf("YES\n0\n1 1\n");
        return 0;
    }
    REP(i, m) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(mp(to, i));
        g[to].pb(mp(from, i));
    }
    int st = 0;
    if (g[0].empty()) {
        REP(i, n) tin[i] = -1;
        REP(i, n) if (tin[i] == -1 && bestInd == -1) {
            dfs2(i, -1);
        }
        if (bestInd == -1) {
            REP(i, n) if ((int)g[i].size() > 1) {
                bestInd = g[i][0].second;
                bestFrom = i;
                bestTo = g[i][0].first;
                break;
            }
        }
        if (bestInd == -1) {
            printf("NO\n");
            return 0;
        }
        g[bestFrom].erase(find(g[bestFrom].begin(), g[bestFrom].end(), mp(bestTo, bestInd)));
        g[bestTo].erase(find(g[bestTo].begin(), g[bestTo].end(), mp(bestFrom, bestInd)));
        st = bestFrom;
        ans.pb(S(0, false));
        sind[0] = bestInd;
        sfrom[0] = bestFrom;
        sto[0] = 0;
        ans.pb(S(0, true));
        ++sc;
        vis[0] = can[0] = true;
    }
    mark(st);
    dfs(st);
    REP(i, n) if (!vis[i]) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    int cnt = 0;
    for (S x : ans) if (x.staircase) ++cnt;
    printf("%d\n", cnt);
    for (int beg = 0; beg < (int)ans.size(); ) {
        if (ans[beg].staircase) {
            int ind = ans[beg].ind;
            printf("%d %d %d\n", sind[ind] + 1, sfrom[ind] + 1, sto[ind] + 1);
            ++beg;
        } else {
            int end = beg + 1;
            while (end < (int)ans.size() && !ans[end].staircase) ++end;
            printf("%d", end - beg);
            for (int i = beg; i < end; ++i) {
                printf(" %d", ans[i].ind + 1);
            }
            printf("\n");
            beg = end;
        }
    }
    return 0;
}