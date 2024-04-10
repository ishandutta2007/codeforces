#include <bits/stdc++.h>

#define MN 1001000
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

ll n, m, a, b, visit[MN], w[MN], s, tot, maxi, pf[MN], deg[MN];
vector<int> adj[MN];


int main() {
    scanf("%lld %lld", &n, &m);

    for(int i = 1; i <= n; i++) {
        scanf("%lld", &w[i]);
    }

    for(int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    scanf("%lld", &s);

    queue<int> fila;
    for(int i = 1; i <= n; i++) {
        if(i != s && deg[i] == 1) {
            fila.push(i);
            visit[i] = 1;
        }
    }

    while(!fila.empty()) {
        int u = fila.front();
        fila.pop();

        for(int v : adj[u]) {
            if(!visit[v]) {
                deg[v]--;
                if(v != s && deg[v] == 1) {
                    fila.push(v);
                    visit[v] = 1;
                }
                pf[v] = max(pf[v], pf[u] + w[u]);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if(!visit[i]) {
            tot += w[i];
            maxi = max(maxi, pf[i]);
        }
    }

    printf("%lld\n", tot + maxi);
    return 0;
}