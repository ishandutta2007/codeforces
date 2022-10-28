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
template<typename T>
struct segment_tree{
    vector<T> segtree;
    int n;
    T join(T x, T y){
        return x^y;
    }
    T base = 0;
    segment_tree(int n) : n(n){
        segtree.resize(n<<1);
    }
    void update(int pos, T val){
        pos+=n;
        segtree[pos]=val;
        pos>>=1;
        while(pos){
            segtree[pos]=join(segtree[2*pos],segtree[2*pos+1]);
            pos>>=1;
        }
    }
    T query(int x, int y){
        if(x<0 || y>=n) assert(0);
        T ansl=base;
        T ansr=base;
        x+=n;
        y+=n+1;
        while(x<y){
            if(x&1){
                ansl=join(ansl, segtree[x++]);
            }
            if(y&1){
                ansr=join(segtree[--y], ansr);
            }
            x>>=1;
            y>>=1;
        }
        return join(ansl, ansr);
    }
    void build(){
        for(int i=n-1;i>0;--i){
            segtree[i] = join(segtree[i<<1], segtree[(i<<1)|1]);
        }
    }
};
struct query{
    int l,r,idx;
    bool operator<(const query &q){
        return r<q.r;
    }
};
void solve(){
    int n;
    cin>>n;
    vector<int> seq(n);
    cin>>seq;
    vector<int> prefixsum(n+1);
    for(int i=1;i<=n;i++){
        prefixsum[i] = prefixsum[i-1]^seq[i-1];
    }
    int Q;
    cin>>Q;
    vector<query> queries(Q);
    vector<int> ans(Q);
    for(int i=0;i<Q;i++){
        cin>>queries[i].l>>queries[i].r;
        queries[i].idx = i;
    }
    sort(queries.begin(), queries.end());
    int ridx = 0;
    map<int,int> last;
    segment_tree<int> segtree(n);
    for(const auto &[l,r,idx] : queries){
        while(ridx<r){
            if(last.count(seq[ridx])){
                segtree.update(last[seq[ridx]], 0);
            }
            last[seq[ridx]] = ridx;
            segtree.update(ridx, seq[ridx]);
            ++ridx;
        }
        ans[idx] = prefixsum[r]^prefixsum[l-1];
        ans[idx]^=segtree.query(l -1,r - 1);
    }
    for(const auto &x : ans){
        cout<<x<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}