#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,i,l[1010],r[1010],j,bb;
char ta;
bool b[1010];
void car(ll aa)
{
//	cout<<aa<<"\n";
	if(r[aa]==0)
	{
		ll ii;
		bool bo=0;
		for(ii=1;ii<=n;ii++)
		{
			if(l[ii]==0&&ii!=aa&&ii!=bb)
			{
				r[aa]=ii;
				l[ii]=aa;
				bo=1;
				break;
			}
		}
		if(bo==0)
			return;
		else
			car(r[aa]);
	}
	else
		car(r[aa]);
		
}
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>l[i]>>r[i];
		if(l[i]==0&&bb==0)
		{
			bb=i;
		}
	}
	car(bb);
	for(i=1;i<=n;i++)
	{
		cout<<l[i]<<" "<<r[i]<<"\n";
	}
}