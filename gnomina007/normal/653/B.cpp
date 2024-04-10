#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include <cstdio>
#include<cmath>
#include <string>
using namespace std;
long long n, t[100], i, j, k, ans, cur, q, dyn[10][10];
string s[40];
char tq, io[40];
int main()
{
	cin>>n>>q;
	dyn[0][0]=1;
	for(i=0; i<q; i++)
	{
		cin>>s[i]>>io[i];
	}
	for(i=1; i<n; i++)
	{
		for(k=0; k<q; k++)
		{
			tq=s[k][0];
		//	cout<<tq<<endl;
			dyn[i][tq-'a']=dyn[i][tq-'a']+dyn[i-1][io[k]-'a'];
		}
	}
	//cout<<dyn[1][0];
	for(i=0; i<6; i++)
	{
		ans=ans+dyn[n-1][i];
	}
	cout<<ans;
}