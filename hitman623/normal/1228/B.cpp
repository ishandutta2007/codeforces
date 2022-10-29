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
int vis[1003][1003],r[1003],c[1003];
int n,m;
void solve(){
    cin>>n>>m;
    rep(i,0,n){
        cin>>r[i];
        rep(j,0,r[i]){
            vis[i][j]=1;
        }
    }
    rep(i,0,m){
        cin>>c[i];
        rep(j,0,c[i]){
            vis[j][i]=1;
        }
    }
    rep(i,0,n){
        rep(j,0,m){
            if(vis[i][j] and (r[i]==j or c[j]==i)){
                cout<<0<<endl;
                return;
            }
        }
    }
    rep(i,0,n) vis[i][r[i]]=1;
    rep(i,0,m) vis[c[i]][i]=1;
    int cnt=0;
    rep(i,0,n){
        rep(j,0,m){
            cnt+=vis[i][j];
        }
    }
    int ans=1;
    rep(i,0,n*m-cnt) ans=(ans*2LL)%hell;
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