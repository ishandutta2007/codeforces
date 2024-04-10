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
int n,dp[300005][3],a[300005],b[300005];
int go(int pos,int f){
	if(pos==n+1) return 0;
	int &ans=dp[pos][f];
	if(ans!=-1) return ans;
	ans=1e18;
	a[pos-1]+=f;
	if(a[pos-1]!=a[pos]){
		ans=min(ans,go(pos+1,0));
		if(a[pos]+1!=a[pos-1]) ans=min(ans,go(pos+1,1)+b[pos]);
		else if(a[pos]+2!=a[pos-1]) ans=min(ans,go(pos+1,2)+2*b[pos]);
	}
	else{
		ans=min(ans,go(pos+1,1)+b[pos]);
		ans=min(ans,go(pos+1,2)+2*b[pos]);
	}
	a[pos-1]-=f;
	return ans;
}
void solve(){
    cin>>n;
    rep(i,0,n+1) dp[i][0]=dp[i][1]=dp[i][2]=-1;
    rep(i,1,n+1) cin>>a[i]>>b[i];
    cout<<go(1,0)<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}