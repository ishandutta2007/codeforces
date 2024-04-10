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
struct DSU{
    int n;
    vector<int> par;
    vector<int> swi;
    vector<int> sz;
    stack<pair<int,int>> prev;
    DSU(int n) : n(n){
        par.resize(n);
        swi.assign(n,0);
        sz.assign(n,1);
        for(int i=0;i<n;i++){
            par[i] = i;
        }
    }
    pair<int,bool> getroot(int x){
        bool color = 0;
        while(x!=par[x]){
            color^=swi[x];
            x = par[x];
        }
        return pair(x,color);
    }
    bool join(int x,int y){
        auto [r1,c1] = getroot(x);
        auto [r2,c2] = getroot(y);
        if(r1 == r2 && c1 == c2) return false;
        if(r1 == r2){
            prev.push(pair(-1,-1));
            return true;
        }
        if(sz[r1] > sz[r2]){
            swap(r1,r2);
            swap(c1,c2);
        }
        par[r1] = r2;
        swi[r1] = (c1==c2);
        sz[r2] += sz[r1];
        prev.push(pair(r1,r2));
        return true;
    }
    void roll_back(){
        auto [r1,r2] = prev.top();
        prev.pop();
        if(r1 == -1 && r2 == -1) return;
        par[r1] = r1;
        sz[r2]-=sz[r1];
    }
};
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> group(n);
    cin>>group;
    for(auto &g : group) --g;
    vector<bool> valid(k, 1);
    DSU dsu(n);
    int val = k;
    map<pair<int,int>,vector<pair<int,int>>> edges;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        if(group[u] == group[v]){
            if(!dsu.join(u,v)){
                if(valid[group[u]]){
                    valid[group[u]] = false;
                    --val;
                }
            }
            continue;
        }
        if(group[u] > group[v]){
            swap(u,v);
        }
        edges[pair(group[u], group[v])].push_back({u,v});
    }
    ll ans = ll(val) * (val-1)/2;    
    for(const auto &[type,edge] : edges){
        int sz = 0;
        if(!valid[type.first] || !valid[type.second]) continue;
        for(const auto &[u,v] : edge){
            if(!dsu.join(u,v)){
                --ans;
                break;
            }
            ++sz;
        }
        while(sz){
            dsu.roll_back();
            --sz;
        }
    }
    cout<<ans<<"\n";
}
int main() {
    //FILE* input = freopen("input.txt", "r", stdin);
    //FILE* output = freopen("output1.txt", "w", stdout);
    solve();
    //fclose(input);
    //fclose(output);
}