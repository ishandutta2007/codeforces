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
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,v[200005],height[200005],tim,entry[200005],ext[200005];
vi adj[200005];
void dfs(int node,int par){
    height[node]=height[par]+1;
    entry[node]=++tim;
    for(auto i:adj[node]){
        if(i!=par){
            dfs(i,node);
        }
    }
    ext[node]=tim;
}
const int N=200005;
int seg[2][4*N],lazy[2][4*N];
void update(int node,int start,int end,int l,int r,int val,int f){
    if(lazy[f][node]!=0){
        seg[f][node]+=lazy[f][node];
        if(start!=end){
            lazy[f][node<<1]+=lazy[f][node];
            lazy[f][node<<1|1]+=lazy[f][node];
        }
        lazy[f][node]=0;
    }
    if(start>end || start>r || end<l) return;
    if(l<=start && end<=r){
        seg[f][node]+=val;
        if(start!=end){
            lazy[f][node<<1]+=val;
            lazy[f][node<<1|1]+=val;
        }
        return;
    }
    int mid=(start+end)>>1;
    update(node<<1,start,mid,l,r,val,f);
    update(node<<1|1,mid+1,end,l,r,val,f);
    seg[f][node]=seg[f][node<<1]+seg[f][node<<1|1];
}
int query(int node,int start,int end,int l,int r,int f){
    if(start>end || start>r || end<l) return 0;
    if(lazy[f][node]!=0){
        seg[f][node]+=lazy[f][node];
        if(start!=end){
            lazy[f][node<<1]+=lazy[f][node];
            lazy[f][node<<1|1]+=lazy[f][node];
        }
        lazy[f][node]=0;
    }
    if(start>=l && end<=r) return seg[f][node];
    int mid=(start+end)>>1;
    int q1=query(node<<1,start,mid,l,r,f);
    int q2=query(node<<1|1,mid+1,end,l,r,f);
    return q1+q2;
}
void solve(){
    cin>>n>>m;
    rep(i,1,n+1){
        cin>>v[i];
    }
    rep(i,0,n-1){
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1,0);
    rep(i,1,n+1) update(1,1,n,entry[i],entry[i],v[i],0),update(1,1,n,entry[i],entry[i],v[i],1);
    while(m--){
        int type;
        cin>>type;
        if(type==1){
            int x,y;
            cin>>x>>y;
            if(height[x]%2){
                update(1,1,n,entry[x],ext[x],y,0);
                update(1,1,n,entry[x],ext[x],-y,1);
            }
            else{
                update(1,1,n,entry[x],ext[x],-y,0);
                update(1,1,n,entry[x],ext[x],y,1);
            }
        }
        else{
            int x;
            cin>>x;
            if(height[x]%2) cout<<query(1,1,n,entry[x],entry[x],0)<<endl;
            else cout<<query(1,1,n,entry[x],entry[x],1)<<endl;
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