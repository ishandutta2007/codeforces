#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,k,i,ta,tb,has,b[101010];
vector<ll> v[101010];
void dfs(ll aa)
{
	b[aa]=1;
	ll ii;
	for(ii=0;ii<v[aa].size();ii++)
		if(b[v[aa][ii]]==0)
		{
			has--;
			dfs(v[aa][ii]);
		}
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	cin>>n>>k;
	for(i=1;i<=k;i++)
	{
		cin>>ta>>tb;
		v[ta].pb(tb);
		v[tb].pb(ta);
		//v[y[i]].pb(mp(x[i],i));
	}
	has=k;
	for(i=1;i<=n;i++)
		if(!b[i])
			dfs(i);
	cout<<has<<"\n";
}