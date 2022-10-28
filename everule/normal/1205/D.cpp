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
    vector<vector<int>> adj(n);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(n == 1) return;
    if(n == 2){
        cout<<"1 2 1\n";
        return;
    }
    auto getcentroid = [&](){
        vector<int> sz(n, 1);
        function<int(int,int)> dfs = [&](int u,int par){
            for(const auto &v : adj[u]){
                if(v == par) continue;
                dfs(v,u);
                sz[u] += sz[v];
            }
            return 0;
        };
        dfs(0,0);
        dfs = [&](int u,int par){
            for(const auto &v : adj[u]){
                if(v == par) continue;
                if(sz[v] > n/2){
                    return dfs(v,u);
                }
            }
            return u;
        };
        return dfs(0,0);
    };
    int c = getcentroid();
    vector<int> sz(n, 1);
    function<void(int,int)> dfs = [&](int u,int par){
        for(const auto &v : adj[u]){
            if(v == par) continue;
            dfs(v,u);
            sz[u] += sz[v];
        }
    };
    dfs(c,c);
    //cout<<c<<"\n";
    vector<pair<int,int>> set1;
    for(const auto &v : adj[c]){
        set1.push_back(pair(sz[v], v));
    }
    sort(set1.begin(), set1.end());
    int mnx = (n + 1)/3;
    int sum = 0;
    vector<pair<int,int>> set2;
    while(sum < mnx){
        sum += set1.back().first;
        set2.push_back(set1.back());
        set1.pop_back();
    }
    map<pair<int,int>, int> edgeweights;
    function<void(int,int)> setsmall = [&](int u,int par){
        int sum = 1;
        for(const auto &v : adj[u]){
            if(v == par) continue;
            setsmall(v,u);
            edgeweights[pair(v,u)] = sum;
            sum += sz[v];
        }
    };
    int x = 1;
    for(const auto &[szv, v] : set1){
        edgeweights[pair(c,v)] = x;
        setsmall(v,c);
        x += szv;
    }
    function<void(int,int)> setbig = [&](int u,int par){
        int sum = x;
        for(const auto &v : adj[u]){
            if(v == par) continue;
            setbig(v,u);
            edgeweights[pair(v,u)] = sum;
            sum += sz[v] * x;
        }
    };
    int val = x;
    for(const auto &[szv,v] : set2){
        edgeweights[pair(c,v)] = val;
        setbig(v,c);
        val += szv * x;
    }
    for(const auto &[e,w] : edgeweights){
        auto [u,v] = e;
        cout<<u + 1<<" "<<v + 1<<" "<<w<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}