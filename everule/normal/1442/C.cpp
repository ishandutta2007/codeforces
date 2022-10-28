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
const int p = 998244353;
ll modpower(ll base, ll power, ll mod=p){
    ll ans = 1;
    base%=mod;
    while(power){
        if(power&1){
            ans*=base;
            ans%=mod;
        }
        base*=base;
        base%=mod;
        power>>=1;
    }
    return ans;
}
const int lgn = 30;
const ll INFL = 1e18;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    vector<vector<int>> adjr(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        adj[u].push_back(v);
        adjr[v].push_back(u);
    }
    vector<int> dist(n*lgn, -1);
    function<void()> dpbfs = [&](){
        deque<int> bfs;
        bfs.push_back(0);
        dist[0] = 0;
        while(!bfs.empty()){
            int u = bfs.front();
            bfs.pop_front();
            vector<int>& edges = (u/n)%2 ? adjr[u%n] : adj[u%n];
            if(u + n < lgn*n){
                if(dist[u+n] == -1 || dist[u+n] > dist[u]){ 
                    bfs.push_front(u+n);
                    dist[u+n] = dist[u];
                }
            }
            for(auto v : edges){
                v += (u/n) * n;
                if(dist[v] == -1 || dist[v] > dist[u] + 1){
                    bfs.push_back(v);
                    dist[v] = dist[u] + 1;
                }
            }
        }
    };
    dpbfs();
    //cout+dist;
    ll ans = INFL;
    for(int i=0;i<lgn;i++){
        int idx = i*n + n-1;
        if(dist[idx] == -1) continue;
        ans = min(ans, (1ll<<i) + dist[idx] - 1);
    }
    if(ans != INFL){
        std::cout<<ans<<"\n";
        return;
    }
    auto mintranspose = [&](){
        dist[0] = 0;
        deque<int> bfs;
        bfs.push_back(0);
        while(!bfs.empty()){
            int u = bfs.front();
            bfs.pop_front();
            vector<int> &edges = (u>=n ? adjr[u-n] : adj[u]);
            for(auto v : edges){
                v += (u>=n) * n;
                if(dist[v] != -1 && dist[v] <= dist[u]) continue;
                bfs.push_front(v);
                dist[v] = dist[u];
            }
            if(u >= n){
                if(dist[u-n] == -1 || dist[u-n] > dist[u] + 1){
                    bfs.push_back(u-n);
                    dist[u-n] = dist[u] + 1;
                }
            }
            else{
                if(dist[u+n] == -1 || dist[u+n] > dist[u] + 1){
                    bfs.push_back(u+n);
                    dist[u+n] = dist[u] + 1;
                }
            }
        }
    };
    dist.assign(2*n, -1);
    mintranspose();
    vector<int> dp(n<<1, -1);
    vector<int> bfsorder;
    auto finddp = [&](){
        deque<int> bfs;
        bfs.push_back(0);
        dp[0] = 0;
        while(!bfs.empty()){
            int u = bfs.front();
            bfsorder.push_back(u);
            bfs.pop_front();
            vector<int>& edges = (u>=n ? adjr[u-n] : adj[u]);
            if(u >= n){
                if(dp[u-n]==-1 || dp[u-n] > dp[u]){
                    if(dist[u-n] > dist[u]){
                        dp[u-n] = dp[u];
                        bfs.push_front(u-n);
                    }
                }
            }
            else{
                if(dp[u+n]==-1 || dp[u+n] > dp[u]){
                    if(dist[u+n] > dist[u]){
                        dp[u+n] = dp[u];
                        bfs.push_front(u+n);
                    }
                }
            }
            for(auto v : edges){
                v += (u>=n)*n;
                if(dp[v] != -1 && dp[v] <= dp[u] + 1) continue;
                if(dist[v] < dist[u]) continue;
                dp[v] = dp[u] + 1;
                bfs.push_back(v);
            }
        }
    };
    finddp();
    /*
    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<n;i++){
        cout<<dist[i+n]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<n;i++){
        cout<<dp[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<n;i++){
        cout<<dp[i+n]<<" ";
    }
    cout<<"\n";*/
    ll mvt = 0;
    if(dist[n-1] == dist[2*n-1]){
        mvt = min(dp[n-1], dp[2*n-1]);
    }
    if(dist[n-1] > dist[2*n-1]){
        mvt = dp[2*n-1];
    }
    if(dist[n-1] < dist[2*n-1]){
        mvt = dp[n-1];
    }
    mvt += modpower(2,min(dist[n-1], dist[2*n-1])) - 1;
    std::cout<<mvt%p<<"\n";
}
//remember to change stuff to submit version
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("output.txt", "w", stdout);
    solve();
}