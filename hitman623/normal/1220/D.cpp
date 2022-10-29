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
int n,a[200002],vis[200005];
vi v[66];
void solve(){
	cin>>n;
	rep(i,0,n){
		cin>>a[i];
		int x=a[i];
		int cur=0;
		while(x%2==0) x/=2,cur++;
		v[cur].pb(i);
	}
	int mx=0;
	rep(i,0,66) mx=max(mx,sz(v[i]));
	rep(i,0,66){
		if(sz(v[i])==mx){
			cout<<n-sz(v[i])<<endl;
			for(auto j:v[i]) vis[j]=1;
			rep(j,0,n) if(vis[j]==0) cout<<a[j]<<" ";
			cout<<endl;
			return;
		}
	}
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