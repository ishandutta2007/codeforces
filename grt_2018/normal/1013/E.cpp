#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pi;
typedef vector<int> vi;
#define ST first
#define ND second
#define PB push_back

const int MAXN = 5010;
const int INF = 1000*1000*1000;
LL dp[MAXN][MAXN];
LL minpref[MAXN][MAXN];
int n,a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n;i++) cin>>a[i];
    for(int k=1; k<=(n+1)/2; k++) {
        for(int i=0; i<=n;i++) dp[i][k]=INF;
    }
    minpref[0][1] = INF;
    for(int i=1; i<=n;i++) {
        dp[i][1] = max(0,a[i-1]-a[i]+1);
        minpref[i][1] = min(minpref[i-1][1],dp[i][1]+max(0,a[i+1]-a[i]+1));
    }
    cout<<minpref[n][1]<<" ";
    for(int k=2; k<=(n+1)/2; k++) {
        minpref[0][k] = INF;
        for(int i=1; i<=n;i++) {
            if(i-3>=0) dp[i][k]=minpref[i-3][k-1]+max(0,a[i-1]-a[i]+1);
            if(i-2>=0) dp[i][k] = min(dp[i][k],dp[i-2][k-1]+max(0,a[i-1]-min(a[i],a[i-2])+1));
            minpref[i][k] = min(minpref[i-1][k],dp[i][k]+max(0,a[i+1]-a[i]+1));
            //cout<<"dp["<<i<<"]["<<k<<"] : "<<dp[i][k]<<"\n";
        }
        //LL ans = INF;
        //for(int i=1; i<=n;i++) ans=min(ans,dp[i][k]+);
        cout<<minpref[n][k]<<" ";
    }
}