#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
template<typename T>
ostream& operator+(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out<<x<<" ";
    }
    out<<"\n";
    return out;
}
template<typename T>
ostream& operator*(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out+x;
    }
    return out;
}
template<typename T>
istream& operator>>(istream& in, vector<T> &vec){
    for(auto &x : vec){
        in>>x;
    }
    return in;
}
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        --u;--v;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    vector<pair<int,int>> trains(k);
    for(auto &[t,s] : trains){
        cin>>s>>t;
        --s;
    }
    sort(trains.begin(), trains.end());
    int ans = k;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    vector<ll> dist(n, 1e18);
    dist[0] = 0;
    pq.push({0,0});
    int j = 0;
    while(!pq.empty()){
       // cout<<pq.top().first<<" "<<pq.top().second<<"\n";
        while(j<k && trains[j].first < pq.top().first){
            if(dist[trains[j].second] > trains[j].first){
         //       cout<<j<<"\n";
                dist[trains[j].second] = trains[j].first;
                --ans;
                pq.push(trains[j]);
            }
            ++j;
        }
        const auto [d,u] = pq.top();
        pq.pop();
        if(dist[u] < d) continue;
        for(const auto &[v,w] : adj[u]){
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    //cout+dist;
    cout<<ans<<"\n"; 
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}