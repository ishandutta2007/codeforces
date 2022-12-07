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

int n, N;
int x[400002], y[400002];
char ans[400005];
bool oddX[200002], oddY[200002];
vector<PII> g[400002];
int pos[400002] = {};
bool used[400002] = {}, usedE[400002] = {};
vector<int> ord;
const int MX = 200000;
const int NMX = 200001;

void dfs(int v, int prevEdge = -1) {
    used[v] = true;
    while (pos[v] < (int)g[v].size()) {
        PII to = g[v][pos[v]++];
        if (!usedE[to.second]) {
            usedE[to.second] = true;
            dfs(to.first, to.second);
        }
    }
    if (prevEdge != -1) ord.pb(prevEdge);
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d%d", x + i, y + i), --x[i], --y[i], oddX[x[i]] ^= 1, oddY[y[i]] ^= 1;
    N = n;
    int posX = 0, posY = 0;
    while (true) {
        while (posX < MX && !oddX[posX]) ++posX;
        while (posY < MX && !oddY[posY]) ++posY;
        if (posX == MX && posY == MX) break;
        if (posX == MX) {
            x[N] = MX, y[N] = posY, ++N;
            ++posY;
        } else if (posY == MX) {
            x[N] = posX, y[N] = MX, ++N;
            ++posX;
        } else {
            x[N] = posX, y[N] = posY, ++N;
            ++posX, ++posY;
        }
    }
    REP(i, N) g[x[i]].pb(mp(y[i] + NMX, i));
    REP(i, N) g[y[i] + NMX].pb(mp(x[i], i));
    REP(i, NMX * 2) used[i] = false;
    REP(i, NMX * 2) if (!used[i]) {
        dfs(i);
    }
    char c = 'r';
    for (int x : ord) {
        ans[x] = c;
        c = (c == 'r') ? 'b' : 'r';
    }
    ans[n] = '\0';
    printf("%s\n", ans);
    return 0;
}