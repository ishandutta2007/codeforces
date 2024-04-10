#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
long long p[1500], dyn[1500], n, i, j, ans, q;
vector<long long> va, vb;
int main()
{
	q=1000000007;
	cin>>n;
	for(i=1; i<=n; i++)
	{
		cin>>p[i];
	}
	dyn[1]=2;
	for(i=2; j<=n; i++)
	{
		if(p[i]==i)
		{
			dyn[i]=2;
		}
		else
		{
			for(j=p[i]; j<i; j++)
			{
				dyn[i]=(dyn[i]+dyn[j])%q;
			}
			dyn[i]=dyn[i]+2;
		}
	}
	for(i=1; i<=n; i++)
	{
		ans=(ans+dyn[i])%q;
	}
	cout<<ans%q;




	

}