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
int n,dp[200005][4];
string s,w="RGB",res;
void solve(){
    memset(dp,1,sizeof dp);
    cin>>n>>s;
    rep(i,0,n){
        rep(j,0,3){
            if(i==0) dp[i][j]=s[i]!=w[j];
            else{
                rep(k,0,3){
                    if(k!=j){
                        dp[i][j]=min(dp[i][j],dp[i-1][k]+(s[i]!=w[j]));
                    }
                }                
            }
        }
    }
    int ans=min({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
    cout<<ans<<endl;
    int cur=n-1;
    int pos=0;
    rep(i,0,3){
        if(dp[cur][i]<dp[cur][pos]) pos=i;
    }
    while(1){
        res+=w[pos];
        if(cur==0) break;
        rep(i,0,3){
            if(pos!=i and dp[cur-1][i]+(s[cur]!=w[pos])==dp[cur][pos]){
                cur--;
                pos=i;
                break;
            }
        }
    }
    reverse(all(res));
    cout<<res<<endl;
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