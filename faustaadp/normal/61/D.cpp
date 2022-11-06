#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
ll n,i,ta,tb,tc,awal,has;
vector<ll> v[101010],w[101010];
void dfs(ll aa,ll bb,ll cc)
{
	has=min(has,awal-cc);
	ll ii;
	for(ii=0;ii<v[aa].size();ii++)
		if(v[aa][ii]!=bb)
			dfs(v[aa][ii],aa,cc+w[aa][ii]);
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(i=1;i<n;i++)
	{
		cin>>ta>>tb>>tc;
		v[ta].pb(tb);
		v[tb].pb(ta);
		w[ta].pb(tc);
		w[tb].pb(tc);
		awal+=2*tc;
	}
	has=1e18;
	dfs(1,1,0);
	cout<<has<<"\n";
}