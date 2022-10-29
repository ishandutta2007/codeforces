#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
namespace Revocable_disjoint_set {
    const int N = 1e6;
    struct node{
        int sz, fa;
    }f[N];
    stack<int> record;//
    void init(int n){
        while (!record.empty()) record.pop();
        for (int i = 1; i <= n ; i ++)
            f[i].sz = 1, f[i].fa = i;
    }
    int root(int x){
        while (f[x].fa!=x) x = f[x].fa;
        return x;
    }
    bool merge(int x, int y) {
        if ((x = root(x)) == (y = root(y))) return 0;
        if (f[x].sz > f[y].sz) swap(x, y);
        f[x].fa = y;
        f[y].sz += f[x].sz;
        record.push(x);
        return 1;
    }
    void undo() {
        int x = record.top();
        record.pop();
        f[f[x].fa].sz -= f[x].sz;
        f[x].fa = x;
    }
    void undo_to_x(int x) {
        while (record.size() > x) undo();
    }
}
const int N = 1e6;
int n, m, k;
int ans[N];
int a[N][3];
vector<pair<pair<int, int> , int> > edge[N];
vector<pair<int, int> >edgee[N];
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m ; i ++) {
        scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]), edgee[a[i][2]].push_back(make_pair(a[i][0], a[i][1]));
    }
    scanf("%d", &k);
    for (int i = 1;i <= k ; i ++) {
        int x;
        scanf("%d", &x);
        ans[i] = x;
        while (x --) {
            int y;
            scanf("%d", &y);
            edge[a[y][2]].push_back(make_pair(make_pair(a[y][0],a[y][1]), i));
        }
    }
    Revocable_disjoint_set::init(n);
    for (int i = 1; i <= N; i ++) {
        for (int l = 0, r = l; l < edge[i].size(); l = r+1) {
            for (r = l; r + 1 < edge[i].size() && edge[i][r + 1].second == edge[i][l].second; r++);
            int tmp = Revocable_disjoint_set::record.size();
            int sig = edge[i][l].second;
            for (int k = l; k <= r; k++)
                ans[sig] -= Revocable_disjoint_set::merge(edge[i][k].first.first, edge[i][k].first.second);
            Revocable_disjoint_set::undo_to_x(tmp);
        }
        for (auto u:edgee[i])
            Revocable_disjoint_set::merge(u.first, u.second);
    }
    for (int i = 1; i <= k; i ++)
        ans[i]?printf("NO\n"):printf("YES\n");
    return 0;
}