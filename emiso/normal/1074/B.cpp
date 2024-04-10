#include <bits/stdc++.h>

#define MN 2000

using namespace std;
typedef long long ll;

int n, t, a, b, k, jonson, mark[MN], mark2[MN], visit[MN];
vector<int> adj[MN], x, y;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);

        for(int i = 0; i < MN; i++) {
            mark[i] = mark2[i] = visit[i] = 0;
            adj[i].clear();
        }

        for(int i = 1; i < n; i++) {
            scanf("%d %d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        scanf("%d", &k); x.resize(k);
        for(int i = 0; i < k; i++) {
            scanf("%d", &x[i]);
            mark[x[i]] = 1;
        }

        scanf("%d", &k); y.resize(k);
        for(int i = 0; i < k; i++) {
            scanf("%d", &y[i]);
            mark2[y[i]] = 1;
        }

        printf("B %d\n", y[0]); fflush(stdout);
        scanf("%d", &jonson);

        queue<int> fila;
        fila.push(jonson);
        visit[jonson] = 1;

        while(!fila.empty()) {
            int u = fila.front(); fila.pop();

            if(mark[u]) {
                printf("A %d\n", u);
                fflush(stdout);
                scanf("%d", &jonson);

                if(mark2[jonson]) {
                    printf("C %d\n", u);
                    fflush(stdout);
                } else {
                    printf("C -1\n");
                    fflush(stdout);
                }
                break;
            }

            for(int v : adj[u]) {
                if(!visit[v]) {
                    visit[v] = 1;
                    fila.push(v);
                }
            }
        }
    }
    return 0;
}