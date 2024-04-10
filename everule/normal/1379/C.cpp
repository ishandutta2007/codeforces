#include <iostream>
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
struct node{
    ll minvalue, count,sum;
    node(){}
    node(ll minvalue, ll count,ll sum) : minvalue(minvalue), count(count), sum(sum){}
};
struct segment_tree{
    vector<node> segtree;
    int n;
    node join(const node &x, const node &y){
        return node(min(x.minvalue, y.minvalue), x.count + y.count, x.sum + y.sum);
    }
    segment_tree(const vector<int> &a){
        n = 1;
        while(n<a.size()){
            n*=2;
        }
        segtree.resize(n<<1, node(1e9, 0, 0));
        for(int i=0;i<a.size();i++){
            segtree[n+i] = node(a[i], 1, a[i]);
        }
        for(int i=n-1;i>=0;--i){
            segtree[i] = join(segtree[(i<<1)], segtree[(i<<1)|1]);
        }
    }
    void update(int pos, node val){
        pos+=n;
        segtree[pos]=val;
        pos>>=1;
        while(pos){
            segtree[pos]=join(segtree[2*pos],segtree[2*pos+1]);
            pos>>=1;
        }
    }
    node query(int minvalue, int count){
        node ans = node(1e9,0,0);
        int idx = 1;
        while(idx < n){
            idx<<=1;
            idx|=1;
            node curr = join(ans, segtree[idx]);
            if(curr.minvalue>minvalue && curr.count<=count){
                --idx;
                ans = curr;
            }
        }
        node curr = join(segtree[idx], ans);
        if(curr.minvalue>minvalue && curr.count<=count){
            ans = curr;
        }
        return ans;
    }
};
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<pair<int,int>> flowers(m);
    vector<int> a(m);
    for(auto &flower : flowers){
        cin>>flower.second>>flower.first;
    }
    for(int i=0;i<m;i++){
        a[i] = flowers[i].second;
    }
    sort(a.begin(), a.end());
    map<int,vector<int>> mapper;
    for(int i=0;i<m;i++){
        mapper[a[i]].pb(i);
    }
    segment_tree segtree(a);
    sort(flowers.begin(), flowers.end());
    ll ans = -1;
    for(int i=m-1;i>=0;--i){
        int idx = mapper[flowers[i].second].back();
        mapper[flowers[i].second].pop_back();
        segtree.update(idx, node(1e9,0,0));
        ll curr = flowers[i].second;
        node query = segtree.query(flowers[i].first, n-1);
        curr += (n-1-query.count) * flowers[i].first + query.sum;
        ans = max(ans, curr);
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