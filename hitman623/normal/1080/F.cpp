#include <bits/stdc++.h>

#define int         long long
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
// #define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,k;
vii v[1000005];
vii tree[1000005];
void build(int node,int l,int r){
    if(l==r){
        v[l].pb({hell-1,hell-1});
        sort(all(v[l]));
        mi mp;
        for(auto i:v[l]){
            if(mp.count(i.x)==0) mp[i.x]=i.y;
            else mp[i.x]=min(mp[i.x],i.y);
        }
        vii d(all(mp));
        tree[node]=d;
        for(int i=sz(tree[node])-2;i>=0;i--){
            tree[node][i].y=min(tree[node][i].y,tree[node][i+1].y);
        }
        return;
    }
    int mid=(l+r)/2;
    build(2*node,l,mid);
    build(2*node+1,mid+1,r);
    vi d;
    for(auto i:tree[node<<1]) d.pb(i.x);
    for(auto i:tree[node<<1|1]) d.pb(i.x);
    sort(all(d));
    d.resize(unique(all(d))-d.begin());
    for(auto i:d){
        pii g={i,-hell};
        int x=lower_bound(all(tree[node<<1]),g)-tree[node<<1].begin();
        int y=lower_bound(all(tree[node<<1|1]),g)-tree[node<<1|1].begin();
        int h=0;
        if(x<sz(tree[node<<1])) h=max(h,tree[node<<1][x].y);
        if(y<sz(tree[node<<1|1])) h=max(h,tree[node<<1|1][y].y);
        tree[node].pb({i,h});
    }
}
int query(int node,int l,int r,int a,int b,int x){
    if(l>b or r<a) return -hell;
    if(a<=l and r<=b){
        pii temp={x,-hell};
        int g=lower_bound(all(tree[node]),temp)-tree[node].begin();
        if(g<sz(tree[node])) return tree[node][g].y;
        else return hell;
    }
    int mid=(l+r)/2;
    return max(query(2*node,l,mid,a,b,x),query(2*node+1,mid+1,r,a,b,x));
}
void solve(){
    cin>>n>>m>>k;
    rep(i,0,k){
        int l,r,p;
        cin>>l>>r>>p;
        v[p].pb({l,r});
    }
    build(1,1,n);
    rep(i,1,m+1){
        int a,b,x,y;
        cin>>a>>b>>x>>y;
        if(query(1,1,n,a,b,x)>y) cout<<"no"<<endl;
        else cout<<"yes"<<endl;
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