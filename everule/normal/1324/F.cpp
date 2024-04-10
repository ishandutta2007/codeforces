//https://codeforces.com/problemset/problem/1324/F
#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
vector<vector<int>> edge;
vector<int> vis;
vector<int> dp;
vector<int> color;
vector<int> eulerpath;
vector<int> ans;
void euler(int u, int& idx){
    vis[u]=1;
    eulerpath[idx++]=u;
    for(auto child : edge[u]){
        if(vis[child]){
            continue;
        }
        euler(child,idx);
        eulerpath[idx++]=u;
    }
}
void dfs(int u, int v=-1){
    vis[u]=1;
    if(v!=-1 && edge[u].size()==1){
        dp[u]=color[u];
        ans[u]=dp[u];
        return;
    }
    for(auto child : edge[u]){
        if(vis[child]){
            continue;
        }
        if(child==v){
            continue;
        }
        dfs(child,u);
        dp[u]+=max(0,dp[child]);
    }
    dp[u]+=color[u];
    ans[u]=dp[u];
    return;
}
ll solve(){
    int n;
    cin>>n;
    edge.resize(n);
    vis.resize(n,0);
    dp.resize(n);
    color.resize(n);
    ans.resize(n);
    for(int i=0;i<n;i++){
        cin>>color[i];
        if(color[i]==0){
            --color[i];
        }
    }
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        edge[--u].pb(--v);
        edge[v].pb(u);
    }
    dfs(0);
    eulerpath.resize(2*n);
    vis.clear();
    vis.resize(n,0);
    int idx=0;
    euler(0,idx);
    for(int i=1;i<idx;i++){
        dp[eulerpath[i-1]]-=max(0,dp[eulerpath[i]]);
        dp[eulerpath[i]]+=max(0,dp[eulerpath[i-1]]);
        ans[eulerpath[i]]=max(ans[eulerpath[i]], dp[eulerpath[i]]);
        ans[eulerpath[i-1]]=max(ans[eulerpath[i-1]], dp[eulerpath[i-1]]);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}