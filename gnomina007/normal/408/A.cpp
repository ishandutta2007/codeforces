#include <iostream>
using namespace std;
long long n, k[105], m[105][105], i, j, s[105], ans;
int main()
{
	cin>>n;
	ans=999999999999999;
	for(i=1; i<=n; i++)
	{
		cin>>k[i];
	}
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=k[i]; j++)
		{
			cin>>m[i][j];
			s[i]=s[i]+m[i][j]*5+15;
		}
		ans=min(ans, s[i]);
	}
	cout<<ans;

}