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
int m,n,vis[1<<17],par[1<<17],deg[1<<17],sub[1<<17];
vi a[1<<17];
int f=0;
vi bad;
void dfs(int node,int pa){
    sub[node]=1;
    par[node]=pa;
    deg[node]=0;
    for(auto i:a[node]){
        if(i!=pa){
            deg[node]++;
            dfs(i,node);
            sub[node]+=sub[i];
        }
    }
    if(f==0 and sub[node]&(sub[node]+1)){
        sub[node]++;
        bad.pb(node);
        f=1;
    }
}
void solve(){
    cin>>m;
    n=(1<<m)-2;
    rep(i,0,n-1){
        int x,y;
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
        deg[x]++;
        deg[y]++;
    }
    queue<int> q;
    rep(i,1,n+1){
        if(deg[i]==1){
            q.push(i);
        }
    }
    while(!q.empty()){
        int d=q.front();
        q.pop();
        vis[d]=1;
        for(auto i:a[d]){
            if(vis[i]==0){
                par[d]=i;
                break;
            }
        }
        for(auto i:a[d]){
            deg[i]--;
            if(vis[i]==0 and deg[i]==1){
                q.push(i);
            }
        }
    }
    memset(deg,0,sizeof deg);
    int root=-1;
    rep(i,1,n+1){
        if(par[i]==0){
            root=i;
        }
    }
    vi candids;
    candids.pb(root);
    for(auto i:a[root]){
        candids.pb(i);
    }
    if(sz(candids)>5){
        cout<<0<<endl;
        return;
    }
    vi ans;
    for(auto rot:candids){
        bad.clear();
        f=0;
        int yes=1;
        dfs(rot,rot);
        par[rot]=0;
        if(sz(bad)!=1 or (deg[bad[0]]!=3 && deg[bad[0]]!=1)){
            yes=0;
        }
        rep(i,1,n+1){
            if(par[i] and par[i]!=bad[0] and 2*sub[i]+1!=sub[par[i]]){
                yes=0;
                break;
            }
            if(i==bad[0]) continue;
            if(deg[i]!=2 and deg[i]!=0){
                yes=0;
                break;
            }
        }
        if(yes) ans.pb(bad[0]);
    }
    sort(all(ans));
    ans.resize(unique(all(ans))-ans.begin());
    cout<<sz(ans)<<endl;
    for(auto i:ans) cout<<i<<" ";
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