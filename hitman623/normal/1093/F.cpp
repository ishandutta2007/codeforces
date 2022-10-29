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
#define hell        998244353 
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,k,len,a[100005];
int dp[100005][101];
int pre[101][100005];
int last[101][100005];
void solve(){
    cin>>n>>k>>len;
    rep(i,1,n+1){
    	cin>>a[i];
    }
    rep(i,1,k+1){
    	rep(j,1,n+1){
    		if(a[j]!=-1 and a[j]!=i) last[i][j]=j;
    		else last[i][j]=last[i][j-1];
    		last[i][j]=max(last[i][j],j-len+1);
    	}
    }
    pre[0][0]=1;
    rep(i,1,n+1){
    	pre[0][i]=pre[0][i-1];
    	rep(j,1,k+1){
    		if(a[i]!=-1 and a[i]!=j) dp[i][j]=0;
    		else{
    			dp[i][j]=(pre[0][i-1]-(last[j][i]?pre[0][last[j][i]-1]:0)+hell)%hell;
    			dp[i][j]=(dp[i][j]-pre[j][i-1]+(last[j][i]?pre[j][last[j][i]-1]:0)+hell)%hell;
    		}
    		pre[j][i]=(pre[j][i-1]+dp[i][j])%hell;
    		pre[0][i]=(pre[0][i]+dp[i][j])%hell;
    	}
    }
    int ans=0;
    rep(i,1,k+1) ans=(ans+dp[n][i])%hell;
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