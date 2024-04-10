#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,has,i,a[1010101],h1,h2,tem,tom,j;
int d[10000010];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);		
	has=1e18;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(d[a[i]])
		{
			has=min(has,a[i]);
			if(has==a[i])
			{
				h1=d[a[i]];
				h2=i;
			}
		}
		d[a[i]]=i;
	}
	for(i=1;i<=10000000;i++)
	{
		tem=-1;
		for(j=i;j<=10000000;j+=i)
		{
			if(d[j])
			{
				if(tem==-1)tem=d[j];
				else 
				{
					tom=a[tem]/i;
					tom*=a[d[j]];
					if(has>tom)
					{
						h1=tem;
						h2=d[j];
						has=tom;
					}
					break;
				}
			}
		}
	}
	//cout<<has<<"\n";
	cout<<min(h1,h2)<<" "<<max(h1,h2)<<"\n";
}