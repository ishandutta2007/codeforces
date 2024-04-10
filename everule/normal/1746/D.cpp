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
    int n,k;
    cin>>n>>k;
    vector<vector<int>> g(n);
    for(int i=1;i<n;i++){
        int p;
        cin>>p;
        --p;
        g[p].push_back(i);
    }
    vector<int> s(n);
    cin>>s;
    ll ans = 0;
    function<ll(int, int)> dfs = [&](int u, int paths) -> ll{
        if(g[u].size() == 0){
            ans += 1ll * paths * s[u];
            return s[u];
        }
        vector<ll> best_inc;
        ans += 1ll * paths * s[u];
        best_inc.reserve(g[u].size());
        for(auto &v : g[u]){
            best_inc.push_back(dfs(v, paths / g[u].size()));
        }
        sort(best_inc.begin(), best_inc.end(), greater<ll>());
        int num_take = paths % g[u].size();
        ans += accumulate(best_inc.begin(), best_inc.begin() + num_take, 0ll);
        return best_inc[num_take] + s[u];
    };
    dfs(0, k);
    cout<<ans<<"\n";
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