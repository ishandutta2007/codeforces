#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>; 
ll n,m,t;
map<int,vi> v;
ll bit[200005];
void update(int x,ll y=1){
    x++;
    for(;x<=n;x+=x&(-x)) bit[x]+=y;
}
ll query(int x){
    x++;
    ll res=0;
    for(;x>0;x-=x&(-x)) res+=bit[x];
        return res;
}
void solve(){
    ll ans=-1,ansd=-1;
    v.clear();
    ordered_set<int> s;
    cin>>n>>m>>t;
    rep(i,0,n){
        int x;
        cin>>x;
        v[x].pb(i);
    }
    for(auto i:v){
        for(auto j:i.y){
            update(j,i.x);
            s.insert(j);
        }
        int cnt=sz(s);
        int lo=0,hi=cnt/m+1;
        while(hi-lo>1){
            int mid=(lo+hi)/2;
            int g=*s.find_by_order(mid*m-1);
            if(query(g)*2<=t) lo=mid;
            else hi=mid;
        }
        int complete=lo*m;
        int g=-1;
        if(complete) g=*s.find_by_order(lo*m-1);
        ll rem=t-query(g)*2;
        int last=g;
        lo=g;
        hi=n;
        while(hi-lo>1){
            int mid=(lo+hi)/2;
            if(query(mid)-query(last)<=rem) lo=mid;
            else hi=mid;
        }
        int candidate=min(m,1LL*s.order_of_key(lo+1)-s.order_of_key(last+1));
        if(ans<complete+candidate){
            ans=complete+candidate;
            ansd=i.x;
        }
    }
    for(auto i:v){
        for(auto j:i.y){
            update(j,-i.x);
        }
    }
    cout<<ans<<" "<<min(t,ansd)<<"\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tests=1;
    cin>>tests;
    while(tests--){
        solve();
    }
    return 0;
}