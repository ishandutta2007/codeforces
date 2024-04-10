#include <bits/stdc++.h>

#define MN 1010
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m, dist[MN][MN], dist2[MN][MN], k;
bool visit[MN][MN], visit2[MN][MN];
char line[MN], grid[MN][MN];

pii ini, fim;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool valid_cell(int x, int y) {
    return grid[x][y] != '#';
}

void bfs(pii ini, pii fim) {
    queue<pii> fila, fila2;
    fila.push(ini);
    fila2.push(fim);

    visit[ini.X][ini.Y] = true;
    dist[ini.X][ini.Y] = 0;

    visit2[fim.X][fim.Y] = true;
    dist2[fim.X][fim.Y] = 0;

    while(!fila.empty() && !fila2.empty()) {
        pii u = fila.front();
        fila.pop();

        for(int i=0; i<4; i++) for(int d = 1; d <= k; d++) {
            int nx = u.X + d*dx[i];
            int ny = u.Y + d*dy[i];

            if(!valid(nx, ny)) break;
            if(!valid_cell(nx, ny)) break;
            if(visit[nx][ny]) continue;

            fila.push({nx, ny});
            dist[nx][ny] = dist[u.X][u.Y] + 1;
            visit[nx][ny] = true;
            if(nx == fim.X && ny == fim.Y) return;
        }

        u = fila2.front();
        fila2.pop();

        for(int i=0; i<4; i++) for(int d = 1; d <= k; d++) {
            int nx = u.X + d*dx[i];
            int ny = u.Y + d*dy[i];

            if(!valid(nx, ny)) break;
            if(!valid_cell(nx, ny)) break;
            if(visit2[nx][ny]) continue;

            fila2.push({nx, ny});
            dist2[nx][ny] = dist2[u.X][u.Y] + 1;
            visit2[nx][ny] = true;
            if(nx == ini.X && ny == ini.Y) return;
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &k);

    for(int i=0; i<n; i++) {
        scanf("%s", line);
        for(int j=0; j<m; j++) {
            grid[i][j] = line[j];
            if(grid[i][j] == 'S') ini = {i, j};
            if(grid[i][j] == 'T') fim = {i, j};
        }
    }

    int ix, iy, fx, fy;
    scanf("%d %d %d %d", &ix, &iy, &fx, &fy);
    ini = {ix - 1, iy - 1};
    fim = {fx - 1, fy - 1};

    bfs(ini, fim);


    int ans= 99999999;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(visit[i][j] && visit2[i][j])
                ans = min(ans, dist[i][j] + dist2[i][j]);

    if(ans == 99999999) printf("-1\n");
    else printf("%d\n", ans);

    return 0;
}