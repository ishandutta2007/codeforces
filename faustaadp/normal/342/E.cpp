#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
ll n,m,i,ta,tb,j,dep[101010],p[22][101010],sz,z[101010],K,dek[101010],b[101010];
vector<ll> v[101010];
void dfs(ll aa,ll bb,ll cc)
{
	dep[aa]=cc;
	ll ii;
	p[0][aa]=bb;
	for(ii=1;ii<=20;ii++)p[ii][aa]=p[ii-1][p[ii-1][aa]];
	for(ii=0;ii<v[aa].size();ii++)
		if(v[aa][ii]!=bb)
			dfs(v[aa][ii],aa,cc+1);
}
ll LCA(ll aa,ll bb)
{
	if(dep[aa]<dep[bb])swap(aa,bb);
	ll ii;
	//cout<<"_"<<aa<<"-"<<bb<<"\n";
	for(ii=20;ii>=0;ii--)
		if((dep[aa]-(1<<ii))>=dep[bb])
			aa=p[ii][aa];
//	cout<<aa<<"X"<<bb<<"\n";
	if(aa==bb)return aa;
	for(ii=20;ii>=0;ii--)
		if(p[ii][aa]!=p[ii][bb])
		{
			aa=p[ii][aa];
			bb=p[ii][bb];
		}
	return p[0][aa];
}
ll jar(ll aa,ll bb)
{
	//cout<<aa<<" "<<bb<<" LCA= "<<LCA(aa,bb)<<"\n";
	return dep[aa]+dep[bb]-2*dep[LCA(aa,bb)];
}
void upd()
{
	ll ii;
	queue<ll> q;
	for(ii=1;ii<=sz;ii++)
	{
		dek[z[ii]]=0;
		q.push(z[ii]);
	}
	while(!q.empty())
	{
		ll u=q.front();
		q.pop();
		for(ii=0;ii<v[u].size();ii++)
			if(dek[v[u][ii]]>dek[u]+1)
			{
				//cout<<"AA";	
				dek[v[u][ii]]=dek[u]+1;
				q.push(v[u][ii]);
			}
	}
//	for(ii=1;ii<=n;ii++)cout<<j<<" "<<ii<<" "<<dek[ii]<<"\n";
	sz=0;
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(i=1;i<n;i++)
	{
		dek[i+1]=1e18;
		cin>>ta>>tb;
		v[ta].pb(tb);
		v[tb].pb(ta);
	}
	dfs(1,1,1);
	K=100;
	j=-1;
	sz=0;
	b[1]=1;
	z[1]=1;
	sz=1;
	upd();
	while(m--)
	{
		cin>>ta;
		if(ta==2)
		{
			cin>>ta;
			if(j>=K)
			{
				upd();
				j=0;
			}
			ll hz=dek[ta];
			for(i=1;i<=sz;i++)
			{
				if(hz==0)break;
				hz=min(hz,jar(ta,z[i]));
			}
			cout<<hz<<"\n";
		}
		else
		{
			j++;
			cin>>ta;	
			sz++;
			b[ta]=1;
			z[sz]=ta;
		}
	}
}