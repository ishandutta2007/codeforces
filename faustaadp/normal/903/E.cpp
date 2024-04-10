#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll k,n,i,j,ka,h1,h2,hi,ho;
string s[5050],z[5050],sz;
vector<ll> v;
bool bo;
ll bis(string zz)
{
	ll ii,hh,jj;
	for(ii=1;ii<=k;ii++)
	{
		hh=0;
		for(jj=0;jj<n;jj++)
		{
			if(zz[jj]!=s[ii][jj])
				hh++;
		}
		if(hh>2)
			return 0;
		if(hh==0)
		{
			ll kk;
			bool boo=0;
			for(kk=1;kk<n;kk++)
			{
				if(z[ii][kk]==z[ii][kk-1])
					boo=1;
			}
			if(!boo)
				return 0;
		}
	}
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>k>>n;
	for(i=1;i<=k;i++)
	{
		cin>>s[i];
		z[i]=s[i];
		sort(z[i].begin(),z[i].end());
	}
	for(i=1;i<k;i++)
	{
		if(z[i]!=z[i+1])
		{
			cout<<-1<<"\n";
			return 0;
		}
	}
	if(k==1)
	{
		swap(s[1][0],s[1][1]);
		cout<<s[1]<<"\n";
		return 0;
	}
	for(i=1;i<=k;i++)
	{
		for(j=i+1;j<=k;j++)
		{
			if(s[i]!=s[j])
			{
				for(ka=0;ka<n;ka++)
				{
					if(s[i][ka]!=s[j][ka])
						ho++;
				}
				if(ho>hi)
				{
					hi=ho;
					h1=i;
					h2=j;
				}
			}
		}
	}
	if(hi==0)
	{
		swap(s[1][0],s[1][1]);
		cout<<s[1]<<"\n";
		return 0;
	}
	for(ka=0;ka<n;ka++)
	{	
		if(s[h1][ka]!=s[h2][ka])
			v.pb(ka);
	}
	if(v.size()>4)
	{
		cout<<-1<<"\n";
		return 0;
	}
	for(i=0;i<v.size();i++)
	{
		for(j=i+1;j<v.size();j++)
		{
			sz=s[h1];
			swap(sz[v[i]],sz[v[j]]);
			if(bis(sz))
			{
				cout<<sz<<"\n";
				return 0;
			}
		}
	}
	sz=s[h1];
	if(bis(sz))
	{
		cout<<sz<<"\n";	
		return 0;
	}
	cout<<-1<<"\n";
}