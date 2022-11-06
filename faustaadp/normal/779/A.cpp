#include<bits/stdc++.h>
using namespace std;
long long n,i,a[100],b[100],c[100],hs,ta;
bool bo;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>ta;
		a[ta]++;
		c[ta]++;
	}
	for(i=1;i<=n;i++)
	{
		cin>>ta;
		b[ta]++;
		c[ta]++;
	}
	bo=0;
	for(i=1;i<=5;i++)
	{
		if(c[i]%2==1)
		{
			bo=1;
			break;
		}
		else
		{
			c[i]=c[i]/2;
		}
	}
	if(bo==1)
	{
		cout<<-1<<endl;
	}
	else
	{
		for(i=1;i<=5;i++)
		{
			//cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<endl;
			hs=hs+abs(a[i]-c[i]);
			hs=hs+abs(b[i]-c[i]);
		}
		cout<<hs/4<<endl;
	}
}