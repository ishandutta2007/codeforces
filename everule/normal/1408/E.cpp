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
struct Edge{
    int u,v,w;
    Edge(int u,int v,int w) : u(u), v(v), w(w) {}
    bool operator<(const Edge &e){
        return w < e.w;
    }
};
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
void solve(){
    int m,n;
    cin>>m>>n;
    vector<int> a(m), b(n);
    cin>>a>>b;
    ll ans = 0;
    vector<Edge> edges;
    for(int i=0;i<m;i++){
        int s;
        cin>>s;
        while(s--){
            int j;
            cin>>j;
            --j;
            edges.emplace_back(i+n,j,-a[i]-b[j]);
            ans+=a[i]+b[j];
        }
    }
    DSU tree(n+m);
    sort(edges.begin(), edges.end());
    for(const auto &[u,v,w] : edges){
        if(tree.find_set(u)!=tree.find_set(v)){
            ans+=w;
            tree.join_sets(u,v);
        }
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}