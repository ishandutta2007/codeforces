#include <bits/stdc++.h>

#define MN 2002
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m, dist[MN][MN][2], ix, iy, L, R;
bool visit[MN][MN];
char line[MN], grid[MN][MN];

pii ini, fim;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool valid_cell(int x, int y) {
    return grid[x][y] == '.';
}

void bfs() {
    deque<pii> fila;
    fila.push_back(ini);
    visit[ini.X][ini.Y] = true;
    dist[ini.X][ini.Y][0] = dist[ini.X][ini.Y][1] = 0;

    while(!fila.empty()) {
        pii u = fila.front();
        fila.pop_front();

        for(int i=0; i<4; i++) {
            int nx = u.X + dx[i];
            int ny = u.Y + dy[i];

            if(!valid(nx, ny)) continue;
            if(!valid_cell(nx, ny)) continue;
            if(visit[nx][ny]) continue;

            dist[nx][ny][0] = dist[u.X][u.Y][0] + (i == 2);
            dist[nx][ny][1] = dist[u.X][u.Y][1] + (i == 0);

            if(i == 0 || i == 2) fila.push_back({nx, ny});
            else fila.push_front({nx, ny});

            visit[nx][ny] = true;
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    scanf("%d %d", &ix, &iy); ini = {ix-1, iy-1};
    scanf("%d %d", &L, &R);

    for(int i=0; i<n; i++) {
        scanf("%s", line);
        for(int j=0; j<m; j++) {
            grid[i][j] = line[j];
        }
    }

    bfs();
    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(visit[i][j] && dist[i][j][0] <= L && dist[i][j][1] <= R) ans++;
        }
    }

    printf("%d\n", ans);
    return 0;
}