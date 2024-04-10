//https://codeforces.com/contest/1307/problem/D
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
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> special(k);
    vector<vector<int>> adj(n);
    for(int i=0;i<k;i++){
        cin>>special[i];
         --special[i];
    }
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> dist(n, -1);
    queue<int> q;
    q.push(0);
    dist[0]=0;
    while(!q.empty()){
        for(const auto &node  : adj[q.front()]){
            if(dist[node]==-1){
                q.push(node);
                dist[node]=dist[q.front()]+1;
            }
        }
        q.pop();
    }
    vector<int> dist2(n, -1);
    q.push(n-1);
    dist2[n-1]=0;
    while(!q.empty()){
        for(const auto &node  : adj[q.front()]){
            if(dist2[node]==-1){
                q.push(node);
                dist2[node]=dist2[q.front()]+1;
            }
        }
        q.pop();
    }
    set<pair<int,int>> distance1;
    set<pair<int, int>> distance2;
    for(int i=0;i<k;i++){
        distance1.insert(mp(dist[special[i]], special[i]));
        distance2.insert(mp(dist2[special[i]], special[i]));
    }
    int ans=-1;
    for(const auto &x : distance1){
        int curr=x.first+1;
        distance2.erase(mp(dist2[x.second], x.second));
        if(distance2.size()==0){
            break;
        }
        curr+=(*prev(distance2.end())).first;
        if(curr>dist[n-1]){
            curr=dist[n-1];
        }
        ans=max(ans, curr);
    }
    cout<<ans<<'\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}