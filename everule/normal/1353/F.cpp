//https://codeforces.com/contest/1353/problem/F
#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
const ll INF=3e18;
pair<int,int> operator+(const pair<int,int> &x, const pair<int,int> &y){
    return mp(x.first + y.first, x.second + y.second);
}
template<typename T>
decltype(auto) operator-(vector<vector<T>> &seq, const pair<int , int> &idx){
    return seq[idx.first][idx.second];
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<ll>> grid(n, vector<ll>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            grid[i][j]-=i+j;
        }
    }
    vector<vector<bool>> vis(n, vector<bool>(m, -1));
    vector<vector<ll>> dist(n, vector<ll>(m));
    auto valid=[&](const pair<int,int> &pos){
        return pos.first<n && pos.first>=0 && pos.second<m && pos.second>=0;
    };
    vector<pair<int,int>> dirforward={{1,0},{0,1}};
    vector<pair<int,int>> dirback={{-1,0},{0,-1}};
    auto bfs=[&](const pair<int,int> &start){
        queue<pair<int,int>> tochk;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dist[i][j]=INF;
                vis[i][j]=0;
            }
        }
        tochk.push(start);
        dist-start=grid-start;
        vis-start=1;
        while(!tochk.empty()){
            auto curr=tochk.front();
            tochk.pop();
            vis-curr=1;
            for(const auto &dir : dirforward){
                auto next=curr+dir;
                if(!valid(next)){
                    continue;
                }
                if(grid-next<grid-start){
                    continue;
                }
                dist-next=min(dist-next, dist-curr + (grid-next));
                if(vis-next){
                    continue;
                }
                vis-next=1;
                tochk.push(next);
            }
        }  
        tochk.push(start);
        while(!tochk.empty()){
            auto curr=tochk.front();
            tochk.pop();
            vis-curr=1;
            for(const auto &dir : dirback){
                auto next=curr+dir;
                if(!valid(next)){
                    continue;
                }
                if(grid-next<grid-start){
                    continue;
                }
                dist-next=min(dist-next, dist-curr + (grid-next));
                if(vis-next){
                    continue;
                }
                vis-next=1;
                tochk.push(next);
            }
        }  
        if(dist[0][0]>=INF || dist[n-1][m-1]>=INF){
            return INF;
        }
        return dist[0][0] - (n+m)*(grid-start) + dist[n-1][m-1]; 
    };
    ll ans=INF;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans=min(bfs(mp(i,j)), ans);
        }
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}