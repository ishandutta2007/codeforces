#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
int a[100005];
int main()
{
	int n,bnum=0,snum=0,mx=-1,mn=1000000005;
	cin>>n;
	int ans=n;
	for(int i=1;i<=n;i++)
    {
	cin>>a[i];
	mx=max(mx,a[i]);
	mn=min(mn,a[i]);
    }
	for(int i=1;i<=n;i++)
	{
		if(a[i]==mx or a[i]==mn)
		ans--;
	}
	cout<<ans;
	return 0;
}