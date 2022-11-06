#include<bits/stdc++.h>
using namespace std;
long long n,k,i,c,a[10101010];
bool b; 
int main()
{

	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=k;i++)
	{
		cin>>c;
	}
	if(k>1)
	{
		cout<<"YES\n";
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				a[i]=c;
			}
		}
		b=1;
		for(i=1;i<n;i++)
		{
			if(a[i]>=a[i+1])
			{
				b=0;
				break;
			}
		}
		if(b)	cout<<"NO\n";
		else	cout<<"YES\n";
	}
}