#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<cmath>
#include<string.h>
#include<cstdlib>
#define ll long long
#define INF 2e8
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
int n,x;
int odd=1,even=2;

void _odd()
{
	cout<<odd<<" ";
	odd+=2;
}

void _even()
{
	cout<<even<<" ";
	even+=2;
}

int main()
{
	n=read();
	x=n/2;
	for(int i=1;i<=n/2;i++)
	{
		for(int j=1;j<=x;j++)
		{
			_even();
		}
		for(int j=x+1;j<=n-x;j++)
	    {
	    	_odd();
	    }
	    for(int j=n-x+1;j<=n;j++)
	    {
	    	_even();
	    }
		x--;
		cout<<endl;
	}
	for(int i=1;i<=n;i++)
	    _odd();
	cout<<endl;
    x=1;
	for(int i=n/2+2;i<=n;i++)
	{
		for(int j=1;j<=x;j++)
		{
			_even();
		}
		for(int j=x+1;j<=n-x;j++)
	    {
	    	_odd();
	    }
	    for(int j=n-x+1;j<=n;j++)
	    {
	    	_even();
	    }
		x++;
		cout<<endl;
	}
	return 0;
}