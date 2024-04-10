#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;

int cracked[550][550],ex,ey,sx,sy,flag = 0;
int X[4] = {1,0,-1,0};
int Y[4] = {0,-1,0,1};

void bfs(int y, int x) {
    queue<pair<int,int> > fila;
    fila.push(make_pair(y,x));
    while(!fila.empty()) {
        int y = fila.front().first;
        int x = fila.front().second;
        fila.pop();
        for(int i=0;i<4;i++) {
            if(cracked[y+Y[i]][x+X[i]] == 0) {
                fila.push(make_pair(y+Y[i],x+X[i]));
                cracked[y+Y[i]][x+X[i]] = 1;
            }
            else if(cracked[y+Y[i]][x+X[i]] == 1) {
                if(y+Y[i] == ey && x+X[i] == ex) flag = 1;
            }
        }
    }
}

int main() {
    int n,m,sy,sx;
    memset(cracked,-1,sizeof(cracked));
    scanf("%d %d ",&n,&m);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            char c = getchar();
            if(c == '.') cracked[i][j] = 0;
            else cracked[i][j] = 1;
        }
        char c = getchar();
    }
    scanf("%d %d",&sy,&sx);
    scanf("%d %d",&ey,&ex);
    bfs(sy,sx);
    if(flag == 0) puts("NO");
    else puts("YES");
    return 0;
}