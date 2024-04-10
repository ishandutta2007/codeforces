#include <bits/stdc++.h>

#define w1 while(1)
#define pint(n) printf("%d\n",n)
#define fill(n,m) memset(n,m,sizeof(n))
#define MN 200200
#define INF 99999999

using namespace std;

int a[MN], dist[MN],visit[MN],n;

void bfs() {
    dist[1] = 0;
    visit[1] = 1;

    queue<int> fila;
    fila.push(1);

    while(!fila.empty()) {
        int u = fila.front();
        fila.pop();

        if(u - 1 > 0 && visit[u - 1] == 0) {
            dist[u - 1] = dist[u] + 1;
            visit[u - 1] = 1;
            fila.push(u - 1);
        }
        if(u + 1 <= n && visit[u + 1] == 0) {
            dist[u + 1] = dist[u] + 1;
            visit[u + 1] = 1;
            fila.push(u + 1);
        }
        if(visit[a[u]] == 0) {
            dist[a[u]] = dist[u] + 1;
            visit[a[u]] = 1;
            fila.push(a[u]);
        }
    }
}

int main() {
    scanf("%d",&n);

    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }

    bfs();

    for(int i=1;i<=n;i++) {
        printf("%d ",dist[i]);
    }

    return 0;
}