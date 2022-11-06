#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll an[101010],ad[101010],n,m,k,x,i,ta,tb,mo=1e9+7,has;
ll d[101010][3][11];
vector<ll> v[101010];
void dfs(ll aa,ll bb)
{
	an[aa]=-1;
	ad[aa]=-1;
	ll ii;
	vector<ll> tem;
	for(ii=0;ii<v[aa].size();ii++)
		if(v[aa][ii]!=bb)
		{
			dfs(v[aa][ii],aa);
			tem.pb(v[aa][ii]);
		}
	if(tem.empty())return ;
	an[aa]=tem[0];
	for(ii=1;ii<tem.size();ii++)
		ad[tem[ii-1]]=tem[ii];
}
ll depe(ll aa,ll bb,ll cc)
{
	if(cc<0)return 0;
	if(d[aa][bb][cc]==-1)
	{		
		if(an[aa]==-1&&ad[aa]==-1)
		{
			d[aa][bb][cc]=0;
			if((cc==0)&&(m>1))
			{
				if(bb==0||bb==2)
					d[aa][bb][cc]=m-1;
				else
				if(bb==1)
					d[aa][bb][cc]=k-1;
			}
			else
			if(cc==1&&bb==0)
				d[aa][bb][cc]=1;
		}
		else
		if(an[aa]==-1)
		{
			if(bb==0||bb==2)
				d[aa][bb][cc]=(depe(ad[aa],bb,cc)*(m-1))%mo;
			else
				d[aa][bb][cc]=(depe(ad[aa],bb,cc)*(k-1))%mo;
			if(bb==0)
				d[aa][bb][cc]=(d[aa][bb][cc]+depe(ad[aa],bb,cc-1))%mo;
		}
		else
		if(ad[aa]==-1)
		{
			if(bb==0||bb==2)
			{
				d[aa][bb][cc]=(depe(an[aa],0,cc)*(k-1))%mo;
				d[aa][bb][cc]=(d[aa][bb][cc]+depe(an[aa],2,cc)*(m-k))%mo;
			}
			else
				d[aa][bb][cc]=(depe(an[aa],0,cc)*(k-1))%mo;
			if(bb==0)
				d[aa][bb][cc]=(d[aa][bb][cc]+depe(an[aa],1,cc-1))%mo;
		}
		else
		{
			d[aa][bb][cc]=0;
			ll ii;
			for(ii=0;ii<=cc;ii++)
			{
				if(bb==0||bb==2)
				{	
					d[aa][bb][cc]=(d[aa][bb][cc]+(((depe(an[aa],0,ii)*(k-1))%mo)*(depe(ad[aa],bb,(cc-ii)))))%mo;
					d[aa][bb][cc]=(d[aa][bb][cc]+(((depe(an[aa],2,ii)*(m-k))%mo)*(depe(ad[aa],bb,(cc-ii)))))%mo;
				}	
				else
					d[aa][bb][cc]=(d[aa][bb][cc]+(((depe(an[aa],0,ii)*(k-1))%mo)*(depe(ad[aa],bb,(cc-ii)))))%mo;
			}
			if(bb==0)
			{
				for(ii=0;ii<cc;ii++)
					d[aa][bb][cc]=(d[aa][bb][cc]+(((depe(an[aa],1,ii))%mo)*(depe(ad[aa],bb,(cc-ii-1)))))%mo;					
			}
		}
	//	cout<<aa<<" "<<bb<<" "<<cc<<" "<<d[aa][bb][cc]<<"\n";
	}
	return d[aa][bb][cc];
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<n;i++)
	{
		cin>>ta>>tb;
		v[ta].pb(tb);
		v[tb].pb(ta);
	}
	cin>>k>>x;
	dfs(1,1);
	memset(d,-1,sizeof(d));
	for(i=x;i>=0;i--)
		has=(has+depe(1,0,i))%mo;
	cout<<has<<"\n";
}