#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
ll n,k,ta,tb,D[202020],hz,war[202020],i;
vector<ll> v[202020],w[202020];
ll cek(ll aa)
{
	ll ii,H=0;
	for(ii=1;ii<=n;ii++)
		if(D[ii]>aa)
			H++;
	return (H<=k);
}
void dfs(ll aa,ll bb,ll cc)
{
	ll ii,tee=0;
	for(ii=0;ii<v[aa].size();ii++)
	{
		if(v[aa][ii]==bb)continue;
		tee++;
		if(tee==cc)tee++;
		while(tee>hz)tee-=hz;
		war[w[aa][ii]]=tee;
		dfs(v[aa][ii],aa,tee);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>k;
	for(i=1;i<n;i++)
	{
		cin>>ta>>tb;
		v[ta].pb(tb);
		v[tb].pb(ta);
		D[ta]++;
		D[tb]++;
		w[ta].pb(i);
		w[tb].pb(i);
	}
	ll L=1,R=n,C;
	while(L<=R)
	{
		C=(L+R)/2;
		if(cek(C))
		{
			hz=C;
			R=C-1;
		}
		else
			L=C+1;
	}
	dfs(1,1,0);
	cout<<hz<<"\n";
	for(i=1;i<n;i++)
		if(i<(n-1))
			cout<<war[i]<<" ";
		else
			cout<<war[i]<<"\n";
}