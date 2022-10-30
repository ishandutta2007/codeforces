#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include <cstdio>
#include<cmath>
#include <string>
using namespace std;
string s;
long long n, m, i, j, cur, a[100005], ans;
int main()
{
	cin>>n;
	cin>>s;
	for(i=0; i<n; i++)
	{
		cin>>a[i];
	}
	cur=0; 
	for(i=0; i<300005; i++)
	{
		if(ans==0)
		{
			if(s[cur]=='>')
			{
				cur=cur+a[cur];
			}
			else
			{
				cur=cur-a[cur];
			}
			if(cur>=n)
			{
				ans++;
			}
			if(cur<0)
			{
				ans++;
			}
		}
	}
	if(ans==0)
	{
		cout<<"INFINITE";
	}
	else
	{
		cout<<"FINITE";
	}
}