//https://codeforces.com/problemset/problem/1320/B
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
    int n,m;
    cin>>n>>m;
    vector<int> edge[n];
    int dist[n]={0};
    vector<int> edgeback[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edge[--u].pb(--v);
        edgeback[v].pb(u);
    }
    int k;
    cin>>k;
    int seq[k];
    for(int i=0;i<k;i++){
        cin>>seq[i];
        --seq[i];
    }
    queue<int> tochk;
    dist[seq[k-1]]=1;
    tochk.push(seq[k-1]);
    while(!tochk.empty()){
        for(int i=0;i<edgeback[tochk.front()].size();i++){
            if(dist[edgeback[tochk.front()][i]]==0){
                dist[edgeback[tochk.front()][i]]=dist[tochk.front()]+1;
                tochk.push(edgeback[tochk.front()][i]);
            }
        }
        tochk.pop();
    }
    int mn=0,mx=0;
    for(int i=0;i<k-1;i++){
        if(dist[seq[i]]-dist[seq[i+1]]!=1){
            ++mn;
            ++mx;
            continue;
        }
        int count=0;
        for(int j=0;j<edge[seq[i]].size();j++){
            if(dist[seq[i]]-dist[edge[seq[i]][j]]==1){
                ++count;
            }
        }
        if(count>1){
            mx++;
        }
    }
    cout<<mn<<" "<<mx;
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}