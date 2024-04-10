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
int n,f[100005],vis[100005];
vi v[100005];
void solve(){
    cin>>n;
    rep(i,1,n+1) f[i]=vis[i]=0;
    rep(i,1,n+1){
        v[i].clear();
        int m;
        cin>>m;
        rep(j,0,m){
            int x;
            cin>>x;
            v[i].pb(x);
        }
    }
    rep(i,1,n+1){
        rep(j,0,sz(v[i])){
            if(vis[v[i][j]]==0){
                vis[v[i][j]]=1;
                f[i]=1;
                break;
            }
        }
    }
    int girl=0,kingdom=0;
    rep(i,1,n+1) if(f[i]==0) girl=i;
    rep(i,1,n+1) if(vis[i]==0) kingdom=i;
    if(girl and kingdom) cout<<"IMPROVE\n"<<girl<<" "<<kingdom<<endl;
    else cout<<"OPTIMAL"<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}