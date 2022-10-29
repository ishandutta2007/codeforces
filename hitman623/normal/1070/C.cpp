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
#define MAX_PRICE   1000000
#define rep(i,a,b)  for(int i=a;i<b;i++)

using namespace std;
int n,k,m;
vii open[1000006],close[1000006];
const int N=1000005;
int seg[N<<2][2];
int query(int node,int start,int end,int K){
    if(start==end){
        if(seg[node][0]>K) return start*K;
        else return seg[node][1];
    }
    int mid=(start+end)>>1;
    if(seg[node<<1][0]>=K) return query(node<<1,start,mid,K);
    else return seg[node<<1][1]+query(node<<1|1,mid+1,end,K-seg[node<<1][0]);
}
void update(int node,int start,int end,int x,int val){
    if(start==end){
        seg[node][0]+=val;
        seg[node][1]+=start*val;
        return;
    }
    int mid=(start+end)>>1;
    if(start<=x && x<=mid) update(node<<1,start,mid,x,val);
    else update(node<<1|1,mid+1,end,x,val);
    seg[node][0]=seg[node<<1][0]+seg[node<<1|1][0];
    seg[node][1]=seg[node<<1][1]+seg[node<<1|1][1];
}
void solve(){
    cin>>n>>k>>m;
    rep(i,0,m){
        int l,r,c,p;
        cin>>l>>r>>c>>p;
        open[l].pb({p,c});
        close[r].pb({p,c});
    }
    int ans=0;
    rep(i,1,n+1){
        for(auto j:open[i]){
            update(1,0,MAX_PRICE,j.x,j.y);
        }
        ans+=query(1,0,MAX_PRICE,k);
        for(auto j:close[i]){
            update(1,0,MAX_PRICE,j.x,-j.y);
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