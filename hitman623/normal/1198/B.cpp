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
int n,q,a[200005];
const int N=200005;
int seg[4*N],lazy[4*N];
void build(int node,int start,int end){
    if(start==end){
        seg[node]=a[start];
        return;
    }
    int mid=(start+end)>>1;
    build(node<<1,start,mid);
    build(node<<1|1,mid+1,end);
    seg[node]=max(seg[node<<1],seg[node<<1|1]);
}
void upd1(int node,int start,int end,int pos,int val){
    if(lazy[node]!=0){
        seg[node]=max(seg[node],lazy[node]);
        if(start!=end){
            lazy[node<<1]=max(lazy[node<<1],lazy[node]);
            lazy[node<<1|1]=max(lazy[node<<1|1],lazy[node]);
        }
        lazy[node]=0;
    }
    if(start==end){
        seg[node]=val;
        return;
    }
    int mid=(start+end)>>1;
    if(pos<=mid) upd1(node<<1,start,mid,pos,val);
    else upd1(node<<1|1,mid+1,end,pos,val);
    seg[node]=max(seg[node<<1],seg[node<<1|1]);
}
int query(int node,int start,int end,int l,int r){
    if(start>end || start>r || end<l) return 0;
    if(lazy[node]!=0){
        seg[node]=max(seg[node],lazy[node]);
        if(start!=end){
            lazy[node<<1]=max(lazy[node<<1],lazy[node]);
            lazy[node<<1|1]=max(lazy[node<<1|1],lazy[node]);
        }
        lazy[node]=0;
    }
    if(start>=l && end<=r) return seg[node];
    int mid=(start+end)>>1;
    int q1=query(node<<1,start,mid,l,r);
    int q2=query(node<<1|1,mid+1,end,l,r);
    return max(q1,q2);
}
void solve(){
    cin>>n;
    rep(i,1,n+1) cin>>a[i];
    build(1,1,n);
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int p,x;
            cin>>p>>x;
            upd1(1,1,n,p,x);
        }
        else{
            int x;
            cin>>x;
            lazy[1]=max(lazy[1],x);
        }
    }
    rep(i,1,n+1) cout<<query(1,1,n,i,i)<<" ";
    cout<<endl;
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