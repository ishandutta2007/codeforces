#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,i,ta,tb,b[101010];
vector<ll> X;
vector<ll> v[101010];
priority_queue<ll> pq;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>ta>>tb;
		v[ta].pb(tb);
		v[tb].pb(ta);
	}
	pq.push(-1);
	while(!pq.empty())
	{
		ll u=-pq.top();
		pq.pop();
		if(b[u])continue;
		b[u]=1;
		X.pb(u);
		//pq.pop();
		for(i=0;i<v[u].size();i++)
			if(!b[v[u][i]])
				pq.push(-v[u][i]);
	}
	//cout<<X.size()<<"\n";
	//return 0;
	for(i=0;i<n;i++)
		if(i<(n-1))cout<<X[i]<<" ";
		else cout<<X[i]<<"\n";
}