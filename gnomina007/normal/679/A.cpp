#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include <cstdio>
#include<cmath>
#include <string>
using namespace std;
pair<long long, long long> xe;
long long n, m, q, a[100], sum, i;
string t;
int main()
{
	a[1]=2;
	a[2]=3;
	a[3]=5;
	a[4]=7;
	a[5]=11;
	a[6]=13;
	a[7]=17;
	a[8]=19;
	a[9]=23;
	a[10]=29;
	a[11]=31;
	a[12]=37;
	a[13]=41;
	a[14]=43;
	a[15]=47;
	a[16]=4;
	a[17]=9;
	a[18]=25;
	a[19]=49;
	for(i=1; i<=19; i++)
	{
		cout<<a[i]<<endl;
		fflush(stdout);
		cin>>t;
		if(t[0]=='y')
		{
			sum++;
		}
	}
	if(sum<2)
	{
		cout<<"prime";
	}
	else
	{
		cout<<"composite";
	}
	fflush(stdout);
}