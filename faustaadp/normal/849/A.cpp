#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,i,a[1010];
bool b[1010][5][5],bo;
ll rmt(ll aa,ll bb,ll cc)
{
	//cout<<aa<<" "<<bb<<" "<<cc<<"\n";
	if(aa==n&&cc==1&&bb==1&&a[aa]==1)
	{
	//	cout<<"Y\n";
		bo=1;
	}
	else
	{
		if(aa<n)
		{
			if(b[aa][bb][cc]==0)
			{
				b[aa][bb][cc]=1;
				if(a[aa]==1&&a[aa+1]==1&&cc==1)
				{
					rmt(aa+1,(bb+1)%2,1);
				}
				rmt(aa+1,bb,(cc+1)%2);	
			}
		}
	}
}
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]=a[i]%2;
	}
	if(a[1]==1)
		rmt(1,1,1);
	if(bo)	cout<<"Yes\n";
	else	cout<<"No\n";
}