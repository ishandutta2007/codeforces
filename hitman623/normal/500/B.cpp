#include "bits/stdc++.h"

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)		cerr<<#a<<" : "<<a<<endl
#else
#define tr(a)    
#endif

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii 		vector<pii>
#define mi 			map<int,int>
#define mii			map<int,pii>	
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;
vi adj[303];
int cnt=0,ans[303],vis[303];
vi val1[303],val2[303];	
vi p(303);
void dfs(int node)
{
	vis[node]=1;
	val1[cnt].pb(p[node]);
	val2[cnt].pb(node);
	for(auto i:adj[node])
		if(!vis[i])
		dfs(i);
}
void solve()
{
	int n;
	cin>>n;
	rep(i,0,n)
		cin>>p[i];
	string a[n];
	rep(i,0,n)
		cin>>a[i];
	rep(i,0,n)
		rep(j,0,n)
		if(a[i][j]=='1'){
			adj[i].pb(j);
			adj[j].pb(i);
		}
	rep(i,0,n)
		if(!vis[i]){
			dfs(i);
			cnt++;
		}
	rep(i,0,cnt)
	{
		sort(all(val1[i]));
		sort(all(val2[i]));
		rep(j,0,sz(val1[i])){
			ans[val2[i][j]]=val1[i][j];
		}
	}
	rep(i,0,n)
		cout<<ans[i]<<" ";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
	return 0;
}