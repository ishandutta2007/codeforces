#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,i,a[101010],c[101010],j,bb,hz;
char ta;
bool b[1010];
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		c[i]=a[i];
		if(a[i]-a[i-1]<=0)
		{
			hz=hz+(a[i-1]+1)-a[i];
			a[i]=a[i-1]+1;
		}
	}
	//a[n+1]=1000000000000000000;
//	cout<<hz<<"\n";
	for(i=n;i>=1;i--)
	{
		if(c[i]==a[i])
		{
			break;
		}
		else
		{
			c[i]=max(c[i],c[i+1]+1);
			if(a[i]-c[i]<0)
				break;
			//a[i]=c[i];
			hz=hz-(a[i]-c[i]);
			//cout<<hz<<"\n";
		}
	}
	if(a[i]==c[i+1])
		hz++;
	cout<<hz<<"\n";
}