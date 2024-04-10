#include <bits/stdc++.h>

#define MN 200100
#define MOD 1000000007

using namespace std;
typedef long long ll;

ll expo[MN];
int dist[MN], adj[MN], n, visit[MN], count_;
vector<int> radj[MN];

void calc_() {
    expo[0] = 1;
    for(int i = 1; i < MN; i++) {
        expo[i] = (expo[i-1] * 2)%MOD;
    }
}

void dfs(int node) {
    if(visit[node]) return;
    visit[node]++;

    dfs(adj[node]);
    for(int i=0;i<radj[node].size();i++)
        dfs(radj[node][i]);
}

int main() {
    calc_();
    scanf("%d\n", &n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&adj[i]);
        radj[adj[i]].push_back(i);
    }

    memset(dist, -1, sizeof dist);
    ll ans = 1;

    for(int i=1;i<=n;i++) {
        if(visit[i]) continue;

        dfs(i);
        int v = adj[i], u = i;
        dist[u] = 0;

        while(dist[v] == -1) {
            dist[v] = dist[u] + 1;
            u = v;
            v = adj[v];
        }   int ciclo = abs(dist[u] - dist[v]) + 1;
        //printf("%d %d\n", ciclo, count_);
        ans = (ans *((expo[ciclo] - 2)%MOD + MOD)%MOD)%MOD;
        count_ += ciclo;
    }
    ans = (ans * expo[n-count_])%MOD;
    printf("%lld\n", ans);

    return 0;
}