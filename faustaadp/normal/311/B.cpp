#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,t,ta,p[101010],tb,a[101010],d[2][101010],I,i,P[101010];
void cari(ll aa,ll bb,ll cc,ll dd)
{
	if(aa>bb)return ;
	ll ce=(aa+bb)/2,ii,OPT;
	d[I][ce]=1e18;
	for(ii=max(ce,cc);ii<=dd;ii++)
	{
		//cout<<ce<<" "<<ii<<" "<<P[ii]-P[ce-1]<<" "<<(a[ce]*(ii-ce+1))<<" "<<d[1-I][ii+1]<<"\n";
		if((d[I][ce])>(-P[ii]+P[ce-1]+(a[ii]*(ii-ce+1))+d[1-I][ii+1]))
		{
			//cout<<"ii "<<ce<<"\n";
			OPT=ii;
			d[I][ce]=(-P[ii]+P[ce-1]+(a[ii]*(ii-ce+1))+d[1-I][ii+1]);
		}
	}
	//cout<<i<<" "<<aa<<" "<<bb<<" "<<ce<<" "<<d[I][ce]<<"\n";
	cari(aa,ce-1,cc,OPT);
	cari(ce+1,bb,OPT,dd);
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m>>t;
	for(i=2;i<=n;i++)
	{
		cin>>ta;
		p[i]=p[i-1]+ta;
	}
	for(i=1;i<=m;i++)
	{
		cin>>ta>>tb;
		a[i]=tb-p[ta];
	//	cout<<i<<" "<<a[i]<<"\n";
		d[0][i]=1e18;
	}
	sort(a+1,a+1+m);
	for(i=1;i<=m;i++)P[i]=P[i-1]+a[i];
	//for(i=1;i<=m;i++)cout<<i<<" "<<a[i]<<" "<<P[i]<<"\n";
	for(i=1;i<=t;i++)
	{
		I=i%2;
		cari(1,m,1,m);
	}
	cout<<d[t%2][1]<<"\n";
}