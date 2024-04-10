#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll i,k[1010101],t,n,tt,bo,j,m;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(i=1;i<=1000000;i++)
		k[i]=i*i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n==0)
		{
			cout<<"1 1\n";
			continue;
		}
		tt=1;
		bo=0;
		for(i=n;;)
		{
			i=n+k[tt];
	//		cout<<i<<" "<<k[tt]<<"\n";
			tt++;
			if(bo==1)
				break;
			if((i-n)*4>i)
				break;
			if((ll)sqrt(i)*(ll)sqrt(i)==i)
			{
				for(j=1;j<=sqrt(i);j++)
				{
				//	cout<<(ll)((sqrt(i))/j)*(ll)((sqrt(i))/j)<<" "<<k[tt-1]<<"\n";
					if((ll)((sqrt(i))/j)*(ll)((sqrt(i))/j)==k[tt-1])
					{
						n=sqrt(i);
						m=j;
				//		cout<<n<<"-"<<m<<"\n";
						bo=1;
						break;
					}
				}
			}
			if(bo==1)
				break;
		}
		if(bo==1)
			cout<<n<<" "<<m<<"\n";
		else
			cout<<-1<<"\n";
	}
}