#include <iostream>
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
    int n,a,b;
    cin>>n>>a>>b;
    --a;--b;
    vector<vector<int>> adj(n);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> onpath(n);
    vector<int> path;
    function<bool(int,int)> mark = [&](int u,int p){
        bool is = (u == b);
        for(const auto &v : adj[u]){
            if(v == p) continue;
            is |= mark(v,u);
        }
        onpath[u] = is;
        if(is) path.push_back(u);
        return is;
    };
    mark(a,-1);
    reverse(path.begin(), path.end());
    int len = path.size() - 1;
    bool ans = 0;
    vector<array<int, 2>> dp(n, {0,0});
    vector<bool> good(n);
    function<void(int,int)> dpcalc = [&](int u,int p){
        for(const auto &v : adj[u]){
            if(v == p || onpath[v]) continue;
            dpcalc(v,u);
            if(dp[u][0] < dp[v][0] + 1){
                dp[u][1] = dp[u][0];
                dp[u][0] = dp[v][0] + 1;
            }
            else if(dp[u][1] < dp[v][0] + 1){
                dp[u][1] = dp[v][0] + 1;
            }
            good[u] = good[u] | good[v];
        }
        good[u] = good[u] | (dp[u][0] >= len && dp[u][1] >= len);
    };
    for(const auto &u : path){
        dpcalc(u,u);
    }
    int l = 0, r = len;
    int mxl=dp[b][0], mnr = len - dp[a][0];
    for(;l<r;){
        bool flag = 0;
        while(l<len-1 && l<mxl){
            ++l;
            mnr = min(mnr, l + (len - dp[path[l]][0]));
            flag = 1;
        }
        while(r>1 && r>mnr){
            --r;
            mxl = max(mxl, r - (len - dp[path[r]][0]));
            flag = 1;
        }
        if(!flag) break;
    }
    for(int i=0;i<=len;i++){
        if(i <= l || i >= r) ans |= good[path[i]];
    }
    vector<int> pl(len+1), pr(len+1);
    pl[0] = 0;
    pr[len] = 0;
    for(int i=1;i<len;i++){
        pl[i] = max(pl[i-1], dp[path[i-1]][0]) + 1;
    }
    for(int i=len-1;i>0;--i){
        pr[i] = max(pr[i+1], dp[path[i+1]][0]) + 1;
    }
    for(int i=1;i<len;i++){
        if(i>l && i<r) continue;
        if(dp[path[i]][0]>=len && pl[i] >= len && pr[i] >= len){
            ans = 1;
        }
    }
    cout<<(ans ? "YES" : "NO")<<"\n";
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