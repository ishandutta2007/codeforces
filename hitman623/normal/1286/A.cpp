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
int n,p[101],dp[101][2][101][101];
int go(int pos,int f,int z,int o){
	if(pos==n) return 0;
	int &ans=dp[pos][f][z][o];
	if(ans!=-1) return ans;
	if(p[pos]) return ans=go(pos+1,p[pos]%2,z,o)+(p[pos]%2!=f);
	ans=hell;
	if(z) ans=min(ans,go(pos+1,0,z-1,o)+f);
	if(o) ans=min(ans,go(pos+1,1,z,o-1)+(f^1));
	return ans;
}
int f[2];
void solve(){
    cin>>n;
    f[0]=n/2;
    f[1]=(n+1)/2;
    rep(i,0,n){
    	cin>>p[i];
    	if(p[i]) f[p[i]%2]--;
    }
    int ans=hell;
    if(p[0]==0){
    	if(f[0]){
    		memset(dp,-1,sizeof dp);
    		ans=min(ans,go(1,0,f[0]-1,f[1]));
    	}
    	if(f[1]){
    		memset(dp,-1,sizeof dp);
    		ans=min(ans,go(1,1,f[0],f[1]-1));
    	}
    }
    else{
    	memset(dp,-1,sizeof dp);
    	ans=min(ans,go(1,p[0]%2,f[0],f[1]));
    }
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