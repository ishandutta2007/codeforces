#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,i,x[101010],y[101010],ta,tb,b[101010],bes[101010],a[101010],JK,cal,j,te;
vector<ll> v[101010],tem,isi[101010];
priority_queue<pair<ll,ll> >pq;
void dfs(ll aa)
{
	ll X=v[aa].size();
	bes[aa]=X;
	if(cal==-1||bes[cal]>bes[aa])
		cal=aa;
	b[aa]=1;
	a[JK]++;
	ll ii;
	for(ii=0;ii<v[aa].size();ii++)
		if(!b[v[aa][ii]])
			dfs(v[aa][ii]);
}
void dfs2(ll aa)
{
	b[aa]=2;
	tem.pb(aa);
	ll ii;
	for(ii=0;ii<v[aa].size();ii++)
		if(b[v[aa][ii]]==1)
			dfs2(v[aa][ii]);
}
void gab(ll aa,ll bb)
{
	te++;
	x[te]=aa;
	y[te]=bb;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		x[i]=-1;y[i]=-1;
		cin>>ta>>tb;
		v[ta].pb(tb);
		v[tb].pb(ta);
	}
	for(i=1;i<=n;i++)
		if(!b[i])
		{
			tem.clear();
			cal=-1;
			JK++;
			dfs(i);
			dfs2(cal);
			for(j=0;j<a[JK];j+=2)
				isi[JK].pb(tem[j]);
			for(j=1;j<a[JK];j+=2)
				isi[JK].pb(tem[j]);
			if(a[JK]==3)
				swap(isi[JK][1],isi[JK][2]);
			else
			if(a[JK]==4)
				swap(isi[JK][1],isi[JK][3]);
			else
			if(a[JK]%2==0)
				swap(isi[JK][a[JK]-1],isi[JK][a[JK]-2]);
			pq.push(mp(a[JK],JK));
		}
	ll sisa=m;
	if(JK==2&&a[1]==1&&a[2]==3&&m==3)
	{

	}
	else
	if(JK==2&&a[1]==3&&a[2]==1&&m==3)
	{

	}
	else
	if(a[1]==4&&a[2]==1&&m==4)
	{	
		x[1]=isi[1][0];y[1]=isi[1][3];
		x[2]=isi[1][3];y[2]=isi[2][0];
		x[3]=isi[2][0];y[3]=isi[1][2];
		x[4]=isi[1][2];y[4]=isi[1][1];
	}	
	else
	if(a[1]==1&&a[2]==4&&m==4)
	{
		x[1]=isi[2][0];y[1]=isi[2][3];
		x[2]=isi[2][3];y[2]=isi[1][0];
		x[3]=isi[1][0];y[3]=isi[2][2];
		x[4]=isi[2][2];y[4]=isi[2][1];
	}
	else
	if(a[1]==4&&a[2]==2&&m==5)
	{	
		x[1]=isi[1][0];y[1]=isi[1][3];
		x[2]=isi[1][3];y[2]=isi[2][0];
		x[3]=isi[2][0];y[3]=isi[1][2];
		x[4]=isi[1][2];y[4]=isi[1][1];
		x[5]=isi[1][1];y[5]=isi[2][1];
	}	
	else
	if(a[2]==4&&a[1]==2&&m==5)
	{	
		x[1]=isi[2][0];y[1]=isi[2][3];
		x[2]=isi[2][3];y[2]=isi[1][0];
		x[3]=isi[1][0];y[3]=isi[2][2];
		x[4]=isi[2][2];y[4]=isi[2][1];
		x[5]=isi[2][1];y[5]=isi[1][1];
	}	
	else
	if(JK==1&&a[1]==4&&m==3)
	{
		x[1]=isi[1][2];y[1]=isi[1][1];
		x[2]=isi[1][1];y[2]=isi[1][0];
		x[3]=isi[1][0];y[3]=isi[1][3];
	}
	else
	if(JK==1)
	{
		if(a[1]==3||(a[1]==4&&m==4)||a[1]==2)
		{

		}
		else
		{
			for(i=1;i<a[1];i++)
			{
				gab(isi[1][i-1],isi[1][i]);
				sisa--;
				if(!sisa)break;
			}
			if(sisa)
				gab(isi[1][a[1]-1],isi[1][0]);
		}
	}
	else
	{	
		tem.clear();
		ll las=-1;
		while(1)
		{
			pair<ll,ll> X=pq.top();
			pq.pop();
			pair<ll,ll> Y=pq.top();
			pq.pop();
			if(a[X.se]==0)break;
			if(las!=X.se||a[Y.se]==0)
			{
				las=X.se;
				a[X.se]--;
				tem.pb(isi[X.se][a[X.se]]);
				pq.push(mp(X.fi-1,X.se));
				pq.push(Y);
			}
			else
			{
				las=Y.se;
				a[Y.se]--;
				tem.pb(isi[Y.se][a[Y.se]]);
				pq.push(mp(Y.fi-1,Y.se));
				pq.push(X);
			}
		}
		ll sz=tem.size();
		for(i=1;i<sz;i++)
		{
			gab(tem[i-1],tem[i]);
			sisa--;
			if(!sisa)break;
		}
		if(sisa)
			gab(tem[sz-1],tem[0]);
	}
	if(x[1]==-1)
	{
		cout<<-1<<"\n";
		return 0;
	}
	for(i=1;i<=m;i++)
	 	cout<<x[i]<<" "<<y[i]<<"\n";
	// for(i=1;i<=JK;i++)
	// 	for(j=0;j<isi[i].size();j++)
	// 		cout<<i<<" "<<isi[i][j]<<"\n";
}