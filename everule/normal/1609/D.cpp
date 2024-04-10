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
void solve(){
    int n,d;
    cin>>n>>d;
    DSU dsu(n);
    for(int i=0;i<d;i++){
        int x,y;
        cin>>x>>y;
        --x;--y;
        dsu.join_sets(x, y);
        vector<int> cc;
        for(int i=0;i<n;i++){
            if(dsu.parent[i] == i){
                cc.push_back(dsu.sizof[i]);
            }
        }
        sort(cc.begin(), cc.end());
        reverse(cc.begin(), cc.end());
        int c = n - cc.size();
        ll ans = 0;
        int idx = 0;
        while(c <= i + 1){
            ans += cc[idx];
            idx++;
            c++;
        }
        cout<<ans - 1<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}