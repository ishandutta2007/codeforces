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
int n,val[100005],depth[100005],par[100005];
vi a[100005];
void dfs(int node){
    for(auto i:a[node]){
        depth[i]=depth[node]+1;
        par[i]=node;
        dfs(i);
    }
}
void solve(){
    cin>>n;
    rep(i,2,n+1){
        int x;
        cin>>x;
        a[x].pb(i);
    }
    rep(i,1,n+1) cin>>val[i];
    depth[1]=1;
    par[1]=1;
    dfs(1);
    rep(i,1,n+1){
        if(val[i]==-1 or val[par[par[i]]]<=val[i]);
        else{
            cout<<-1<<endl;
            return;
        }
        if(val[i]==-1){
            int cur=hell;
            for(auto j:a[i]){
                cur=min(cur,val[j]);
            }
            if(cur<hell) val[i]=cur;
            else val[i]=val[par[i]];
        }
    }
    int ans=val[1];
    rep(i,2,n+1){
        if(val[i]<val[par[i]]){
            cout<<-1<<endl;
            return;
        }
        ans+=val[i]-val[par[i]];
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