#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int f[4567],ans;

int main()
{
	int n,k,t,d;
	
	cin >> n >> k;
	if (n==k)
	{
		puts("86400");
		return 0;
	}
	
	for (int i=0;i<n;i++)
	{
		cin >> t >> d;
		for (int j=k;j>=0;j--)
		{
			if (t<=f[j]) f[j]+=d;
			else ans=max(ans,t-f[j]-1), f[j]=t+d-1;
			if (j) f[j]=min(f[j],f[j-1]);
		}
	}
	
	for (int i=0;i<=k;i++) ans=max(ans,86400-f[i]);
	
	cout << ans << endl;
}