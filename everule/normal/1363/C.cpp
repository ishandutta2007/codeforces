//https://codeforces.com/contest/1363/problem/C
#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
void solve(){
    int n, x;
    cin>>n>>x;
    --x;
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> subtrees;
    vector<bool> vis(n);
    vis[x]=1;
    int ans=0;
    int o=0, e=0;
    for(const auto &node : adj[x]){
        queue<int> tochk;
        tochk.push(node);
        int size=1;
        vis[node]=1;
        while(!tochk.empty()){
            for(const auto &edge : adj[tochk.front()]){
                if(!vis[edge]){
                    ++size;
                    vis[edge]=1;
                    tochk.push(edge);
                }
            }
            tochk.pop();
        }
        if(size&1){
            ++o;
        }
        else{
            ++e;
        }
    }
    if(adj[x].size()<=1){
        cout<<"Ayush\n";
        return;
    }
    if(o&1){
        cout<<"Ayush\n";
    }
    else{
        cout<<"Ashish\n";
    }
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