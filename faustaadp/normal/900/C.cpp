#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,i,ta,m1,m2,a[1010101],hz,h1,h2;
bool b[1010101];
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>ta;
		if(ta>m1)
		{
			m2=m1;
			m1=ta;
		}
		else
		if(ta>m2)
		{
			m2=ta;
		}
		if(ta==m2)
		{
			a[m1]++;
			hz=max(hz,a[m1]);
		}
		if(ta==m1)
		{
			h2++;
			b[ta]=1;
		}
	}
	if(hz==0)
	{
		for(i=1;i<=n;i++)
		{
			if(b[i]==0)
			{
				cout<<i<<"\n";
				return 0;
			}
		}
		cout<<1<<"\n";
	}
	else
	if(hz==1)
	{
		for(i=1;i<=n;i++)
		{
			if(b[i]==0||a[i]==hz)
			{
				cout<<i<<"\n";
				return 0;
			}
		}
		cout<<1<<"\n";
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			if(hz==a[i])
			{
				cout<<i<<"\n";
				return 0;
			}
		}
		cout<<1<<"\n";
	}
}