#include "bits/stdc++.h"

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)		cerr<<#a<<" : "<<a<<endl
#else
#define tr(a)    
#endif
#define int 		long long
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
vii a[100005];
int sum=0,s[100005],p[100005],n,q;
void dfs(int node,int par)
{
	p[node]=par;
	s[node]=1;
	for(auto i:a[node])
		if(i.x!=par){
			dfs(i.x,node);
			s[node]+=s[i.x];
			sum+=i.y*s[i.x]*(n-s[i.x]);
		}
}
void solve()
{
	cin>>n;
	vi x(n),y(n),l(n);
	rep(i,0,n-1)	
	{
		cin>>x[i]>>y[i]>>l[i];
		a[x[i]].pb({y[i],l[i]});
		a[y[i]].pb({x[i],l[i]});
	}
	dfs(1,-1);
	cin>>q;
	while(q--)
	{
		int r,w;
		cin>>r>>w;
		r--;
		if(p[x[r]]==y[r])
		{
			sum-=s[x[r]]*(n-s[x[r]])*(l[r]-w);
			l[r]=w;
		}
		else
		{
			sum-=s[y[r]]*(n-s[y[r]])*(l[r]-w);
			l[r]=w;	
		}
		cout<<fixed<<setprecision(10);
		cout<<1.0l*(sum*6)/(n*(n-1))<<endl;
	}
}

signed main()
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