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
mii mp;
int n,m,col[300005];
vi a[300005];
void dfs(int node,int par){
    for(auto i:a[node]){
        if(i==par) continue;
        int expcol;
        if(mp.count({par,i})) expcol=6-col[par]-col[node];
        else expcol=col[par];
        if(col[i]){
            if(col[i]!=expcol){
                cout<<-1<<endl;
                exit(0);
            }
        }
        else{
            col[i]=expcol;
            dfs(i,node);
        }
    }
}
void solve(){
    cin>>n>>m;
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
        mp[{x,y}]=1;
        mp[{y,x}]=1;
    }
    if(sz(a[1])==0){
        cout<<-1<<endl;
        return;
    }
    col[1]=1;
    col[a[1][0]]=2;
    dfs(a[1][0],1);
    rep(i,1,n+1){
        if(col[i]==0){
            cout<<-1<<endl;
            return;
        }
    }
    for(auto i:mp){
        if(col[i.x.x]==col[i.x.y]){
            cout<<-1<<endl;
            return;
        }
    }
    int f[4]={0,0,0,0};
    rep(i,1,n+1){
        f[col[i]]++;
    }
    ll tobe=1LL*f[1]*f[2]+1LL*f[2]*f[3]+1LL*f[1]*f[3];
    if(f[1]==0 or f[2]==0 or f[3]==0 or tobe!=m){
        cout<<-1<<endl;
        return;
    }
    rep(i,1,n+1) cout<<col[i]<<" ";
    cout<<endl;
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