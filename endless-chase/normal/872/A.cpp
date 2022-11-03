#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
int a[15];
int b[15];
int main()
{
	int n,m,mn1=100,mn2=100,mn=100,ans;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
	cin>>a[i];
	mn1=min(mn1,a[i]);
}
	for(int i=0;i<m;i++)
	{
	cin>>b[i];
	mn2=min(mn2,b[i]);
}
for(int i=0;i<n;i++)
{
	for(int j=0;j<m;j++)
	{
		if(a[i]==b[j])
		mn=min(mn,a[i]);
	}
}
if(mn1>mn2)
ans=10*mn2+mn1;
else
ans=10*mn1+mn2;
cout<<min(ans,mn);
return 0;
}