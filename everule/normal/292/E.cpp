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
struct Query{
    int x,y,k;
    Query(int x,int y,int k) : x(x), y(y), k(k) {}
    Query() {}
};
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n), b(n);
    cin>>a>>b;
    vector<int> segtree(n<<1, -1);
    auto set = [&](int l,int r,int idx){
        l += n;
        r += n + 1;
        while(l < r){
            if(l&1){
                segtree[l] = idx;
                ++l;
            }
            if(r&1){
                --r;
                segtree[r] = idx;
            }
            l>>=1;
            r>>=1;
        }
    };
    auto get = [&](int x){
        x+=n;
        int ans = -1;
        while(x){
            ans = max(ans, segtree[x]);
            x >>= 1;
        }
        return ans;
    };
    vector<Query> queries(m);
    for(int i=0;i<m;i++){
        int t;
        cin>>t;
        if(t == 1){
            auto &[x,y,k] = queries[i];
            cin>>x>>y>>k;
            --x;--y;
            set(y,y+k-1,i);
        }
        else{
            int idx;
            cin>>idx;
            --idx;
            int qidx = get(idx);
            if(qidx == -1){
                cout<<b[idx]<<"\n";
            }
            else{
                auto [x,y,k] = queries[qidx];
                cout<<a[idx-y+x]<<"\n";
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}