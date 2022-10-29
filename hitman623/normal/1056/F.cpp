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
int n,ans;
vii v;
double c,t,pw[101],dp[101][101][1001];
void solve(){
    ans=0;
    v.clear();
    cin>>n;
    cin>>c>>t;
    rep(i,0,n+1){
        rep(j,0,n+1){
            rep(k,0,1001){
                dp[i][j][k]=1e30;
            }
        }
    }
    v.pb({hell,hell});
    rep(i,1,n+1){
        int a,p;
        cin>>a>>p;
        v.pb({a,p});
    }
    pw[0]=1;
    rep(i,1,n+1) pw[i]=pw[i-1]*10/9;
    sort(all(v));
    reverse(all(v));
    rep(i,0,n+1) dp[i][0][0]=0;
    rep(i,1,n+1){
        rep(j,1,i+1){
            rep(k,0,1001){
                if(k>=v[i].y){
                    dp[i][j][k]=min(dp[i-1][j][k],dp[i-1][j-1][k-v[i].y]+v[i].x*pw[j]);
                }
            }
        }
    }
    rep(m,0,n+1){
        rep(i,0,1001){
            if(dp[n][m][i]<1e20){
                double x=(sqrtl(dp[n][m][i]*c)-1)/c;
                if(x<0) x=0;
                if(x+m*10+dp[n][m][i]/(1+c*x)<=t+0.001){
                    ans=max(ans,i);
                }
            }
        }
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc=1;
    cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}