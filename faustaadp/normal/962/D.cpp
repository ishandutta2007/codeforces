#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[202020];
priority_queue<pair<ll,ll> > pq;
pair<ll,ll> u,nx;
vector<ll> v;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		pq.push(mp(-a[i],-i));
	}
	while(pq.size()>1)
	{
		u=pq.top();
		pq.pop();
		if(a[-u.se]!=-u.fi)
			continue;
		nx=pq.top();
	//	cout<<u.fi<<","<<u.se<<" "<<nx.fi<<","<<nx.se<<"\n";
		if(u.fi==nx.fi)
		{
			a[-u.se]=0;
			a[-nx.se]=-u.fi*2;
			pq.push(mp(-a[-nx.se],nx.se));
		}
	}
	for(i=1;i<=n;i++)
		if(a[i]!=0)
			v.pb(a[i]);
	cout<<v.size()<<"\n";
	for(i=0;i<v.size();i++)
		if(i+1<v.size())
			cout<<v[i]<<" ";
		else
			cout<<v[i]<<"\n";
}