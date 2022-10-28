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
    int n;
    cin>>n;
    vector<int> a(n);
    cin>>a;
    vector<vector<int>> adj(n);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int mn = 0, mx = n;
    const int INF = 1e9 + 7;
    while(mn < mx){
        int mid = (mn + mx)/2;
        vector<array<int, 2>> dp(n, {INF, INF});
        function<void(int,int)> dfs = [&](int u,int par){
            array<array<int, 2>, 2> mx;
            for(int i=0;i<2;i++) for(int j=0;j<2;j++) mx[i][j] = 1;
            for(const auto &v : adj[u]){
                if(v == par) continue; 
                dfs(v,u);
                for(int i=0;i<2;i++){
                    if(dp[v][i] > mx[i][0]){
                        mx[i][1] = mx[i][0];   
                        mx[i][0] = dp[v][i];
                    }
                    else if(dp[v][i] > mx[i][1]){
                        mx[i][1] = dp[v][i];
                    }
                }
            }
            if(mx[0][0] + mx[0][1] - 1 <= mid && a[u]!=1){
                dp[u][0] = min(dp[u][0], mx[0][0]);
                dp[u][1] = min(dp[u][1], mx[0][0] + 1);
            }
            if(mx[1][0] + mx[1][1] - 1 <= mid && a[u]!=2){
                dp[u][0] = min(dp[u][0], mx[1][0] + 1);
                dp[u][1] = min(dp[u][1], mx[1][0]); 
            }
        };
        dfs(0,0);
        if(dp[0][0] == INF && dp[0][1] == INF){
            mn = mid + 1;
        }
        else{
            mx = mid;
        }
    }
    cout<<mn/2 + 1<<"\n";
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