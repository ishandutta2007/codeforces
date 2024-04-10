#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)

int n, q, u;
int p[310000];
vector<int> g[310000];
int sub[310000];
int ans[310000];

void dfsSize(int v) {
    sub[v] = 1;
    for (int x : g[v]) {
        dfsSize(x);
        sub[v] += sub[x];
    }
}

void dfsCentr(int v) {
    for (int x : g[v]) dfsCentr(x);
    ans[v] = g[v].empty() ? v : ans[g[v][0]];
    while (sub[ans[v]]*2 < sub[v]) ans[v] = p[ans[v]];
}

int main()
{
    scanf("%d %d", &n, &q);
    rep(i,1,n) {
        scanf("%d", &p[i]);p[i]--;
        g[p[i]].push_back(i);
    }

    dfsSize(0);
    rep(i,0,n) sort(g[i].begin(),g[i].end(), [](int a, int b) { return sub[a] > sub[b]; });

    dfsCentr(0);
    rep(i,0,q) {
        scanf("%d", &u); u--;
        printf("%d\n", ans[u]+1);
    }
}