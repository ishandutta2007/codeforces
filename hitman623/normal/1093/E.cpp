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
int n,m,posa[200005];
ordered_set<int> os[800005];
int a[200005],b[200005];
ordered_set<int> bit[200005];
void add(int x,int y=1){
    for(;x<=n;x+=x&(-x)) bit[x].insert(y);
}
void rem(int x,int y=1){
    for(;x<=n;x+=x&(-x)) bit[x].erase(y);
}
int query(int x,int y){
    int res=0;
    for(;x>0;x-=x&(-x)) res+=bit[x].order_of_key(y);
    return res;
}
void solve(){
    cin>>n>>m;
    rep(i,1,n+1){
        cin>>a[i];
        posa[a[i]]=i;
    }
    rep(i,1,n+1){
        cin>>b[i];
        add(posa[b[i]],i);
    }
    while(m--){
        int type;
        cin>>type;
        if(type==1){
            int la,ra,lb,rb;
            cin>>la>>ra>>lb>>rb;
            cout<<query(ra,rb+1)-query(ra,lb)-query(la-1,rb+1)+query(la-1,lb)<<"\n";
        }
        else{
            int x,y;
            cin>>x>>y;
            rem(posa[b[x]],x);
            rem(posa[b[y]],y);
            swap(b[x],b[y]);
            add(posa[b[x]],x);
            add(posa[b[y]],y);
        }
    }
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