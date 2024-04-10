#include <stdio.h>
#include <queue>

using namespace std;

#define N 20010

int dist[N], visit[N], n, m;

void bfs(int node) {
    visit[node] = true;
    dist[node] = 0;
    queue<int> fila;
    fila.push(node);

    while(!fila.empty()) {
        int v = fila.front(); fila.pop();
        if(v == m) return;

        if(2*v < N && !visit[2*v]) {
            visit[2*v] = true;
            dist[2*v] = dist[v] + 1;
            fila.push(2*v);
        }
        if(v-1 > 0 && !visit[v-1]) {
            visit[v-1] = true;
            dist[v-1] = dist[v] + 1;
            fila.push(v-1);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    bfs(n);
    printf("%d\n", dist[m]);
    return 0;
}