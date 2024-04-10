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
int n,m,vis[5005],h[5005],f[5],ans[5005];
vi a[5005];
vi v[5005][2];
int cur=0;
void dfs(int node,int d){
    h[node]=d;
    vis[node]=1;
    v[cur][d%2].pb(node);
    for(auto i:a[node]){
        if(vis[i]==1){
            if((abs(h[i]-h[node])+1)%2){
                cout<<"NO"<<endl;
                exit(0);
            }
        }
        else if(vis[i]==0){
            dfs(i,d+1);
        }
    }
    vis[node]=2;
}
int dp[5005][5005];
void solve(){
    cin>>n>>m;
    rep(i,1,4) cin>>f[i];
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    rep(i,1,n+1){
        if(vis[i]==0){
            cur++;
            dfs(i,1);
        }
    }
    dp[0][0]=1;
    rep(i,1,cur+1){
        rep(j,0,f[2]+1){
            if(j>=sz(v[i][0])) dp[i][j]|=dp[i-1][j-sz(v[i][0])];
            if(j>=sz(v[i][1])) dp[i][j]|=dp[i-1][j-sz(v[i][1])];
        }
    }
    if(dp[cur][f[2]]==0){
        cout<<"NO"<<endl;
        return;
    }
    int k=f[2];
    while(cur){
        if(k>=sz(v[cur][0]) and dp[cur-1][k-sz(v[cur][0])]){
            for(auto j:v[cur][0]){
                ans[j]=2;
            }
            k-=sz(v[cur][0]);
        }
        else if(k>=sz(v[cur][1]) and dp[cur-1][k-sz(v[cur][1])]){
            for(auto j:v[cur][1]){
                ans[j]=2;
            }
            k-=sz(v[cur][1]);
        }
        else assert(false);
        cur--;
    }
    rep(i,1,n+1){
        if(ans[i]==0){
            if(f[1]) ans[i]=1,f[1]--;
            else if(f[3]) ans[i]=3,f[3]--;
            else assert(false);
        }
    }
    cout<<"YES"<<endl;
    rep(i,1,n+1) cout<<ans[i];
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