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
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n;
int T,s;
const int N=200005;
int a[N],seg[N<<2];
void build(int node,int start,int end){
    if(start==end){
        seg[node]=a[start];
        return;
    }
    int mid=(start+end)>>1;
    build(node<<1,start,mid);
    build(node<<1|1,mid+1,end);
    seg[node]=seg[node<<1]+seg[node<<1|1];
}
int query(int node,int start,int end,int t){
    if(start==end){
        return start;
    }
    int mid=(start+end)>>1;
    if(seg[node<<1]<=t){
        return query(node<<1|1,mid+1,end,t-seg[node<<1]);
    }
    else{
        return query(node<<1,start,mid,t);
    }
}
void update(int node,int start,int end,int x,int val){
    if(start==end){
        seg[node]+=val;
        return;
    }
    int mid=(start+end)>>1;
    if(start<=x && x<=mid) update(node<<1,start,mid,x,val);
    else update(node<<1|1,mid+1,end,x,val);
    seg[node]=seg[node<<1]+seg[node<<1|1];
}
void solve(){
    cin>>n>>T;
    rep(i,1,n+1){
        cin>>a[i];
        s+=a[i];
    }
    build(1,1,n);
    int ans=T/s*n,rem=n;
    T%=s;
    while(1){
        if(s==0 || T==0) break;
        if(s<=T){
            ans+=T/s*rem;
            T%=s;
        }
        int ind=query(1,1,n,T);
        update(1,1,n,ind,-a[ind]);
        s-=a[ind];
        rem--;
        a[ind]=0;
    }
    cout<<ans<<endl;
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