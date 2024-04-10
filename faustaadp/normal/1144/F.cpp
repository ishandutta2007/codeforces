#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
ll n,m,i,b[202020],h[202020],ta,tb;
vector<ll> v[202020],w[202020];
void dfs(ll aa,ll bb)
{
	//cout<<aa<<" "<<bb<<"\n";
	if(b[aa]!=0&&b[aa]!=bb)
	{
		cout<<"NO\n";
		exit(0);
	}
	if(b[aa]!=0)return ;
	b[aa]=bb;
	ll ii,nx=1;
	if(bb==1)nx=2;
	for(ii=0;ii<v[aa].size();ii++)
	{
		if(w[aa][ii]>0&&bb==1)h[abs(w[aa][ii])]=1;
		if(w[aa][ii]<0&&bb==2)h[abs(w[aa][ii])]=1;
		dfs(v[aa][ii],nx);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>ta>>tb;
		v[ta].pb(tb);
		w[ta].pb(i);
		v[tb].pb(ta);
		w[tb].pb(-i);
	}
	dfs(1,1);
	cout<<"YES\n";
	for(i=1;i<=m;i++)cout<<h[i];
	cout<<"\n";
}