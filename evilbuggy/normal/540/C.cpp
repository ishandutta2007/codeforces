#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

char a[505][505];
int n, m, vis[505][505];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y){
    if(vis[x][y])return;
    vis[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny] == 'X')continue;
        dfs(nx, ny);
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
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>a[i][j];
            vis[i][j] = 0;
        }
    }
    int r1, r2, c1, c2;
    cin>>r1>>c1;
    cin>>r2>>c2;
    if(r1 == r2 && c1 == c2){
        for(int i = 0; i < 4; i++){
            int nr = r1 + dx[i];
            int nc = c1 + dy[i];
            if(nr > 0 && nr <= n && nc > 0 && nc <= m){
                if(a[nr][nc] == '.'){
                    cout<<"YES"<<endl;
                    return 0;
                }
            }
        }
        cout<<"NO"<<endl;
        return 0;
    }
    dfs(r1, c1);
    if(a[r2][c2] == 'X'){
        for(int i = 0; i < 4; i++){
            int nr = r2 + dx[i];
            int nc = c2 + dy[i];
            if(nr < 1 || nr > n || nc < 1 || nc > m)continue;
            if(vis[nr][nc]){
                cout<<"YES"<<endl;
                return 0;
            }
        }
        cout<<"NO"<<endl;
        return 0;
    }else if(abs(r2-r1) + abs(c2-c1) == 1){
        for(int i = 0; i < 4; i++){
            int nr = r2 + dx[i];
            int nc = c2 + dy[i];
            if(nr < 1 || nr > n || nc < 1 || nc > m)continue;
            if(a[nr][nc] == '.'){
                cout<<"YES"<<endl;
                return 0;
            }
        }
        cout<<"NO"<<endl;
        return 0;
    }else{
        int cnt = 0;
        for(int j = 0; j < 4; j++){
            int nr2 = r2 + dx[j];
            int nc2 = c2 + dy[j];
            if(nr2 < 1 || nr2 > n || nc2 < 1 || nc2 > m)continue;
            if(a[nr2][nc2] != 'X')cnt++;
        }
        // cout<<cnt<<endl;
        if(cnt < 2){
            cout<<"NO"<<endl;
            return 0;
        }
        for(int i = 0; i < 4; i++){
            int nr = r2 + dx[i];
            int nc = c2 + dy[i];
            if(nr < 1 || nr > n || nc < 1 || nc > m)continue;
            if(vis[nr][nc]){
                cout<<"YES"<<endl;
                return 0;
            }
        }
        cout<<"NO"<<endl;
        return 0;
    }
}