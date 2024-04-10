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
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>; 
//change null_type to get ordered_map
// int main() {
//     ordered_set<int> s;
//     s.insert(1);
//     s.insert(3);
//     // count of elements in s strictly less than 2
//     cout<<s.order_of_key(2)<<endl;    
//     // print the 0-th smallest number in s (0-indexing)
//     cout<<*s.find_by_order(0)<<endl;
// }
ordered_set<int> s;
int n,a[200005];
vii w[200005];
map<int,vi> mp;
int ans[200005];
void solve(){
    cin>>n;
    rep(i,1,n+1){
        cin>>a[i];
        mp[a[i]].pb(i);
    }
    int q;
    cin>>q;
    rep(i,1,q+1){
        int k,pos;
        cin>>k>>pos;
        w[k].pb({i,pos});
    }
    vector<pair<int,vi>> v(all(mp));
    int cur=0;
    for(int i=sz(v)-1;i>=0;i--){
        for(auto j:v[i].y){
            s.insert(j);
            cur++;
            for(auto k:w[cur]){
                ans[k.x]=a[*s.find_by_order(k.y-1)];
            }
        }
    }
    rep(i,1,q+1) cout<<ans[i]<<"\n";
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