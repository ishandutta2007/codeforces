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
#define hell        1000000000000000007LL
#define M           1000001
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,T,p[100005],l[100005],c[100005],t[100005],tim[100005],val[100005],ans[100005];
vi a[100005];
int seg[4000005][2];
int query(int node,int start,int end,int v){
    if(v==0) return 0;
    if(start==end) return min(seg[node][0],v/start);
    int mid=(start+end)>>1;
    if(seg[2*node][1]<=v) return seg[2*node][0]+query(2*node+1,mid+1,end,v-seg[2*node][1]);
    else return query(2*node,start,mid,v);
}
void update(int node,int start,int end,int x,int v){
    if(start>x or end<x) return;
    if(start==end){
        seg[node][0]+=v;
        seg[node][1]+=start*v;
        return;
    }
    int mid=(start+end)>>1;
    if(x<=mid) update(node<<1,start,mid,x,v);
    else update(node<<1|1,mid+1,end,x,v);
    seg[node][0]=seg[node<<1][0]+seg[node<<1|1][0];
    seg[node][1]=seg[node<<1][1]+seg[node<<1|1][1];
}
void dfs(int node){
    update(1,0,M,t[node],c[node]);
    tim[node]+=l[node];
    if(T<2*tim[node]) val[node]=-hell;
    else val[node]=query(1,0,M,T-2*tim[node]);
    int mx1=-hell,mx2=-hell;
    for(auto i:a[node]){
        tim[i]=tim[node];
        dfs(i);
        if(ans[i]>mx1) mx2=mx1,mx1=ans[i];
        else mx2=max(mx2,ans[i]);
    }
    if(node==1) mx2=mx1;
    ans[node]=max(val[node],mx2);
    update(1,0,M,t[node],-c[node]);
}
void solve(){
    cin>>n>>T;
    rep(i,1,n+1) cin>>c[i];
    rep(i,1,n+1) cin>>t[i];
    rep(i,2,n+1){
        cin>>p[i]>>l[i];
        a[p[i]].pb(i);
    }
    dfs(1);
    cout<<ans[1]<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}