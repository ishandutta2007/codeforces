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
const int INF = 1e9 + 8;
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> g(n);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto furthestfrom = [&](int u){
        queue<int> bfs;
        bfs.push(u);
        vector<int> dist(n,INF);
        vector<vector<int>> levels(n);
        int ans = 0;
        dist[u] = 0;
        levels[0].push_back(u);
        while(!bfs.empty()){
            int u = bfs.front();
            bfs.pop();
            ans = u;
            for(auto v : g[u]){
                if(dist[v] > dist[u] + 1){
                    bfs.push(v);
                    dist[v] = dist[u] + 1;
                    levels[dist[v]].push_back(v);
                }
            }
        }
        return tuple<int, vector<int>>(ans, dist);
    };
    int v1 = get<0>(furthestfrom(0));
    int v2 = get<0>(furthestfrom(v1));
    auto d1 = get<1>(furthestfrom(v1));
    auto d2 = get<1>(furthestfrom(v2));
    int dm = d1[v2];
    assert(d1[v2] == d2[v1]);
    int tot = 0;
    int v3 = -1;
    for(int i=0;i<n;i++){
        if(i == v1 || i == v2) continue;
        if(d1[i] + d2[i] - (d1[i] + d2[i] - dm) / 2>= tot){
            v3 = i;
            tot = d1[i] + d2[i] - (d1[i] + d2[i] - dm) / 2;
        }
    }
    cout<<tot<<"\n";
    cout<<v1+1<<" "<<v2+1<<" "<<v3+1<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}