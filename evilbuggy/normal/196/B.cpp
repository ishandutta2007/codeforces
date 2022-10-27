#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

char maze[1505][1505];
bool vis[1505][1505];
int prex[1505][1505];
int prey[1505][1505];
int n, m;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y){
    int nx = (n + (x%n))%n;
    int ny = (m + (y%m))%m;
    if(vis[nx][ny]){
        if(prex[nx][ny] != x || prey[nx][ny] != y){
            cout<<"Yes"<<endl;
            exit(0);
        }
        return;
    }
    if(maze[nx][ny] == '#')return;
    vis[nx][ny] = true;
    prex[nx][ny] = x;
    prey[nx][ny] = y;
    for(int i = 0; i < 4; i++){
        dfs(x + dx[i], y + dy[i]);
    }

}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    cin>>n>>m;
    int sx, sy;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>maze[i][j];
            vis[i][j] = false;
            if(maze[i][j] == 'S')sx = i, sy = j;
        }
    }
    dfs(sx, sy);
    cout<<"No"<<endl;
}