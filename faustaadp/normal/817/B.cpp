#include<bits/stdc++.h>
//#define ll long long
using namespace std;
long long a[101010],x,y,i,n,d[101010],hs;
bool b[101010];
map<long long,long long> c;
int main()
{
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		d[i]=a[i];
		c[a[i]]++;
	}
	sort(d,d+n);
	if(d[0]!=d[1]&&d[1]!=d[2]&&d[0]!=d[2])
	{
		cout<<c[d[0]]*c[d[1]]*c[d[2]]<<endl;
	}
	else
	if(d[0]==d[1]&&d[1]==d[2])
	{
		hs=1;
		for(i=max(3LL,c[d[0]]-3LL)+1;i<=c[d[0]];i++)
		{
			hs=hs*i;
			//cout<<hs<<endl;
		}
		for(i=2;i<=min(3LL,c[d[0]]-3LL);i++)
		{
			hs=hs/i;
		//	cout<<hs<<endl;
		}
		cout<<hs<<endl;
	}
	else
	if(d[0]==d[1]&&d[1]!=d[2])
	{
		hs=1;
		for(i=max(2LL,c[d[0]]-2LL)+1;i<=c[d[0]];i++)
			hs=hs*i;
		for(i=2;i<=min(2LL,c[d[0]]-2LL);i++)
			hs=hs/i;
		hs=hs*c[d[2]];
		cout<<hs<<endl;
	}
	else
	if(d[0]!=d[1]&&d[1]==d[2])
	{
		hs=1;
		for(i=max(2LL,c[d[1]]-2LL)+1;i<=c[d[1]];i++)
			hs=hs*i;
		for(i=2;i<=min(2LL,c[d[1]]-2LL);i++)
			hs=hs/i;
		hs=hs*c[d[0]];
		cout<<hs<<endl;
	}
}