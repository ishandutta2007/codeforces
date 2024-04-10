//https://codeforces.com/contest/1335/problem/F
#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
map<char, pair<int,int>> delta;
pair<int,int> operator+(const pair<int,int> &x, const pair<int,int> &y){
    return mp(x.first + y.first, x.second + y.second);
}
void solve(){
    int n,m;
    cin>>n>>m;
    bool black[n][m];
    vector<vector<pair<int,int>>> dir(n ,vector<pair<int,int>>(m));
    vector<vector<set<pair<int,int>>>> revdir(n ,vector<set<pair<int,int>>>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char type;
            cin>>type;
            black[i][j]=type-'0';
            black[i][j]^=1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char type;
            cin>>type;
            dir[i][j]=delta[type];
            auto next=mp(i,j)+delta[type];
            revdir[next.first][next.second].insert(mp(i,j));
        }
    }
    
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<pair<pair<int,int>, int>> cycles;
    int total=0;
    int blacks=0;
    for(int i=0, x=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==0){
                pair<int,int> currpos=mp(i,j);
                int basex=x;
                while(vis[currpos.first][currpos.second]==0){
                    vis[currpos.first][currpos.second]=x;
                    currpos=currpos+dir[currpos.first][currpos.second];
                    ++x;
                }
                if(vis[currpos.first][currpos.second]>=basex){
                    cycles.pb(mp(currpos, x-vis[currpos.first][currpos.second]));
                    total+=x-vis[currpos.first][currpos.second];
                    vis[currpos.first][currpos.second]=-1;
                }
            }
        }
    }
    vector<vector<bool>> vis2(n, vector<bool>(m, 0));
    for(const auto &cycle : cycles){
        int k=cycle.second;
        //cout<<cycle.first.first<<" "<<cycle.first.second<<" "<<cycle.second<<'\n';
        vector<bool> poss(k, 0);
        queue<pair<pair<int,int>, int>> tochk;
        tochk.push(mp(cycle.first, 0));
        vis2[cycle.first.first][cycle.first.second]=1;
        while(tochk.size()){
            poss[(tochk.front().second)%k]=poss[(tochk.front().second)%k]|black[tochk.front().first.first][tochk.front().first.second];
            for(const auto &node : revdir[tochk.front().first.first][tochk.front().first.second]){
                if(!vis2[node.first][node.second]){
                    tochk.push(mp(node, tochk.front().second+1));
                    vis2[node.first][node.second]=1;
                }
            }
            tochk.pop();
        }
        for(int i=0;i<k;i++){
            blacks+=(poss[i]);
        }
        
    }
    cout<<total<<" "<<blacks<<'\n';
    
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >>t;
    delta['R']=mp(0,1);
    delta['L']=mp(0,-1);
    delta['U']=mp(-1, 0);
    delta['D']=mp(1,0);
    while(t--){
        solve();
    }
}