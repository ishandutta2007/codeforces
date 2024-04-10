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
#define hell        1000000007
#define MN          -1100000000000000000LL
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
const int N=100005;
int n,a[N],k[N],prek[N],presumk[N],q;
int val[N];
pii seg[4*N];
int lazy[4*N];
void build(int node,int start,int end){
    if(start==end){
        seg[node]={val[start],val[start]};
        return;
    }
    int mid=(start+end)>>1;
    build(node<<1,start,mid);
    build(node<<1|1,mid+1,end);
    seg[node].x=max(seg[node<<1].x,seg[node<<1|1].x);
    seg[node].y=seg[node<<1].y+seg[node<<1|1].y;
}
void update(int node,int start,int end,int l,int r,int val){
    if(lazy[node]!=MN){
        seg[node].x=lazy[node];
        seg[node].y=(end-start+1)*lazy[node];
        if(start!=end){
            lazy[node<<1]=lazy[node];
            lazy[node<<1|1]=lazy[node];
        }
        lazy[node]=MN;
    }
    if(start>end || start>r || end<l) return;
    if(l<=start && end<=r){
        seg[node].x=val;
        seg[node].y=(end-start+1)*val;
        if(start!=end){
            lazy[node<<1]=val;
            lazy[node<<1|1]=val;
        }
        return;
    }
    int mid=(start+end)>>1;
    update(node<<1,start,mid,l,r,val);
    update(node<<1|1,mid+1,end,l,r,val);
    seg[node].x=max(seg[node<<1].x,seg[node<<1|1].x);
    seg[node].y=seg[node<<1].y+seg[node<<1|1].y;
}
pii query(int node,int start,int end,int l,int r){
    if(start>end || start>r || end<l) return {MN,0};
    if(lazy[node]!=MN){
        seg[node].x=lazy[node];
        seg[node].y=(end-start+1)*lazy[node];
        if(start!=end){
            lazy[node<<1]=lazy[node];
            lazy[node<<1|1]=lazy[node];
        }
        lazy[node]=MN;
    }
    if(start>=l && end<=r) return seg[node];
    int mid=(start+end)>>1;
    pii q1=query(node<<1,start,mid,l,r);
    pii q2=query(node<<1|1,mid+1,end,l,r);
    return {max(q1.x,q2.x),q1.y+q2.y};
}
void solve(){
    cin>>n;
    rep(i,0,4*n+1) lazy[i]=MN;
    rep(i,1,n+1) cin>>a[i];
    rep(i,1,n) cin>>k[i];
    rep(i,1,n+1){
        val[i]=a[i]-prek[i-1];
        prek[i]=prek[i-1]+k[i];
        presumk[i]=presumk[i-1]+prek[i];
    }
    build(1,1,n);
    cin>>q;
    while(q--){
        char ch;
        cin>>ch;
        if(ch=='+'){
            int pos,x;
            cin>>pos>>x;
            int w=query(1,1,n,pos,pos).y+x;
            int lo=pos,hi=n+1;
            while(hi-lo>1){
                int mid=(lo+hi)/2;
                if(query(1,1,n,pos,mid).x>=w) hi=mid;
                else lo=mid;
            }
            update(1,1,n,pos,lo,w);
        }
        else{
            int l,r;
            cin>>l>>r;
            pii w=query(1,1,n,l,r);
            cout<<w.y+(presumk[r-1]-(l>=2?presumk[l-2]:0))<<endl;
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