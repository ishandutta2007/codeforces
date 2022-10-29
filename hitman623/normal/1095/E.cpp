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
int n,ans;
string s;
const int N=1000005;
int a[N],seg[4*N],lazy[4*N];
void build(int node,int start,int end){
    if(start==end){
        seg[node]=a[start];
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
void solve(){
    cin>>n>>s;
    rep(i,0,n){
        if(i) a[i]=a[i-1];
        if(s[i]=='(') a[i]++;
        else a[i]--;
    }
    build(1,0,n-1);
    rep(i,0,n){
        if(s[i]=='('){
            update(1,0,n-1,i,n-1,-2);
            if(query(1,0,n-1,0,n-1)>=0 and query(1,0,n-1,n-1,n-1)==0){
                ans++;
            }
            update(1,0,n-1,i,n-1,2);
        }
        else{
            update(1,0,n-1,i,n-1,2);
            if(query(1,0,n-1,0,n-1)>=0 and query(1,0,n-1,n-1,n-1)==0){
                ans++;
            }
            update(1,0,n-1,i,n-1,-2);
        }
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