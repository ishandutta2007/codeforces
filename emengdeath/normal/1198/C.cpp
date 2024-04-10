#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int N = 1e6;
int n, m, T;
vector<pair<int, int> > g[N];
int bz[N], du[N];
vector<int> ans;
priority_queue<pair<int, int> > h;
int main(){
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= m ; i ++){
            int x, y;
            scanf("%d %d", &x, &y);
            g[x].push_back(make_pair(y, i));
            g[y].push_back(make_pair(x, i));
        }
        bool tag = 0;
        ans.clear();
        for (int i = 1; i <= n * 3; i ++)
            du[i] = g[i].size(),bz[i] = 0, h.push(make_pair(-du[i], i));
        while (!h.empty()){
            pair<int, int> v = h.top();
            h.pop();
            if (-v.first != du[v.second]) continue;
            if (bz[v.second]) continue;
            bz[v.second] = 1;
            for (auto u:g[v.second])
                if (!bz[u.first]) {
                    bz[u.first] = 1;
                    for (auto w:g[v.second])
                        if (!bz[w.first]){
                            du[w.first] --;
                            h.push(make_pair(-du[w.first], w.first));
                        }
                    for (auto w:g[u.first])
                        if (!bz[w.first]){
                            du[w.first] --;
                            h.push(make_pair(-du[w.first], w.first));
                        }
                    ans.push_back(u.second);
                    break;
                }
        }
        if (ans.size() >= n) {
            tag = 1;
            printf("Matching\n");
            for (int i = 0; i < n ; i++)
                printf("%d ", ans[i]);
            printf("\n");
        }
        if (!tag) {
            ans.clear();
            for (int i = 1; i <= n * 3; i ++)
                du[i] = g[i].size(),bz[i] = 0, h.push(make_pair(-du[i], i));
            while (!h.empty()){
                pair<int, int> v = h.top();
                h.pop();
                if (-v.first != du[v.second]) continue;
                if (bz[v.second]) continue;
                ans.push_back(v.second);
                bz[v.second] = 1;
                for (auto u:g[v.second])
                if (!bz[u.first]){
                    bz[u.first] = 1;
                    for (auto w:g[u.first])
                        if (!bz[w.first]) {
                            du[w.first] --;
                            h.push(make_pair(-du[w.first], w.first));
                        }
                }
            }
            if (ans.size() >= n) {
                tag = 1;
                printf("IndSet\n");
                for (int i = 0; i < n; i++)
                    printf("%d ", ans[i]);
                printf("\n");
            }
        }
        if (!tag) {
            printf("Impossible\n");
        }
        for (int i = 1; i <= n * 3; i++)
            g[i].clear();
    }
    return 0;
}