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
int n,r,a[101],b[101];
int dp[101][60003];
vii v;
int go(int pos,int w){
	if(w<0) return -hell;
	if(pos==n) return 0;
	int &ans=dp[pos][w];
	if(ans!=-1) return ans;
	ans=go(pos+1,w);
	if(a[v[pos].y]<=w) ans=max(ans,go(pos+1,w+b[v[pos].y])+1);
	return ans;
}
void solve(){
    cin>>n>>r;
    rep(i,0,n){
    	cin>>a[i]>>b[i];
    	if(b[i]>=0) v.pb({a[i]-hell,i});
    	else v.pb({-(a[i]+b[i]),i});
    }
    sort(all(v));
    memset(dp,-1,sizeof dp);
    // if(go(0,r)==n) cout<<"YES"<<endl;
    // else cout<<"NO"<<endl;
    cout<<go(0,r)<<endl;
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