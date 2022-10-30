#include <iostream>;
#include <cmath>;
#include <vector>;
#include <stdio.h>;
#include <algorithm>;
#include <string>;
#include <set>;
using namespace std;
long long ans(long long n)
{
	if(n<=1)
	{
		return 1;
	}
	else
	{
		long long x=ans(n/2);
		return(2*x+1);
	}
}
long long karma(long long n)
{
	if(n<=1)
	{
		return n;
	}
	else
	{
		long long x=karma(n/2);
		return(2*x+n%2);
	}
}
long long solve(long long n, long long x)
{
	if(n==0)
	{
		return 0;
	}
	if(n==1)
	{
		return 1;
	}
	if(n>=2)
	{
		long long y=ans(n/2);
		if(x<=y)
		{
			return solve(n/2, x);
		}
		if(x==y+1)
		{
			return karma(n/2)+n%2;
		}
		if(x>y+1)
		{
			return solve(n/2, x-y-1)+karma(n/2)+n%2;
		}
	}
}
long long n, i, j, a[105], c1, c2,l, r, b[105], cur, t;
int main()
{
	cin>>n>>l>>r;
	c1=solve(n, r);
	if(l!=1)
	{
	   c2=solve(n, l-1);
	}
	//cout<<c1<<' '<<c2<<endl;
	cout<<c1-c2;
}