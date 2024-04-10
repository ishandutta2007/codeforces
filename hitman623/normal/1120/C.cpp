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
int n,a,b,node=1;
string s;
int dp[5005];
int match[5005][5005];
int pre[5005];
void solve(){
    cin>>n>>a>>b;
    cin>>s;
    rep(i,0,n){
        rep(j,0,n){
            if(s[i]==s[j]) match[i][j]=((i and j)?match[i-1][j-1]:0)+1;
        }
    }
    rep(i,0,n){
        dp[i]=(i?dp[i-1]:0)+a;
        rep(j,0,i){
            pre[j]=match[j][i];
            if(j) pre[j]=max(pre[j],pre[j-1]);
        }
        rep(j,1,i+1){
            if(pre[j-1]>=i-j+1){
                dp[i]=min(dp[i],dp[j-1]+b);
            }
        }
    }
    cout<<dp[n-1]<<endl;
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