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
    int n,m;
    cin>>n>>m;
    vector<int> status(n);
    cin>>status;
    vector<vector<pair<int,int>>> adj(m);
    vector<vector<int>> door(n);
    for(int i=0;i<m;i++){
        int s;
        cin>>s;
        for(int j=0;j<s;j++){
            int x;
            cin>>x;
            --x;
            door[x].pb(i);
        }
    }
    for(int i=0;i<n;i++){
        int u = door[i][0], v = door[i][1];
        adj[u].pb({v, status[i]^1});
        adj[v].pb({u, status[i]^1});
    }
    vector<int> state(m, -1);
    for(int i=0;i<m;i++){
        if(~state[i]) continue;
        state[i] = 0;
        queue<int> bfs;
        bfs.push(i);
        while(!bfs.empty()){
            int u = bfs.front();
            bfs.pop();
            for(const auto &[v,t] : adj[u]){
                if(~state[v]){
                    if(state[v]!=(state[u]^t)){
                        cout<<"NO\n";
                        return;
                    }
                    continue;
                }
                state[v] = state[u]^t;
                bfs.push(v);
            }
        }
    }
    cout<<"YES\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}