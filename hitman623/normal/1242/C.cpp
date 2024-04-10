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
int n,w[16],s[16],dp[1<<15];
int a[16][5005],vis[16][5005];
int valid[1<<15];
vii ans[1<<15];
map<int,pii> pos;
vii res;
int rem[16],add[16],mask,S;
pii started;
bool go(int x,int y){
    if(vis[x][y]){
        if(x==started.x and y==started.y){
            // cout<<"v\n";
            return 1;
        }
        // cout<<"w\n";
        return 0;
    }
    if(mask&(1<<x)){
        // cout<<"q\n";
        return 0;
    }
    // cout<<x<<" "<<y<<endl;
    res.pb({x,y});
    vis[x][y]=1;
    mask|=(1<<x);
    int d=S-s[x]+a[x][y];
    if(pos.count(d)) return go(pos[d].x,pos[d].y);
    else return 0;
}
void dfs(int mak){
    if(mak==0) return;
    for(int j=mak;;j=(j-1)&mak){
        if(j==0) break;
        if(dp[mak^j] and valid[j]){
            dfs(mak^j);
            rep(i,0,sz(ans[j])){
                rem[ans[j][i].x]=ans[j][i].y;
                add[ans[j][(i+1)%sz(ans[j])].x]=ans[j][i].x;
            }
            return;
        }
    }
}
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>w[i];
        rep(j,0,w[i]){
            cin>>a[i][j];
            pos[a[i][j]]={i,j};
            s[i]+=a[i][j];
            S+=a[i][j];
        }
    }
    if(S%n){
        cout<<"No"<<endl;
        return;
    }
    S/=n;
    rep(i,0,n){
        rep(j,0,w[i]){
            if(vis[i][j]) continue;
            mask=0;
            res.clear();
            started={i,j};
            if(go(i,j)){
                // cout<<i<<" : "<<j<<endl;
                valid[mask]=1;
                dp[mask]=1;
                ans[mask]=res;
            }
            else{
                for(auto k:res){
                    vis[k.x][k.y]=0;
                }
            }
            // cout<<endl;
        }
    }
    dp[0]=1;
    rep(i,0,1<<n){
        for(int j=i;;j=(j-1)&i){
            if(j==0) break;
            dp[i]=dp[i]|(dp[i^j]&dp[j]);
        }
    }
    if(dp[(1<<n)-1]){
        cout<<"Yes"<<endl;
        dfs((1<<n)-1);
        rep(i,0,n){
            cout<<a[i][rem[i]]<<" "<<add[i]+1<<endl;
        }
    }
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