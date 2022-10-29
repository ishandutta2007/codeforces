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
int n,dp[2002][2002];
string s,w;
int g[2002][26];
int h[2002][26];
int can[2002][2002];
void solve(){
    cin>>n;
    cin>>s>>w;
    rep(i,0,n) memset(g[i],0,sizeof g[i]);
    rep(i,0,n) memset(h[i],0,sizeof h[i]);
    rep(i,0,n){
        if(i) rep(j,0,26) g[i][j]=g[i-1][j];
        g[i][s[i]-'a']++;
    }
    rep(i,0,n){
        if(i) rep(j,0,26) h[i][j]=h[i-1][j];
        h[i][w[i]-'a']++;
    }
    rep(i,0,26){
        if(g[n-1][i]!=h[n-1][i]){
            cout<<-1<<endl;
            return;
        }
    }
    rep(i,0,n+1) rep(j,0,n+1) dp[i][j]=0;
    rep(i,0,n){
        rep(j,0,n){
            can[i][j]=1;
            rep(k,0,26){
                if(g[i][k]>h[j][k]) can[i][j]=0;
            }
        }
    }
    rep(i,1,n+1){
        rep(j,1,n+1){
            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            if(can[i-1][j-1] and s[i-1]==w[j-1]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
        }
    }
    cout<<n-dp[n][n]<<endl;
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