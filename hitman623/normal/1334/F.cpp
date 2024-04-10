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
#define endl        '\n'
#define hell        100000000000000007LL
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
const int N=500005;
int seg[4*N],lazy[4*N];
void build(int node,int start,int end){
    if(start==end){
        seg[node]=hell*(!!start);
        return;
    }
    int mid=(start+end)>>1;
    build(node<<1,start,mid);
    build(node<<1|1,mid+1,end);
    seg[node]=min(seg[node<<1],seg[node<<1|1]);
}
void update(int node,int start,int end,int l,int r,int val){
    if(lazy[node]!=0){
        seg[node]+=lazy[node];
        if(start!=end){
            lazy[node<<1]+=lazy[node];
            lazy[node<<1|1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(start>end || start>r || end<l) return;
    if(l<=start && end<=r){
        seg[node]+=val;
        seg[node]=min(seg[node],hell);
        if(start!=end){
            lazy[node<<1]+=val;
            lazy[node<<1|1]+=val;
        }
        return;
    }
    int mid=(start+end)>>1;
    update(node<<1,start,mid,l,r,val);
    update(node<<1|1,mid+1,end,l,r,val);
    seg[node]=min(seg[node<<1],seg[node<<1|1]);
}
int query(int node,int start,int end,int l,int r){
    if(start>end || start>r || end<l) return hell;
    if(lazy[node]!=0){
        seg[node]+=lazy[node];
        seg[node]=min(seg[node],hell);
        if(start!=end){
            lazy[node<<1]+=lazy[node];
            lazy[node<<1|1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(start>=l && end<=r) return seg[node];
    int mid=(start+end)>>1;
    int q1=query(node<<1,start,mid,l,r);
    int q2=query(node<<1|1,mid+1,end,l,r);
    return min(q1,q2);
}
int n,m,a[500005],b[500005],p[500005],vis[500005];
vi v[500005];
void solve(){
    cin>>n;
    rep(i,0,n) cin>>a[i];
    rep(i,0,n) cin>>p[i];
    cin>>m;
    rep(i,1,m+1){
        cin>>b[i];
        vis[b[i]]=i;
    }
    build(1,0,m);
    rep(i,0,n){
        if(vis[a[i]]){
            int j=vis[a[i]];
            int d=query(1,0,m,j,j);
            int dd=query(1,0,m,j-1,j-1);
            int ddd=min(d+min(0LL,p[i]),dd)-d;
            update(1,0,m,j,j,ddd);
        }
        int l=lower_bound(b+1,b+m+1,a[i])-b;
        int u=upper_bound(b+1,b+m+1,a[i])-b;
        if(u<=m) update(1,0,m,u,m,min(0LL,p[i]));
        if(0<=l-1) update(1,0,m,0,l-1,p[i]);
    }
    int res=query(1,0,m,m,m);
    if(res<hell/10) cout<<"YES"<<endl<<res<<endl;
    else cout<<"NO"<<endl;
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