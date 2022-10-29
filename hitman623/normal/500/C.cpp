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

void solve()
{
	int n,m;
	cin>>n>>m;
	vi w(n+1),b(m);
	rep(i,1,n+1)
	cin>>w[i];
	rep(i,0,m)
	cin>>b[i];
	vi p;
	int v[1001]={0};
	rep(i,0,m)
	if(v[b[i]]==0){
		p.pb(b[i]);
		v[b[i]]=1;
	}
	int cost=0;
	rep(i,0,m)
	{
		int j;
		for(j=0;j<n;++j)
			if(p[j]==b[i])
				break;
			else cost+=w[p[j]];
		p.erase(p.begin()+j);
		p.insert(p.begin(),b[i]);
	}
	cout<<cost;
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