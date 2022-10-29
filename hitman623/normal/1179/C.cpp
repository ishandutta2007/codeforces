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
#define N           1000000
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,q,a[300005],b[300005],val[N+2];
int seg[4*N+2],lazy[4*N+2];
void build(int node,int start,int end){
    if(start==end){
        seg[node]=val[start];
        return;
    }
    int mid=(start+end)>>1;
    build(node<<1,start,mid);
    build(node<<1|1,mid+1,end);
    seg[node]=max(seg[node<<1],seg[node<<1|1]);
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
        if(start!=end){
            lazy[node<<1]+=val;
            lazy[node<<1|1]+=val;
        }
        return;
    }
    int mid=(start+end)>>1;
    update(node<<1,start,mid,l,r,val);
    update(node<<1|1,mid+1,end,l,r,val);
    seg[node]=max(seg[node<<1],seg[node<<1|1]);
}
void lazify(int node,int start,int end){
    if(lazy[node]!=0){
        seg[node]+=lazy[node];
        if(start!=end){
            lazy[node<<1]+=lazy[node];
            lazy[node<<1|1]+=lazy[node];
        }
        lazy[node]=0;
    }
}
int query(int node,int l,int r){
    lazify(node,l,r);
    if(l==r){
        if(seg[node]>0) return l;
        else return -1;
    }
    int mid=(l+r)/2;
    lazify(node<<1|1,mid+1,r);
    if(seg[node<<1|1]>0) return query(node<<1|1,mid+1,r);
    else return query(node<<1,l,mid);
}
void solve(){
    cin>>n>>m;
    rep(i,1,n+1){
        int x;
        cin>>x;
        val[x]++;
        a[i]=x;
    }
    rep(i,1,m+1){
        int x;
        cin>>x;
        val[x]--;
        b[i]=x;
    }
    for(int i=N;i>=1;i--){
        val[i]+=val[i+1];
    }
    build(1,1,N);
    cin>>q;
    while(q--){
        int type,id,x;
        cin>>type>>id>>x;
        if(type==1){
            update(1,1,N,1,a[id],-1);
            a[id]=x;
            update(1,1,N,1,a[id],+1);
        }
        else{
            update(1,1,N,1,b[id],+1);
            b[id]=x;
            update(1,1,N,1,b[id],-1);            
        }
        cout<<query(1,1,N)<<endl;
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