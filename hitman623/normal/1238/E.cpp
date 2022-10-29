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
int n,m,dp[1<<20],f[22][22];
string s;
void solve(){
	memset(dp,1,sizeof dp);
	dp[0]=0;
    cin>>n>>m>>s;
    rep(i,1,sz(s)) f[s[i-1]-'a'][s[i]-'a']++;
    rep(i,1,1<<m){
    	int pos=__builtin_popcount(i);
    	rep(j,0,m){
    		if((i>>j)&1){
    			int cur=dp[i^(1<<j)];
    			rep(k,0,m){
    				if(k==j) continue;
    				if((i>>k)&1) cur+=(f[k][j]+f[j][k])*pos;
    				else cur-=(f[k][j]+f[j][k])*pos;
    			}
    			dp[i]=min(dp[i],cur);
    		}
    	}
    }
    cout<<dp[(1<<m)-1]<<endl;
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