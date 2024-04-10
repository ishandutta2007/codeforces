#include<bits/stdc++.h>

using namespace std;
int a[105];
int b[105];
int main()
{
	int n1,p;
	long long ans=2000,ans1=0,check=0;
	cin>>n1;
	int n=n1*2;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j]<a[j+1])
			{
			p=a[j];
			a[j]=a[j+1];
			a[j+1]=p;
	        }
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			ans1=0;
			check=1;
			memset(b,0,sizeof(b));
			if(i==j)
			continue;
			for(int x=1;x<=n;x++)
			{
				if(x==i||x==j)
				continue;
				b[check]=a[x];
				check++;
			}
			for(int y=1;y<n-2;y=y+2)
			{
				ans1=ans1+abs(b[y+1]-b[y]);
			}
			ans=min(ans,ans1);
			
		}
	}
	cout<<ans;
	return 0;
 }