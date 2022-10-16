#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;

#define mp make_pair
typedef pair<int, int> pii;

char scie[11][11], resc[11][11];
int dist[11][11];
int seen[11][11];
int g[910][910];

int resccnt[11][11];
int sciecnt, ct;

int vis[1000];
int match[1000];

int n,t;

bool bpm(int v) {
    if (vis[v]) return false;
    vis[v] = 1;
    
    for (int i = 0; i < ct; i++) {
        if (g[v][i]) {
            if (match[i] == -1 || bpm(match[i])) {
                match[i] = v;
                return true; 
            }
        }
    }
    
    return false;
}

const int INF = 10000;
queue<pii> fila;

void bfs(int dst[11][11]) {
    memset(seen,0,sizeof(seen));
    pii rea = fila.front();
    dst[rea.first][rea.second] = 0;
    
    while (!fila.empty()) {
        pii cur = fila.front();
        fila.pop();
        
        seen[cur.first][cur.second] = 1;
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx+dy == 0 || dx*dy != 0) continue;
                
                int nx = cur.first + dx, ny = cur.second + dy;
                
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || scie[nx][ny] == 'Y' || seen[nx][ny]) continue;
                
                dst[nx][ny] = dst[cur.first][cur.second] + 1;
                if (dst == dist || dst[nx][ny] < dist[nx][ny]) fila.push(mp(nx,ny));
            }
        }   
    }
}

void create(int x, int y) {
    int mydist[11][11];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mydist[i][j] = INF;
        }
    }
    
    mydist[x][y] = 0;
    fila.push(mp(x,y));
    bfs(mydist);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //if (x == 2 && y == 0) printf("%d (%d) ", mydist[i][j], dist[i][j]);
            if (mydist[i][j] <= min(t,dist[i][j]) && scie[i][j] != 'Y' && scie[i][j] != 'Z') {
                for (int k = 0; k < resc[i][j]-'0'; k++) {
                    for (int z = 0; z < scie[x][y]-'0'; z++) {
                        g[sciecnt + z][resccnt[i][j] + k] = 1;
                    }
                }
            }
        }
        //if (x == 2 && y == 0) printf("\n");
    }
    
    sciecnt += scie[x][y] - '0';
}

int main() {
    scanf("%d %d", &n, &t);
    for (int i = 0; i < n; i++) scanf("%s", scie[i]);
    for (int i = 0; i < n; i++) scanf("%s", resc[i]);
        
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = INF;
            if (scie[i][j]=='Z') fila.push(mp(i,j));
        }
    }
    
    bfs(dist);
    
    ct = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resccnt[i][j] = ct;
            if (resc[i][j] >= '0' && resc[i][j] <= '9') ct += resc[i][j] - '0';
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scie[i][j] >= '0' && scie[i][j] <= '9') create(i, j);
        }
    }
    
    /*printf("%d %d\n", sciecnt, ct);
    for (int i = 0; i < sciecnt; i++) {
        for (int j = 0; j < ct; j++) printf("%d ", g[i][j]);
        printf("\n");
    }*/
    
    int cnt = 0;
    memset(match,-1,sizeof(match));
    for (int i = 0; i < sciecnt; i++) {
        memset(vis,0,sizeof(vis));
        if (bpm(i)) cnt++;
    }
    printf("%d\n", cnt);
}