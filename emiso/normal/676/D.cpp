#include <bits/stdc++.h>

#define L(x) (x + 4 - rot)%4

#define MP(a,b,c) make_pair(make_pair(a,b),c)
#define X first.first
#define Y first.second
#define R second

using namespace std;

bool visit[1010][1010][4];
int dist[1010][1010][4];
vector<int>vi[1010][1010];
int n,m;

int d1[] = {1,1,1,1};
int d2[] = {0,1,0,1};
int d3[] = {1,0,1,0};
int d4[] = {1,0,0,0};
int d5[] = {0,1,0,0};
int d6[] = {0,0,0,1};
int d7[] = {0,0,1,0};
int d8[] = {1,1,1,0};
int d9[] = {1,0,1,1};
int d10[] = {0,1,1,1};
int d11[] = {1,1,0,1};
int d12[] = {0,0,0,0};

void bfs(int xi, int yi) {
    visit[xi][yi][0] = 1;
    dist[xi][yi][0] = 0;

    queue<pair<pair<int,int>,int> > fila;

    fila.push(MP(xi,yi,0));
    while(!fila.empty()) {
        int x = fila.front().X;
        int y = fila.front().Y;
        int rot = fila.front().R;
        fila.pop();

        if(!visit[x][y][(rot+1)%4]) {
            dist[x][y][(rot+1)%4] = dist[x][y][rot] + 1;
            visit[x][y][(rot+1)%4] = 1;
            fila.push(MP(x,y,(rot+1)%4));
        }

        //UP
        if(x > 1 && vi[x][y][L(0)] && vi[x-1][y][L(2)] && !visit[x-1][y][rot]) {
            dist[x-1][y][rot] = dist[x][y][rot] + 1;
            visit[x-1][y][rot] = 1;
            fila.push(MP(x-1,y,rot));
        }

        //DOWN
        if(x < n && vi[x][y][L(2)] && vi[x+1][y][L(0)] && !visit[x+1][y][rot]) {
            dist[x+1][y][rot] = dist[x][y][rot] + 1;
            visit[x+1][y][rot] = 1;
            fila.push(MP(x+1,y,rot));
        }

        //LEFT
        if(y > 1 && vi[x][y][L(3)] && vi[x][y-1][L(1)] && !visit[x][y-1][rot]) {
            dist[x][y-1][rot] = dist[x][y][rot] + 1;
            visit[x][y-1][rot] = 1;
            fila.push(MP(x,y-1,rot));
        }

        //RIGHT
        if(y < m && vi[x][y][L(1)] && vi[x][y+1][L(3)] && !visit[x][y+1][rot]) {
            dist[x][y+1][rot] = dist[x][y][rot] + 1;
            visit[x][y+1][rot] = 1;
            fila.push(MP(x,y+1,rot));
        }
    }
}

int main() {
    int xt,yt,xm,ym;
    char door;
    scanf("%d %d",&n,&m);

    for(int i=1;i<=n;i++) {
        scanf("%c",&door);

        for(int j=1;j<=m;j++) {
            scanf("%c",&door);

            if(door == '+')
                vi[i][j].assign(d1,d1+4);
            else if(door == '-')
                vi[i][j].assign(d2,d2+4);
            else if(door == '|')
                vi[i][j].assign(d3,d3+4);
            else if(door == '^')
                vi[i][j].assign(d4,d4+4);
            else if(door == '>')
                vi[i][j].assign(d5,d5+4);
            else if(door == '<')
                vi[i][j].assign(d6,d6+4);
            else if(door == 'v')
                vi[i][j].assign(d7,d7+4);
            else if(door == 'L')
                vi[i][j].assign(d8,d8+4);
            else if(door == 'R')
                vi[i][j].assign(d9,d9+4);
            else if(door == 'U')
                vi[i][j].assign(d10,d10+4);
            else if(door == 'D')
                vi[i][j].assign(d11,d11+4);
            else if(door == '*')
                vi[i][j].assign(d12,d12+4);
            else printf("error\n");
        }
    }

    scanf("%d %d %d %d",&xt,&yt,&xm,&ym);
    bfs(xt,yt);

    int ans = 99999999, flag = 0;
    for(int i=0;i<4;i++) {
        if(visit[xm][ym][i]) {
            ans = min(ans,dist[xm][ym][i]);
            flag = 1;
        }
    }
    if(!flag) printf("-1\n");
    else printf("%d\n",ans);
    return 0;
}