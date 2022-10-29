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
#define hell        1000000009
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,q,a[300005],fib[300005],fibsum[300005];
const int N=300005;
int seg[2][4*N],lazy[2][4*N];
int get(int l,int r){
    return (fibsum[r]-fibsum[l-1]+hell)%hell;
}
void update(int node,int start,int end,int l,int r,int f,int val){
    if(lazy[f][node]!=0){
        seg[f][node]=(seg[f][node]+get(start+f,end+f)*lazy[f][node])%hell;
        if(start!=end){
            lazy[f][node<<1]=(lazy[f][node<<1]+lazy[f][node])%hell;
            lazy[f][node<<1|1]=(lazy[f][node<<1|1]+lazy[f][node])%hell;
        }
        lazy[f][node]=0;
    }
    if(start>end || start>r || end<l) return;
    if(l<=start && end<=r){
        seg[f][node]=(seg[f][node]+get(start+f,end+f)*val)%hell;
        if(start!=end){
            lazy[f][node<<1]=(lazy[f][node<<1]+val)%hell;
            lazy[f][node<<1|1]=(lazy[f][node<<1|1]+val)%hell;
        }
        return;
    }
    int mid=(start+end)>>1;
    update(node<<1,start,mid,l,r,f,val);
    update(node<<1|1,mid+1,end,l,r,f,val);
    seg[f][node]=(seg[f][node<<1]+seg[f][node<<1|1])%hell;
}
int query(int node,int start,int end,int f,int l,int r){
    if(start>end || start>r || end<l) return 0;
    if(lazy[f][node]!=0){
        seg[f][node]=(seg[f][node]+get(start+f,end+f)*lazy[f][node])%hell;
        if(start!=end){
            lazy[f][node<<1]=(lazy[f][node<<1]+lazy[f][node])%hell;
            lazy[f][node<<1|1]=(lazy[f][node<<1|1]+lazy[f][node])%hell;
        }
        lazy[f][node]=0;
    }
    if(start>=l && end<=r) return seg[f][node];
    int mid=(start+end)>>1;
    int q1=query(node<<1,start,mid,f,l,r);
    int q2=query(node<<1|1,mid+1,end,f,l,r);
    return (q1+q2)%hell;
}
void solve(){
    cin>>n>>q;
    rep(i,1,n+1){
        cin>>a[i];
        a[i]=(a[i]+a[i-1])%hell;
    }
    fib[1]=fib[2]=1;
    rep(i,3,n+2) fib[i]=(fib[i-1]+fib[i-2])%hell;
    rep(i,1,n+2) fibsum[i]=(fibsum[i-1]+fib[i])%hell;
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int l,r;
            cin>>l>>r;
            update(1,1,n,l,r,0,(l%2)?fib[l]:hell-fib[l]);
            update(1,1,n,l,r,1,(l%2)?hell-fib[l-1]:fib[l-1]);
        }
        else{
            int l,r;
            cin>>l>>r;
            cout<<(query(1,1,n,0,l,r)+query(1,1,n,1,l,r)+a[r]-a[l-1]+hell)%hell<<endl;
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