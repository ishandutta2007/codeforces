#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,q,i,ta,tb,j,l1,l2,Vs[20][101010],dep[101010],p[20][101010],k;
vector<ll> v[101010],V[20][101010],has;
void dfs(ll aa,ll bb)
{
	dep[aa]=bb;
	ll ii;
	for(ii=0;ii<v[aa].size();ii++)
	{
		if(dep[v[aa][ii]]>0)
			continue;
		p[0][v[aa][ii]]=aa;
		dfs(v[aa][ii],bb+1);
	}
}
void cari(ll aa,ll bb)
{
	if(dep[aa]<dep[bb])
		swap(aa,bb);
	ll ii,jj;
	for(ii=19;ii>=0;ii--)
	{
		if((dep[aa]-(1<<ii))>=dep[bb])
		{
			for(jj=0;jj<Vs[ii][aa];jj++)
				has.pb(V[ii][aa][jj]);	
			aa=p[ii][aa];
		}
	}
//	cout<<aa<<" "<<bb<<"\n";
	if(aa==bb)
	{
		for(ii=0;ii<Vs[0][aa];ii++)
			has.pb(V[0][aa][ii]);
		return ;
	}
	for(ii=19;ii>=0;ii--)
	{
		if(p[ii][aa]!=p[ii][bb])
		{
			for(jj=0;jj<Vs[ii][aa];jj++)
				has.pb(V[ii][aa][jj]);	
			for(jj=0;jj<Vs[ii][bb];jj++)
				has.pb(V[ii][bb][jj]);	
			aa=p[ii][aa];
			bb=p[ii][bb];
		}
	}
//	cout<<aa<<" "<<bb<<"\n";
	for(ii=0;ii<Vs[1][aa];ii++)
		has.pb(V[1][aa][ii]);
	for(ii=0;ii<Vs[0][bb];ii++)
		has.pb(V[0][bb][ii]);
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>q;
	for(i=1;i<n;i++)
	{
		cin>>ta>>tb;
		v[ta].pb(tb);
		v[tb].pb(ta);
	}
	for(i=1;i<=m;i++)
	{
		cin>>ta;
		if(Vs[0][ta]<10)
		{
			V[0][ta].pb(i);
			Vs[0][ta]++;
		}
	}
	dfs(1,1);
	for(i=1;i<=19;i++)
		for(j=1;j<=n;j++)
		{
			p[i][j]=p[i-1][p[i-1][j]];
			l1=0;
			l2=0;
			for(k=1;k<=10;k++)
			{
		//		cout<<l1<<" "<<l2<<" "<<Vs[i-1][j]<<" "<<Vs[i-1][p[i-1][j]]<<"\n";
				if(l1==Vs[i-1][j]&&l2==Vs[i-1][p[i-1][j]])
					break;
				if(l2<Vs[i-1][p[i-1][j]]&&(l1==Vs[i-1][j]||(V[i-1][j][l1]>V[i-1][p[i-1][j]][l2])))
				{
					V[i][j].pb(V[i-1][p[i-1][j]][l2]);
					l2++;
				}
				else
				{
					V[i][j].pb(V[i-1][j][l1]);
					l1++;
				}
				Vs[i][j]++;
			}
	//		cout<<i<<" "<<j<<" "<<Vs[i][j]<<" -> ";
	//		for(k=0;k<Vs[i][j];k++)
	//			cout<<V[i][j][k]<<" ";
	//		cout<<"\n";
		}
	while(q--)
	{
		has.clear();
		cin>>ta>>tb>>k;
		cari(ta,tb);
		sort(has.begin(),has.end());
		cout<<min((ll)has.size(),k);
		for(i=0;i<min((ll)has.size(),k);i++)
			cout<<" "<<has[i];
		cout<<"\n";
	}
}