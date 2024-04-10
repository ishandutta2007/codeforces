#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
vector<int> son[2000010][10];
int n, m, cnt, vis[2000010];
int dis[2000010];
inline void addedge(int u, int v, int w) {
    while(w >= 10) {
        cnt++;
        son[cnt][w % 10].push_back(v);
        v = cnt;
        w /= 10;
    }
    son[u][w].push_back(v);
}
vector<vector<int> > q1, q2;
int main() {
    scanf("%d%d", &n, &m);
    cnt = n;
    for(int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        addedge(u, v, i);
        addedge(v, u, i);
    }
    dis[1] = 0;
    vector<int> tmp;
    tmp.push_back(1);
    q1.push_back(tmp);
    vis[1] = 1;
    while(1) {
        if(q1.empty()) break;
        for(auto x : q1) {
            for(int d = 0; d < 10; d++) {
                tmp.clear();
                for(auto i : x) {
                    for(auto v : son[i][d]) {
                        if(vis[v]) continue;
                        vis[v] = 1, dis[v] = (dis[i] * 10ll + d) % mod;
                        tmp.push_back(v);
                    }
                }
                if(!tmp.empty()) q2.push_back(tmp);
            }
        }
        q1 = q2;
        q2.clear();
    }
    for(int i = 2; i <= n; i++) printf("%d\n", dis[i]);
    return 0;
}