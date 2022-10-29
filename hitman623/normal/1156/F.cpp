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
int expo(int base,int exponent,int mod){
    int ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
int n,a[5005],inv[5005],dp[5005][5005];
int go(int pos,int cnt){
	if(pos==n+1) return 0;
	int &ans=dp[pos][cnt];
	if(ans!=-1) return ans;
	ans=go(pos+1,cnt);
	if(a[pos]) ans=(ans+go(pos+1,cnt+1)*a[pos]%hell*inv[n-cnt]%hell)%hell;
	if(a[pos]>1) ans=(ans+inv[n-cnt]*a[pos]%hell*(a[pos]-1)%hell*inv[n-cnt-1]%hell)%hell;
	return ans;
}
void solve(){
	memset(dp,-1,sizeof dp);
    cin>>n;
    rep(i,1,n+1){
    	int x;
    	cin>>x;
    	a[x]++;
    	inv[i]=expo(i,hell-2,hell);
    }
    cout<<go(1,0)<<endl;
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