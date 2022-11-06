#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
ll n,m,s,i,b[5050],ta,tb,has,sud[5050],x[5050][5050],heh[5050];
vector<ll> v[5050];
pair<ll,ll> A[5050];
void dfs1(ll aa)
{
	b[aa]=1;
	x[i][aa]=1;
	heh[i]++;
	ll ii;
	for(ii=0;ii<v[aa].size();ii++)
		if(!b[v[aa][ii]])
			dfs1(v[aa][ii]);
}
void upd(ll aa)
{
	ll ii;
	for(ii=1;ii<=n;ii++)
		if(x[aa][ii])
			sud[ii]=1;
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m>>s;
	for(i=1;i<=m;i++)
	{
		cin>>ta>>tb;
		v[ta].pb(tb);
	}
	for(i=1;i<=n;i++)
	{
		memset(b,0,sizeof(b));
		dfs1(i);
	}
	for(i=1;i<=n;i++)A[i]=mp(heh[i],i);
	sort(A+1,A+1+n);
	reverse(A+1,A+1+n);
	upd(s);
	for(i=1;i<=n;i++)
		if(!sud[A[i].se])
		{
			has++;
			upd(A[i].se);
		}
	cout<<has<<"\n";
}