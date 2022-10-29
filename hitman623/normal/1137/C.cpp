#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

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
int n,m,d,ans[100005][52];
ll val[100005];
vi a[100005],stk,b[100005],stk2;
bool vis[100005];
bool visited[100005][52];
void dfs(int node){
    vis[node]=1;
    for(auto i:a[node]){
        if(!vis[i]){
            dfs(i);
        }
    }
    stk.pb(node);
}
int id[100005],cmp;
void dfs2(int node){
    id[node]=cmp;
    vis[node]=1;
    for(auto i:b[node]){
        if(!vis[i]){
            dfs2(i);
        }
    }
    stk2.pb(node);
}
vii v;
bool w[100005];
void dfs3(int node,int p){
    w[node]=0;
    v.pb({node,p});
    visited[node][p]=1;
    int np=(p+1)%d;
    for(auto i:a[node]){
        if(visited[i][np]==0 && id[i]==id[node]){
            dfs3(i,np);
        }
    }
}
void solve(){
    cin>>n>>m>>d;
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        a[x].pb(y);
        b[y].pb(x);
    }
    rep(i,1,n+1){
        string s;
        cin>>s;
        rep(j,0,d){
            if(s[j]=='1'){
                val[i]|=(1LL<<j);
            }
        }
    }
    dfs(1);
    reverse(all(stk));
    memset(vis,0,sizeof vis);
    for(auto i:stk){
        if(!vis[i]){
            cmp++;
            dfs2(i);
        }
    }    
    reverse(all(stk2));
    for(auto i:stk2){
        rep(j,0,d){
            if(visited[i][j]==0){
                v.clear();
                dfs3(i,j);
                int cnt=0;
                for(auto k:v){
                    if(((val[k.x]>>k.y)&1LL) && w[k.x]==0){
                        cnt++;
                        w[k.x]=1;
                    }
                }
                int res=cnt;
                for(auto k:v){
                    for(auto l:a[k.x]){
                        res=max(res,cnt+ans[l][(k.y+1)%d]);
                    }
                }
                for(auto k:v) ans[k.x][k.y]=res;
            }
        }
    }
    cout<<ans[1][0]<<endl;
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