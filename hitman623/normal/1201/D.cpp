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
#define hell        1000000000000007LL
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,k,q,mx;
vi v[200005],cols;
pii neigh[200005];
map<pii,ll> dp;
ll go(int x,int y){
    if(dp.count({x,y})) return dp[{x,y}];
    ll &ans=dp[{x,y}];
    ans=hell;
    if(x==mx){
        int l=v[x][0],r=v[x].back();
        if(l<=y and y<=r) return ans=min(y-l+r-l,r-y+r-l);
        else if(r<y) return ans=y-l;
        else return ans=r-y;
    }
    if(sz(v[x])==0) return ans=go(x+1,y)+1;
    int l=v[x][0],r=v[x].back();
    if(l<=y and y<=r){
        if(neigh[l].x!=-1) ans=min(ans,r-y+r-neigh[l].x+1+go(x+1,neigh[l].x));
        if(neigh[l].y!=-1) ans=min(ans,r-y+r-l+neigh[l].y-l+1+go(x+1,neigh[l].y));
        if(neigh[r].x!=-1) ans=min(ans,y-l+r-l+r-neigh[r].x+1+go(x+1,neigh[r].x));
        if(neigh[r].y!=-1) ans=min(ans,y-l+neigh[r].y-l+1+go(x+1,neigh[r].y));
    }
    else{
        if(r<y){
            if(neigh[l].x!=-1) ans=min(ans,y-neigh[l].x+1+go(x+1,neigh[l].x));
            if(neigh[l].y!=-1) ans=min(ans,y-l+neigh[l].y-l+1+go(x+1,neigh[l].y));
        }
        else{
            if(neigh[r].x!=-1) ans=min(ans,r-y+r-neigh[r].x+1+go(x+1,neigh[r].x));
            if(neigh[r].y!=-1) ans=min(ans,neigh[r].y-y+1+go(x+1,neigh[r].y));        
        }
    }
    return ans;
}
void solve(){
    cin>>n>>m>>k>>q;
    rep(i,0,k){
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        mx=max(mx,x);
    }
    rep(i,0,q){
        int x;
        cin>>x;
        cols.pb(x);
    }
    sort(all(cols));
    rep(i,1,m+1){
        int pos=upper_bound(all(cols),i)-cols.begin();
        if(pos!=sz(cols)) neigh[i].y=cols[pos];
        else neigh[i].y=-1;
        if(pos==sz(cols) or cols[pos]!=i) pos--;
        if(pos!=-1) neigh[i].x=cols[pos];
        else neigh[i].x=-1;
    }
    rep(i,1,n+1) sort(all(v[i]));
    if(sz(v[1])) cout<<go(1,1)<<endl;
    else cout<<go(1,cols[0])+cols[0]-1<<endl;
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