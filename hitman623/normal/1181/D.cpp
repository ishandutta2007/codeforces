#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<ll,ll>
#define vi          vector<ll>
#define vii         vector<pii>
#define mi          map<ll,ll>
#define mii         map<pii,ll>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (ll)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(ll i=a;i<b;i++)
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>; 
ll n,m,q,f[500005],ans[500005],p[500005];
vii w;
vii v[500005];
ordered_set<int> st;
//change null_type to get ordered_map
// ll main() {
//     ordered_set<ll> s;
//     s.insert(1);
//     s.insert(3);
//     // count of elements in s strictly less than 2
//     cout<<s.order_of_key(2)<<endl;    
//     // prll the 0-th smallest number in s (0-indexing)
//     cout<<*s.find_by_order(0)<<endl;
// }
void solve(){
    cin>>n>>m>>q;
    rep(i,0,n){
        ll x;
        cin>>x;
        f[x]++;
    }
    rep(i,1,m+1) w.pb({f[i],i});
    sort(all(w));
    rep(i,0,sz(w)) p[i]=w[i].x+(i?p[i-1]:0);
    rep(i,0,q){
        ll k;
        cin>>k;
        k-=n;
        ll lo=0,hi=m;
        while(hi-lo>1){
            ll mid=(lo+hi)/2;
            if((mid+1)*w[mid].x-p[mid]<k) lo=mid;
            else hi=mid;
        }
        k-=(lo+1)*w[lo].x-p[lo];
        k%=(lo+1);
        if(k==0) k=lo+1;
        v[lo].pb({k,i});
    }
    rep(i,0,sz(w)){
        st.insert(w[i].y);
        for(auto j:v[i]){
            ans[j.y]=*st.find_by_order(j.x-1);
        }
    }
    rep(i,0,q) cout<<ans[i]<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}