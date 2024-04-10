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
long long n, m, bx, by, uy[11], ux[11], i, s1, s2, x, a[10], b[10], h1, h2, sum, a1, a2;
int main()
{
	for(i=0; i<5; i++)
	{
		cin>>a[i];
	}
	for(i=0; i<5; i++)
	{
		cin>>b[i];
	}
	cin>>h1>>h2;
	for(i=0; i<5; i++)
	{
		a1=(150*(i+1));
		a2=((250-a[i])*2*(i+1))-50*b[i];
		//cout<<max(a1, a2)<<endl;
		sum=sum+max(a1, a2);
	}
	sum=sum+100*h1-50*h2;
	cout<<sum;
}