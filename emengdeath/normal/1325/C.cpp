#include <algorithm>
#include <cstdio>
#include <vector>
#include <numeric>
using namespace std;
const int N = 1e5 + 10;
vector<pair<int, int> >g[N];
int deep[N];
int faid[N];
int n;
int id[N];
int ans[N];
void dfs(int x, int fa) {
    for (auto u:g[x])
    if (u.first != fa){
        faid[u.first] = u.second;
        dfs(u.first, x);
        deep[x] = max(deep[x], deep[u.first] + 1);
    }
}
int main() {
    scanf("%d", &n);
    for (int i= 1 ; i < n; i ++ ){
        int x, y;
        scanf("%d %d", &x,&y);
        g[x].push_back({y, i});
        g[y].push_back({x, i});
    }
    int x = 1;
    for (int i = 1; i <= n; i ++)
        if (g[i].size() > 1){
            x = i;
            break;
        }
    dfs(x, 0);
    for (int i = 1; i <= n; i ++)
        id[i] =i;
    sort(id + 1, id + n + 1, [](int x,int y) {
        return deep[x]<deep[y];
    });
    for (int i = 1; i < n; i++)
        ans[faid[id[i]]] = i - 1;
    for (int i = 1; i < n; i ++)
        printf("%d\n", ans[i]);
    return 0;
}