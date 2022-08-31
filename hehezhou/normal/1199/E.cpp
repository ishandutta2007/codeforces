#include <bits/stdc++.h>
using namespace std;
vector < pair<int, int> > to[300010];
int n, m, t, chosev[300010], chosee[300010];
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= 3 * n; i++) to[i].clear(), chosev[i] = 0;
        for(int i = 1; i <= m; i++) chosee[i] = 0;
        for(int i = 1, u, v; i <= m; i++) scanf("%d%d", &u, &v), to[u].push_back(make_pair(v, i)), to[v].push_back(make_pair(u, i));
        int cnt = 0, flag = 0;
        for(int i = 1; i <= 3 * n; i++) {
            if(i[chosev]) continue;
            for(auto [v, id] : to[i]) {
                if(v[chosev]) continue;
                i[chosev] = v[chosev] = 1;
                id[chosee] = 1;
                flag++;
                break;
            }
        }
        if(flag >= n) {
            puts("Matching");
            for(int i = 1; i <= m; i++) {
                if(i[chosee]) printf("%d%c", i, " \n"[++cnt == n]);
                if(cnt == n) break;
            }
        }
        else {
            puts("IndSet");
            for(int i = 1; i <= 3 * n; i++) {
                if(!i[chosev]) printf("%d%c", i, " \n"[++cnt == n]);
                if(cnt == n) break;
            }
        }
    }
}