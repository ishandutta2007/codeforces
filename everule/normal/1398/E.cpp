#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long;
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
struct node{
    ll count = 0;
    ll val=0;
    ll sum = 0;
    node(ll count, ll val, ll sum) : count(count), val(val), sum(sum) {}
    node() {}
};
struct segment_tree{
    vector<node> segtree;
    ll n;
    node join(const node &x,const node &y){
        return node(x.count + y.count, x.val + y.val, x.sum + y.sum);
    }
    segment_tree(vector<ll> &seq){
        n = 32 - __builtin_clz((ll)seq.size() - 1);
        n = 1<<n;
        assert(n>=(ll)seq.size());
        segtree.resize(n<<1);
        for(ll i=0;i<n;i++){
            segtree[i+n].sum = seq[i];
        }
        for(ll i=n-1;i>0;--i){
            segtree[i] = join(segtree[i<<1], segtree[(i<<1)|1]);
        }
    }
    void update(ll pos){
        pos+=n;
        segtree[pos].count^=1;
        segtree[pos].val ^= segtree[pos].sum;
        pos>>=1;
        while(pos){
            segtree[pos]=join(segtree[2*pos],segtree[2*pos+1]);
            pos>>=1;
        }
    }
    ll query(ll mxcount){
        ll idx = 1;
        if(segtree[1].count <= mxcount){
            return segtree[1].val;
        }
        node ans(0, 0, 0);
        while(idx<n){
            idx<<=1;
            node curr = join(ans, segtree[idx]);
            if(curr.count <= mxcount){
                ans = curr;
                ++idx;
            }
        }
        return ans.val;
    }
};
void solve(){
    ll n;
    cin>>n;
    vector<pair<ll,ll>> queries(n);
    vector<ll> powers;
    for(auto &[t, d] : queries){
        cin>>t>>d;
        if(d>0){
            powers.pb(d);
        }
    }
    sort(powers.begin(), powers.end(), greater<ll>());
    map<ll,ll> getidx;
    for(ll i=0;i<(ll)powers.size();i++){
        getidx[powers[i]] = i;
    }
    segment_tree segtree(powers);
    set<ll> fire, lightning;
    auto update = [&](ll t,ll d){
        if(t==0){
            segtree.update(getidx[abs(d)]);
            if(d>0){
                fire.insert(d);
            }
            else{
                fire.erase(-d);
            }
        }
        else{
            if(d>0){
                if(!lightning.empty() && d<*lightning.begin()){
                    segtree.update(getidx[*lightning.begin()]);
                }
                else if(!lightning.empty()){
                    segtree.update(getidx[d]);
                }
                lightning.insert(d);
            }
            else{
                d=-d;
                if(d>*lightning.begin()){
                    segtree.update(getidx[d]);
                }
                lightning.erase(d);
                if(!lightning.empty() && d<*lightning.begin()){
                    segtree.update(getidx[*lightning.begin()]);
                }
            }
        }
    };
    ll ans = 0;
    for(const auto &[t,d] : queries){
        update(t,d);   
        ans+=d;
        //cout<<ans<<" ";
        cout<<ans+segtree.query(lightning.size())<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}