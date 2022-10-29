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
int n,m,s,e,ans,a[100005],b[100005];
vi v[100005];
int bit[100005];
void update(int x,int y=1){
    for(;x<=m;x+=x&(-x)) bit[x]=max(bit[x],y);
}
int query(int x){
    int res=0;
    for(;x>0;x-=x&(-x)) res=max(res,bit[x]);
    return res;
}
void solve(){
    cin>>n>>m>>s>>e;
    rep(i,1,n+1) cin>>a[i];
    rep(i,1,m+1){
        cin>>b[i];
        v[b[i]].pb(i);
    }
    rep(i,1,n+1){
        int endat=sz(v[a[i]]);
        rep(j,0,sz(v[a[i]])){
           int d=query(v[a[i]][j]-1)+1;
            if(d*e+i+v[a[i]][j]<=s) ans=max(ans,d);
            else{
                endat=j;
                break;
            }
        }
        for(int j=endat-1;j>=0;j--){
           int d=query(v[a[i]][j]-1)+1;
           update(v[a[i]][j],d);
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