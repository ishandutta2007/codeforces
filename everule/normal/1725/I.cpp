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
    vector<int> parent;
    vector<int> sizof;
    int n;
    DSU(int N){
        n=N;
        parent.resize(n);
        sizof.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            sizof[i]=1;
        }
    }
    int get_size(int x){
        return sizof[find_set(x)];
    }
    int find_set(int v){
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }
    void join_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sizof[a] < sizof[b]){
                swap(a, b);
            }
            parent[b] = a;
            sizof[a] += sizof[b];
        }
    }
};
const int p = 998244353;
void solve(){
    int n;
    cin>>n;
    DSU dsu(n);
    ll ans = 1;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        int s1 = dsu.get_size(u);
        int s2 = dsu.get_size(v);
        dsu.join_sets(u, v);
        ans *= s1;
        ans %= p;
        ans *= s1;
        ans %= p;
        ans *= s2;
        ans %= p;
        ans *= s2;
        ans %= p;
    }
    for(int i=1;i<2*n-2;i+=2){
        ans *= i;
        ans %= p;
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}