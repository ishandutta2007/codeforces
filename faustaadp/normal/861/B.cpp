#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,i,j,hs,a[1010],b[1010],tt;
bool bb,bo[1010];
int main()
{
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(i=1;i<=1000;i++)
	{
		bb=1;
		for(j=1;j<=n;j++)
		{
			if(!(i*(b[j]-1)+1<=a[j]&&a[j]<=i*b[j]))
			{
				bb=0;
			}
		}
		if(bb==1)
		{
			//cout<<i<<"\n";
			for(j=1;j<=1000;j++)
			{
				if((i*(j-1)+1<=n&&n<=i*j))
				{
					if(bo[j]==0)
					{
						bo[j]=1;
						tt++;
						hs=j;
					}
				}
			}
		}
	}
	if(tt!=1)
	{
		cout<<-1<<"\n";
	}
	else
		cout<<hs<<"\n";
		
}