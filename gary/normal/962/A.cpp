#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[200005],m=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		m=m+a[i];
	}
	int g=0;
	for(int i=1;i<=n;i++)
	{
		g=g+a[i];
		if(g>=0.5*m)
		{
			cout<<i;return 0;
		}
	}
 }