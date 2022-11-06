#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ll long long

ll t,k,jum,a[99],has,hz,hv,i,j;
int main () 
{
	cin>>t;
	while(t--)
	{
		cin>>k;
		jum=0;
		for(i=0;i<7;i++)cin>>a[i];
		for(i=0;i<7;i++)jum+=a[i];
		has=1e18;
		for(i=0;i<7;i++)
		{
			if(a[i]==0)continue;
			hz=k/jum;
			hz*=7;
			hv=k%jum;
			if(hv==0)
			{
//				cout<<hz<<"\n";
				for(j=(i+7)-1;j>=0;j--)
				{
					if(a[j%7]==1)
					{
						//cout<<j<<"a\n";
						hz-=((i+7)-j)-1;
						break;
					}
				}
			}
			else
			{
				for(j=i;j<=1000;j++)
				{
					if(a[j%7]==1)
					{
						hv--;
						if(hv==0)
						{
							hz+=(j-i)+1;
							break;
						}
					}
				}
			}
			has=min(has,hz);
		}
		cout<<has<<"\n";
	}
}