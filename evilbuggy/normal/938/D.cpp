#include <bits/stdc++.h>

using namespace std;

class cmp{
public:
    bool operator()(pair<int,long long int> &a, pair<int, long long int> &b){
        return a.second > b.second;
    }
};

int main(){
    std::ios_base::sync_with_stdio(false);
    int n,m,u,v;
    long long int w;
    cin>>n>>m;
    vector<pair<int,long long int> >g[n+1];
    for(int i = 0; i < m; i++){
        cin>>u>>v>>w;
        g[u].push_back(make_pair(v,w));
        g[v].push_back(make_pair(u,w));
    }
    priority_queue<pair<int,long long int>, vector<pair<int, long long int> >, cmp> myQ;
    for(int i = 1; i <= n; i++){
        cin>>w;
        myQ.push(make_pair(i,w));
    }
    int vis[n+1] = {0};
    long long int cost[n+1];
    for(int i = 0; i <= n; i++){
        cost[i] = 1e16;
    }
    while(!myQ.empty()){
        u = myQ.top().first;
        w = myQ.top().second;
        myQ.pop();
        if(vis[u] == 1){
            continue;
        }
        vis[u] = 1;
        cost[u] = w;
        for(size_t i = 0; i < g[u].size(); i++){
            v = g[u][i].first;
            if(vis[v] == 1)continue;
            long long int wei = g[u][i].second;
            if(cost[u] + 2*wei < cost[v]){
                cost[v] = cost[u] + 2*wei;
                myQ.push(make_pair(v,cost[v]));
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout<<cost[i]<<" ";
    }
}