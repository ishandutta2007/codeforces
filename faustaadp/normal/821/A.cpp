#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[1010][1010],i,j,tt,ii,jj;
bool b,bb;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	b=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			bb=0;
			if(a[i][j]==1)
				bb=1;
			for(ii=1;ii<=n;ii++)
			{
				if(i!=ii)
				{
					for(jj=1;jj<=n;jj++)
					{
						if(j!=jj)
						{
							if(a[i][j]!=1)
							{
								if(a[i][j]==a[i][jj]+a[ii][j])
								{
			//						cout<<i<<" "<<j<<" "<<i<<" "<<jj<<" "<<ii<<" "<<j<<endl;
									bb=1;
								}
							}
						}
					}
				}
			}
			if(bb==0)
				b=0;
		//	cout<<i<<" "<<j<<" bb"<<b<<endl;
		}
	}
	if(b)
		cout<<"Yes\n";
	else
		cout<<"No\n";
}