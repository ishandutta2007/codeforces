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
struct RangeUpdate{ //requires commutativity and associativity
    int n;
    vector<T> segtree;
    function<T(const T&, const T&)> join;
    T base;
    RangeUpdate(int n, function<T(const T&,const T&)> join, T base) : n(n), join(join), base(base){
        segtree.resize(n<<1, base);
    }
    RangeUpdate(vector<T> &seq, function<T(const T&,const T&)> join, T base) : n(seq.size()), join(join), base(base){
        segtree.resize(n<<1, base);
        for(int i=0;i<n;i++){
            segtree[n+i] = seq[i];
        }
    }
    T query(int pos){
        pos+=n;
        T ans = segtree[pos];
        pos>>=1;
        while(pos){
            ans = join(ans, segtree[pos]);
            pos>>=1;
        }
        return ans;
    }
    void update(int l,int r,T val){
        if(l < 0) l = 0;
        if(r >= n) r = n-1;
        if(l > r) return;
        l+=n;
        r+=n+1;
        while(l < r){
            if(l&1){
                segtree[l] = join(segtree[l], val);
                ++l;
            }
            if(r&1){
                --r;
                segtree[r] = join(segtree[r], val);
            }
            l>>=1;
            r>>=1;
        }
    }
};
void solve(){
    int n;
    cin>>n;
    vector<int> seq(n);
    cin>>seq;
    ll ans = 0;
    RangeUpdate<ll> st(n, [&](ll x,ll y){
        return x + y;
    }, 0);
    for(int i=0;i<n;i++){
        if(seq[i] != 1) st.update(i+2, i + seq[i], 1);
        ll q = st.query(i);
        if(q < seq[i] - 1) ans += seq[i] - 1 - q;
        else st.update(i+1, i+1, q - seq[i] + 1);
    }
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