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
int n,m,q,dp[5004][5001],f[5004],s[5004],w[20];
vii v[10004];
void solve(){
    cin>>n>>m>>q;
    rep(i,0,n){
        cin>>w[i];
    }
    rep(i,0,m){
        string h;
        cin>>h;
        int cur=0;
        rep(j,0,n){
            if(h[j]=='1') cur+=(1<<j);
        }
        f[cur]++;
    }
    rep(i,0,1<<n){
        rep(j,0,n){
            if((i>>j)&1) s[i]+=w[j];
        }
    }
    rep(i,0,1<<n){
        rep(j,0,1<<n){
            dp[i][s[(1<<n)-1-(i^j)]]+=f[j];
        }
        rep(j,1,201){
            dp[i][j]+=dp[i][j-1];
        }
    }
    while(q--){
        string g;
        int k;
        cin>>g>>k;
        int cur=0;
        rep(i,0,n){
            if(g[i]=='1') cur+=1<<i;
        }
        cout<<dp[cur][k]<<endl;
    }
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