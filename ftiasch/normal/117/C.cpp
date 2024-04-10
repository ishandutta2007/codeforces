// Codeforces Beta Round #88
// Problem C -- Cycle
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 5555;

int n, m, visit[N], parent[N], cycle[N];
char map[N][N];

void dfs (int u) {
    visit[u] = 0;
    for (int v = 0; v < n and m < 3; ++ v) {
        if (map[u][v] == '1') {
            if (visit[v] == -1) {
                parent[v] = u;
                dfs(v);
            } else if (visit[v] == 0) {
                for (int i = u; i != v; i = parent[i]) {
                    cycle[m ++] = i;
                }
                cycle[m ++] = v;
                return;
            }
        }
    }
    visit[u] = 1;
}

int main () {
    scanf("%d", &n);
    fgets(map[0], N, stdin);
    for (int i = 0; i < n; ++ i) {
        fgets(map[i], N, stdin);
    }
    m = 0;
    memset(visit, -1, sizeof(visit));    
    for (int i = 0; i < n; ++ i) {
        if (visit[i] == -1) {
            dfs(i);
        }
    }
    if (m < 3) {
        printf("-1\n");
    } else {
        while (m > 3) {
            if (map[cycle[0]][cycle[m - 2]] == '1') {
                m -= 1;
            } else {
                cycle[1] = cycle[m - 2];
                cycle[2] = cycle[m - 1];
                break;
            }
        }
        printf("%d %d %d\n", cycle[2] + 1, cycle[1] + 1, cycle[0] + 1);
    }
    return 0;
}