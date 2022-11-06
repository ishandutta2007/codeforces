#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,m,i,a[101010],hs,hz,hm,j,ki,hh;
int main()
{
//	memset(d,-1,sizeof(d))
//	n=45;
//	k=45;
//	m=2000000000;
	cin>>n>>k>>m;
	for(i=1;i<=k;i++)
	{
//		a[i]=rand()%1001010;
		cin>>a[i];
		hh=hh+a[i];
	}
	sort(a+1,a+1+k);
	for(i=0;i<=n;i++)
	{
		if(m-hh*i>=0)
		{
			hz=(k+1)*i;
			hm=m-hh*i;
			for(j=1;j<=k;j++)
			{
			//	cout<<hm<<"\n";
				if(a[j]*(n-i)<=hm)
				{
					hm=hm-(a[j]*(n-i));
					hz=hz+(n-i);
				}
				else
				{
					for(ki=1;ki<=(n-i);ki++)
					{
						if(hm-a[j]<0)
							break;
						hm=hm-a[j];
						hz++;
					}
					break;
				}
			//	cout<<hs<<"\n";
			}
			hs=max(hs,hz);
		}
	}
	cout<<hs<<"\n";
}