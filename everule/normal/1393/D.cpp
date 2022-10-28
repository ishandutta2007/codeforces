#include <iostream>
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
const int AL = 26;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n+2 ,vector<char>(m+2, '.'));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>grid[i][j];
        }
    }
    vector<queue<pair<int,int>>> src(AL);
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,-1},{0,1}};
    vector<vector<int>> dist(n+2, vector<int>(m+2, 1e9));
    vector<vector<bool>> vis(n+2, vector<bool>(m+2));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){

            bool flag = 0;
            for(const auto &[dx, dy] : dir){
                if(grid[i+dx][j+dy]!=grid[i][j]){
                    flag = 1;
                }
            }
            if(!flag) continue;
            src[grid[i][j] - 'a'].push({i,j});
            vis[i][j] = 1;
            dist[i][j] = 1;
        }
    }
    for(auto &bfs : src){
        while(!bfs.empty()){
            const auto &[x,y] = bfs.front();
            for(const auto &[dx, dy] : dir){
                if(grid[x][y]!=grid[x+dx][y+dy]) continue;
                if(vis[x+dx][y+dy]) continue;
                dist[x+dx][y+dy] = dist[x][y] + 1;
                vis[x+dx][y+dy] = 1;
                bfs.push({x+dx, y+dy});
            }
            bfs.pop();
        }
    }
    ll ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ans+=dist[i][j];
        }
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}