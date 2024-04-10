#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,ta,tb,tc,JK,j,k;
pair<pair<ll,ll>,pair<ll,ll> > A[50505],B[50505];
vector<pair<pair<ll,ll>,pair<ll,ll> > > v[50505];
vector<pair<pair<ll,ll>,pair<ll,ll> > > w[50505];
vector<ll> isi;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>ta>>tb>>tc;
		A[i]=mp(mp(ta,tb),mp(tc,i));
	}
	sort(A+1,A+1+n);
	for(i=1;i<=n;i++)
	{
		if((i==1)||(A[i].fi.fi!=A[i-1].fi.fi))
			JK++;
		v[JK].pb(A[i]);
	}
	for(i=1;i<=JK;i++)
	{
		ll sz=v[i].size(),jk=0;
		vector<ll> tom;
		for(j=0;j<sz;j++)
		{
			// cout<<v[i][j].se.se<<"___\n";
			if(j==0||(v[i][j].fi.se!=v[i][j-1].fi.se))
				jk++;
			w[jk].pb(v[i][j]);
		}
		// cout<<jk<<"@_____\n";
		vector<ll> tem2;
		for(j=1;j<=jk;j++)
		{
			ll siz=w[j].size();
			// cout<<siz<<"@@\n";
			if(siz%2==0)
			{
				for(k=0;k<siz;k++)
				{
					tom.pb(w[j][k].se.se);
				}
			}
			else
			{
				for(k=1;k<siz;k++)
				{
					tom.pb(w[j][k].se.se);
				}
				tem2.pb(w[j][0].se.se);
			}
		}
		for(j=0;j<tem2.size();j++)
			tom.pb(tem2[j]);
		if(sz%2==0)
		{
			for(j=0;j<tom.size();j+=2)
				cout<<tom[j]<<" "<<tom[j+1]<<"\n";
		}
		else
		{
			ll ssz=tom.size();
			for(j=0;j<(ssz-1);j+=2)
				cout<<tom[j]<<" "<<tom[j+1]<<"\n";
			isi.pb(tom[ssz-1]);
		}
		for(j=1;j<=jk;j++)
			w[j].clear();
	}
	// cout<<isi.size()<<"___\n";
	for(i=0;i<isi.size();i+=2)
		cout<<isi[i]<<" "<<isi[i+1]<<"\n";
}



// 0 1 1  1	
// 1 0 1  2
// // 1 1 0  3
// // 1 1 1  4
// // 2 2 2  5
// // 2 2 3  8
// 2 3 2  7
// 3 2 2  6