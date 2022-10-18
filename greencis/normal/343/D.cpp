#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

vector<int> g[500005];
int n,q,a,b;
int pr[500005],tin[500005],tout[500005],timer;
set<int> s;

void dfs(int v, int p) {
    pr[v] = p;
    tin[v] = ++timer;
    for (int i = 0; i < g[v].size(); ++i)
        if (g[v][i] != p)
            dfs(g[v][i], v);
    tout[v] = ++timer;
    if (tin[v] + 1 == tout[v]) s.insert(tin[v]);
}

bool isempty(int v) {
    set<int>::iterator it = s.lower_bound(tin[v]);
    return it != s.end() && (*it) <= tout[v];
}

int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n-1; ++i) {
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0);
    scanf("%d",&q);
    while (q--) {
        scanf("%d%d",&a,&b);
        if (a == 1) {
            if (pr[b] && isempty(pr[b])) s.insert(tin[pr[b]]);
            s.erase(s.lower_bound(tin[b]), s.upper_bound(tout[b]));
        } else if (a == 2) {
            s.insert(tin[b]);
        } else {
            printf("%d\n", !isempty(b));
        }
    }

    return 0;
}