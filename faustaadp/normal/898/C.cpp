#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll t,n,i,tt,j,k,l,m,v1[10101];
string s,z,c2[10101];
map<string,ll> me;
vector<string> v[10101];
vector<string> ve[10101];
bool bo,boi;
bool cm(string aa,string bb)
{
	return (aa.length()<bb.length());
}
ll c1(string aa)
{
	if(me[aa]==0)
	{
		tt++;
		me[aa]=tt;
		c2[tt]=aa;
	}
	return me[aa];
}
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>s;
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>z;
			v[c1(s)].pb(z);
		}
	}
	for(i=1;i<=tt;i++)
	{
		sort(v[i].begin(),v[i].end(),cm);
		boi=1;
		for(j=0;j<v[i].size();j++)
		{
			bo=1;
			for(k=j+1;k<v[i].size();k++)
			{
				for(l=0;l<v[i][k].length();l++)
				{
					if(v[i][k].substr(l,v[i][k].length()-l)==v[i][j])
						bo=0;
				}
			}
			if(bo&&boi)
			{
				boi=0;
				m++;
			}
			if(bo)
			{
			//	m++;
				//cout<<m<<"\n";
				ve[m].pb(v[i][j]);
				v1[m]=i;
			}
		}
	}
	cout<<m<<"\n";
	for(i=1;i<=m;i++)
	{
		cout<<c2[v1[i]]<<" "<<ve[i].size();
		for(j=0;j<ve[i].size();j++)
			cout<<" "<<ve[i][j];
		cout<<"\n";
	}
}