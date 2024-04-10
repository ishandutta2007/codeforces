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
int dp[2][1001][90];
int distinct[1001][90];
int y[1001][90];
int ans[1001][1001];
void solve(){
    dp[0][0][0]=1;
    dp[0][0][1]=1;
    y[0][0]=1;
    rep(i,1,1001){
        rep(j,0,1001){
            rep(k,0,90){
                dp[i&1][j][k]=(dp[1-(i&1)][j][k]+1LL*k*(k and j>=i?dp[1-(i&1)][j-i][k-1]:0))%hell;
            }
        }
    }
    rep(j,0,1001){
        rep(k,0,90){
            distinct[j][k]=dp[0][j][k];
            if(j) distinct[j][k]+=distinct[j-1][k];
            if(distinct[j][k]>=hell) distinct[j][k]-=hell;
            rep(l,1,j+1){
                y[j][k]=((k?y[j-l][k-1]:0)+y[j][k]);
                if(y[j][k]>=hell) y[j][k]-=hell;
            }
        }
    }
    rep(i,1,1001){
        rep(j,1,90){
            rep(r,j,i+1){
                ans[i][j]=(ans[i][j]+1LL*y[r][j]*distinct[i-r][j])%hell;
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    int t=1;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        cout<<ans[n][k]<<endl;
    }
    return 0;
}