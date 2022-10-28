#include <bits/stdc++.h>
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
    vector<vector<int>> g(n);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> msk(n);
    vector<int> dep(n);
    {
        function<int(int,int)> dfs = [&](int u,int p){
            array<int, 3> cnt = {0, 0, 0};
            for(auto &v : g[u]){
                if(v == p) continue;
                dep[v] = dep[u] + 1;
                cnt[dfs(v, u)]++;
            }
            if(u == 0){
                return msk[u] = ((cnt[1] == cnt[2] + 1 || cnt[1] == cnt[2]) && cnt[0] == 0);
            }
            if(cnt[0]) return msk[u] = 0;
            if(cnt[1] - cnt[2] > 2) return msk[u] = 0;
            if(cnt[2] - cnt[1] > 1) return msk[u] = 0;
            if(cnt[1] <= cnt[2]) return msk[u] = 1;
            else return msk[u] = 2;
        };
        dfs(0, 0);
    }
    if(msk[0] == 0){
        cout<<"NO\n";
        return;
    }
    vector<pair<int, int>> ans;
    {
        function<void(int,int)> dfs = [&](int u, int p){
            if(dep[u] < dep[p]){
                ans.emplace_back(p, u);
                return;
            }
            vector<int> o, e;
            for(auto &v : g[u]){
                if(v == p) continue;
                if(msk[v] == 1) o.push_back(v);
                else e.push_back(v);
            }
            if(u != 0 && msk[u] == 1) o.push_back(p);
            else if(u != 0) e.push_back(p);
            int deg = g[u].size();
            while(deg > 0){
                if(deg % 2){
                    dfs(o.back(), u);
                    o.pop_back();
                }
                else{
                    dfs(e.back(), u);
                    e.pop_back();
                }
                --deg;
            }
        };
        dfs(0, 0);
    }
    //cout+msk;
    cout<<"YES\n";
    for(auto &[u, v] : ans){
        cout<<u+1<<" "<<v+1<<"\n";
    }
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