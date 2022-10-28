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
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<unordered_set<int, custom_hash>> adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    if(ll(k)*(k-1)/2 > m){
        cout<<"-1\n";
        return;
    }
    unordered_set<int, custom_hash> useless, maybeclique, good;
    for(int i=0;i<n;i++){
        if(adj[i].size() < k - 1){
            useless.insert(i);
        }
        if(adj[i].size() == k - 1){
            maybeclique.insert(i);
        }
        if(adj[i].size() >= k){
            good.insert(i);
        }
    }
    int cnt = 0;
    while(useless.size() || maybeclique.size()){
        if(useless.size()){
            int u = *useless.begin();
            for(const auto &v : adj[u]){
                adj[v].erase(u);
                if(adj[v].size() == k - 1){
                    good.erase(v);
                    maybeclique.insert(v);
                }
                if(int(adj[v].size()) == k-2){
                    maybeclique.erase(v);
                    useless.insert(v);
                }
            }
            useless.erase(u);
            continue;
        }
        if(maybeclique.size()){
            int u = *maybeclique.begin();
            vector<int> clique;
            clique.push_back(u);
            for(const auto &v : adj[u]){
                clique.push_back(v);
            }
            bool flag = 1;
            for(int i=0;i<k && flag;i++){
                for(int j=i+1;j<k && flag;j++){
                    flag &= (adj[clique[i]].count(clique[j]) == 1);
                }
            }
            if(flag){
                cout<<"2\n";
                for(int i=0;i<k;i++){
                    cout<<clique[i] + 1<<" ";
                }
                cout<<"\n";
                return;
            }
            for(const auto &v : adj[u]){
                adj[v].erase(u);
                if(adj[v].size() == k - 1){
                    good.erase(v);
                    maybeclique.insert(v);
                }
                if(int(adj[v].size()) == k-2){
                    maybeclique.erase(v);
                    useless.insert(v);
                }
            }
            maybeclique.erase(u);
        }
    }
    if(good.size() > k){
        cout<<"1 "<<good.size()<<"\n";
        for(const auto &v : good){
            cout<<v+1<<" ";
        }
        cout<<"\n";
        return;
    }
    cout<<"-1\n";
    return;
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