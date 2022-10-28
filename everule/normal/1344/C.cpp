#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb emplace_back
#define vi vector<int>
using namespace std;
vector<bool> vis;
vector<bool> vis2;
vector<bool> instack;
vector<bool> instack2;
vector<vector<int>> edges;
vector<vector<int>> edges2;
vector<int> minidx;
vector<int> minidx2;
void dfs(int x){
    instack[x]=1;
    for(const auto &node : edges[x]){
        if(instack[node]){
            cout<<"-1\n";
            exit(0);
        }
        if(!vis[node]){
            dfs(node);
            minidx[x]=min(minidx[x], minidx[node]);
        }
        else{
            minidx[x]=min(minidx[x], minidx[node]);
        }
    }
    vis[x]=1;
    instack[x]=0;
}
void dfs2(int x){
    instack2[x]=1;
    for(const auto &node : edges2[x]){
        if(instack2[node]){
            cout<<"-1\n";
            exit(0);
        }
        if(!vis2[node]){
            dfs2(node);
            minidx2[x]=min(minidx2[x], minidx2[node]);
        }
        else{
            minidx2[x]=min(minidx2[x], minidx2[node]);
        }
    }
    vis2[x]=1;
    instack2[x]=0;
}
void solve(){
    int n, m;
    cin>>n>>m;
    edges.resize(n);
    edges2.resize(n);
    vector<char> ans(n, 'E');
    for(int i=0;i<m;i++){
        int j,k;
        cin>>j>>k;
        --j;--k;
        edges[j].pb(k);
        edges2[k].pb(j);
    }
    vis.resize(n);
    vis2.resize(n);
    instack.resize(n);
    instack2.resize(n);
    minidx.resize(n);
    minidx2.resize(n);
    for(int i=0;i<n;i++){
        minidx[i]=i;
        minidx2[i]=i;
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i);
        }
        if(!vis2[i]){
            dfs2(i);
        }
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(min(minidx[i], minidx2[i])==i){
            ans[i]='A';
            ++count;
        }
    }
    cout<<count<<'\n';
    for(int i=0;i<n;i++){
        cout<<ans[i];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}