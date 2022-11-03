#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
int a[555];
int p=0;
bool check1(int x)
{
	for(int i=0;i<p;i++)
	{
		if(x==a[i])
		return false;
	}
	return true;
}
int main()
{
	string s;
	int n,ans=0,ans1=0,check=0;
	cin>>n;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]>='a' and s[i]<='z')
		{
			if(check1(s[i])==true)
			{
			ans1++;
			a[p]=s[i];
			p++;
		    }
			ans=max(ans,ans1);
			check++;
		}
		else
		{
		ans1=0;
		check=0;
		memset(a,0,sizeof(a));
		p=0;
	    }
	}
	cout<<ans;
	return 0;
}