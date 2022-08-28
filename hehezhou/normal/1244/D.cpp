#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int> son[100010];
ll cost[3][100010];
ll p[3] = {0, 1, 2};
ll ans[3], _min = 1e18;
ll a[100010];
int out[100010];
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", cost[0] + i);
    for(int i = 1; i <= n; i++) scanf("%d", cost[1] + i);
    for(int i = 1; i <= n; i++) scanf("%d", cost[2] + i);
    for(int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        son[u].push_back(v), son[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) {
        if(son[i].size() == 1) a[1] = i;
    }
    for(int i = 1; i < n; i++) {
        if(son[a[i]].size() > 2) return puts("-1"), 0;
        if(son[a[i]][0] != a[i - 1]) a[i + 1] = son[a[i]][0];
        else a[i + 1] = son[a[i]][1];
    }
    do {
        long long now = 0;
        for(int i = 1; i <= n; i++) {
            now += cost[p[i % 3]][a[i]];
        }
        if(now < _min) _min = now, memcpy(ans, p, sizeof p);
    } while(next_permutation(p, p + 3));
    cout << _min << endl;
    for(int i = 1; i <= n; i++) out[a[i]] = ans[i % 3] + 1;
    for(int i = 1; i <= n; i++) printf("%d%c", out[i], " \n"[i == n]);
    return 0;
}