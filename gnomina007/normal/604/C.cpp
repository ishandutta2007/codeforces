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
long long n, m, k, s[100005], t, i, ans, j, x[100005], a;
string ss;
int main()
{
	cin>>n;
	cin>>ss;
	x[0]=0;
	t=1;
	for(i=1; i<n; i++)
	{
		if(ss[i]!=ss[i-1])
		{
			x[t]=i;
			t++;
		}
	}
	x[t]=n;
	for(i=0; i<t; i++)
	{
		if((x[i+1]-x[i])>1)
		{
			a++;
		}
	}
	if(t==n)
	{
		cout<<t;
	}
	if(t==(n-1))
	{
		cout<<t+1;
	}
	if(t<n-1)
	{
		cout<<t+2;
	}


}