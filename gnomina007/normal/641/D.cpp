#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include <cstdio>
#include<cmath>
#include <string>
using namespace std;
string s;
long long n, m, i, j, cur, a[200005], ans;
long double ma[100005], mi[100005], sa[100005], si[100005], d[100005], ssa[100005], ssb[100005], dis;
int main()
{
	cin>>n;
	for(i=1; i<=n; i++)
	{
		cin>>ma[i];
		sa[i]=sa[i-1]+ma[i];
	}
	for(i=1; i<=n; i++)
	{
		cin>>mi[i];
		si[i]=si[i-1]+mi[i];
		d[i]=d[i-1]+mi[i]+ma[i];
	}
	for(i=1; i<=n; i++)
	{
		dis=sqrt(d[i]*d[i]-4*sa[i]+0.00000000000001);
		ssa[i]=(d[i]+dis)/2;
		ssb[i]=(d[i]-dis)/2;
	}
	cout.precision(15);
	for(i=1; i<=n; i++)
	{
		cout<<(ssa[i]-ssa[i-1])<<' ';
	}
	cout<<endl;
	for(i=1; i<=n; i++)
	{
		cout<<(ssb[i]-ssb[i-1])<<' ';
	}
}