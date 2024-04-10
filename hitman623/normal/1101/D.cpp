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
int n,val[200005],ans;
vi primes[200005];
vi a[200005];
mi mp[200005];
void process_seive(){
	int m=200000;
	rep(i,2,m+1){
		if(sz(primes[i])) continue;
		for(int j=i;j<=m;j+=i){
			primes[j].pb(i);
		}
	}
}
void dfs(int node,int par,int d){
	if(val[node]>1) ans=max(ans,1);
	for(auto i:primes[val[node]]) mp[node][i]=d;
	for(auto i:a[node]){
		if(i!=par){
			dfs(i,node,d+1);
			for(auto j:mp[i]){
				if(val[node]%j.x) continue; 
				if(mp[node].count(j.x)){
					ans=max(ans,j.y+mp[node][j.x]-2*d+1);
				}
			}
			for(auto j:mp[i]){
				if(val[node]%j.x) continue; 
				mp[node][j.x]=max(mp[node][j.x],j.y);
			}
		}
	}
}
void solve(){
	process_seive();
	cin>>n;
	rep(i,1,n+1) cin>>val[i];
	rep(i,0,n-1){
		int x,y;
		cin>>x>>y;
		a[x].pb(y);
		a[y].pb(x);
	}
	dfs(1,0,0);
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