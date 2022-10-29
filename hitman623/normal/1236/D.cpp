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
int n,m,k,cnt,rs,re,cs,ce;
vi r[100005],c[100005];
mii vis;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
void go(int x,int y,int p){
    if(vis.count({x,y}) and vis[{x,y}]==1) return;
    vis[{x,y}]++;
    int fx=x,fy=y;
    if(p==0){
        cs=max(cs,x+1);
        int d=lower_bound(all(r[x]),y)-r[x].begin();
        if(d==sz(r[x])) fx=x,fy=re;
        else fx=x,fy=min(re,r[x][d]-1); 
    }
    if(p==1){
        re=min(re,y-1);
        int d=lower_bound(all(c[y]),x)-c[y].begin();
        if(d==sz(c[y])) fx=ce,fy=y;
        else fx=min(ce,c[y][d]-1),fy=y; 
    }
    if(p==2){
        ce=min(ce,x-1);
        int d=lower_bound(all(r[x]),y)-r[x].begin()-1;
        if(d==-1) fx=x,fy=rs;
        else fx=x,fy=max(rs,r[x][d]+1);         
    }
    if(p==3){
        rs=max(rs,y+1);
        int d=lower_bound(all(c[y]),x)-c[y].begin()-1;
        if(d==-1) fx=cs,fy=y;
        else fx=max(cs,c[y][d]+1),fy=y; 
    }
    cnt+=abs(fx-x)+abs(fy-y);
    go(fx,fy,(p+1)%4);
}
void solve(){
    cin>>n>>m>>k;
    rep(i,0,k){
        int x,y;
        cin>>x>>y;
        r[x].pb(y);
        c[y].pb(x);
        vis[{x,y}]=1;
    }
    rep(i,1,n+1) sort(all(r[i]));
    rep(i,1,m+1) sort(all(c[i]));
    rs=1,re=m;
    cs=1,ce=n;
    cnt=1;
    vis[{1,1}]=-1;
    go(1,1,0);
    if(cnt+k==n*m) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
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