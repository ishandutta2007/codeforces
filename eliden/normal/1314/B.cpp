#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define debug(x) cerr<<#x<<": "<<x<<endl
using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    int nn = 1<<n;
    const int INF = 1e9;
    vector<vector<int>> dp(4,vector<int>(2*nn,-INF));
    vector<bool> in(2*nn);
    rep(i,0,k) {
        int x;
        cin>>x;
        in[nn+x-1] = true;
    }   
    for(int i=nn-1;i>0;--i) {
        if(2*i>=nn) {
            int count = in[2*i]+in[2*i+1];
            dp[0][i] = 0;
            if(count>0) {
                dp[1][i] = 1;
                dp[2][i] = 1;
            }
            if(count==2) {
                dp[3][i] = 1;
            }
            continue;
        }
        rep(j,0,4) rep(k,0,4) {
            int x = dp[j][2*i]+dp[k][2*i+1];
            if(x<0) continue;
            int below = ((j&1)!=0)+((k&1)!=0);
            int above = ((j&2)!=0)+((k&2)!=0);
            if(below) ++x;
            if(above) ++x;
            rep(it,0,2) {
                if(it==1) {
                    if(above>0) {
                        --above;
                        ++below;
                    }
                }
                int y = x;
                if(below) ++y;
                int jj = 0;
                if(below) jj+=1;
                if(above) jj+=2;
                dp[jj][i] =max(dp[jj][i], y);
            }
        }
    }
    int ans = 0;
    rep(i,1,4) ans=max(ans,1+dp[i][1]);
    cout<<ans<<endl;
}