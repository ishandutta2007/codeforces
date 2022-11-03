#include<iostream>
#include<string>
#include<algorithm>
#include<string.h>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
int a[105];
int main()
{
	int n,num,time,p,ans=0;
	cin>>n>>num>>time;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=n;i>0;i--)
	{
		if(n-i<num)
		ans+=time;
		else
		ans+=a[i];
	}
	cout<<ans;
	return 0;
 }