#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	int n;
	int ans=0;
	int ans1=-1;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
    for(int i=1;i<=n;i++)
	{
		ans=0;
		if(a[i]==1)
		{
			for(int b=i-1;b>0;b--)
			{
				if(a[b]==0)
				ans++;
			}
			for(int c=i+1;c<=n;c++)
			{
				if(a[c]==1)
				ans++;
			}
		}
		else
		{
			for(int b=i-1;b>0;b--)
			{
				if(a[b]==0)
				ans++;
			}
			for(int c=i+1;c<=n;c++)
			{
				if(a[c]==1)
				ans++;
			}
		}
		ans1=max(ans1,ans);
	 } 
	 cout<<ans1+1;
return 0;
 }