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
#define N           100005
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>; 
// int main() {
//     ordered_set<int> s;
//     s.insert(1);
//     s.insert(3);
//     // count of elements in s strictly less than 2
//     cout<<s.order_of_key(2)<<endl;    
//     // print the 0-th smallest number in s (0-indexing)
//     cout<<*s.find_by_order(0)<<endl;
// }
int n,m,p[N],s[N],b[N],inc[N],pref[N],cur=1,ans[N],idx;
vector<pair<int,pii>> v;
mi coord;
ordered_set<pii> bit[2][N];
void add(int f,int pos,int val){
    int x=coord[pos];
    for(;x<=cur;x+=x&(-x)) bit[f][x].insert({val,idx});    
}
void rem(int f,int pos,int val){
    int x=coord[pos];
    for(;x<=cur;x+=x&(-x)) bit[f][x].erase(bit[f][x].find({val,idx}));        
}
int query(int f,int pos,int y){
    int x;
    auto it=coord.upper_bound(pos);
    if(it==coord.begin()) return 0;
    else x=(*(--it)).y;
    int res=0;
    for(;x>0;x-=x&(-x)) res+=bit[f][x].order_of_key(make_pair(y,2*hell));
    return res;
}
void solve(){
    cin>>n>>m;
    rep(i,1,n+1) cin>>p[i];
    rep(i,1,n+1) cin>>s[i];
    rep(i,1,n+1) cin>>b[i],coord[b[i]]=1;
    rep(i,1,m+1) cin>>inc[i];
    rep(i,1,m+1) cin>>pref[i];
    for(auto &i:coord) i.y=cur++;
    rep(i,1,n+1){
        v.pb({p[i],{0,i}});
        v.pb({s[i],{2,i}});
    }
    rep(i,1,m+1) v.pb({inc[i],{1,i}});
    sort(all(v));
    for(auto i:v){
        idx=i.y.y;
        if(i.y.x==0){
            add(0,b[idx],b[idx]+p[idx]);
            add(1,b[idx],b[idx]-p[idx]);
        }
        else if(i.y.x==2){
            rem(0,b[idx],b[idx]+p[idx]);
            rem(1,b[idx],b[idx]-p[idx]);            
        }
        else{
            ans[idx]+=query(0,2*hell,pref[idx]+inc[idx])-query(0,pref[idx]-1,pref[idx]+inc[idx]);
            ans[idx]+=query(1,pref[idx]-1,2*hell)-query(1,pref[idx]-1,pref[idx]-inc[idx]-1);
        }
    }
    rep(i,1,m+1) cout<<ans[i]<<" ";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}