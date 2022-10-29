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
const int N=1000005;
int seg[N<<2];
int query(int node,int start,int end,int l,int r){
    if(l<=start && r>=end) return seg[node];
    if(r<start || l>end) return 0;
    int mid=(start+end)>>1;
    int ans1=query(node<<1,start,mid,l,r);
    int ans2=query(node<<1|1,mid+1,end,l,r);
    return (ans1+ans2);
}
int query2(int node,int l,int r,int k){
    if(l==r) return l;
    int mid=(l+r)/2;
    if(seg[2*node]>=k) return query2(2*node,l,mid,k);
    else return query2(2*node+1,mid+1,r,k-seg[2*node]);
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
int n,q;
void solve(){
    cin>>n>>q;
    rep(i,1,n+1){
        int x;
        cin>>x;
        update(1,1,n,x,1);
    }
    while(q--){
        int k;
        cin>>k;
        if(k>0) update(1,1,n,k,1);
        else{
            int w=query2(1,1,n,-k);
            update(1,1,n,w,-1);
        }
    }
    rep(i,1,n+1){
        if(query(1,1,n,i,i)>0){
            cout<<i<<endl;
            return;
        }
    }
    cout<<0<<endl;
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