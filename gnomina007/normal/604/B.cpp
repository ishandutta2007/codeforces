#include<iostream>
#include<vector>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
long long  st(long long a, long long b)
{
	int x;
	if(b==0)
	{
		return 1;
	}
	else
	{
		x=st(a, b-1);
		x=(x*a);
		return x;
	}
}
long long n, m, k, s[100005], t, i, ans, j;
int main()
{
	cin>>n>>k;
	for(i=0; i<n; i++)
	{
		cin>>s[i];
	}
	ans=s[n-1];
	t=n-k;
	if(t>0)
	{
		for(j=0; j<t; j++)
		{
			ans=max(ans, (s[j]+s[2*t-1-j]));
		}
	}
	cout<<ans;
}