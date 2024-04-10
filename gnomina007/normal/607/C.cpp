#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include <cstdio>
#include<cmath>
#include<string>
using namespace std;
long long n,i, j, a[1000005], b[1000005], otkat[1000005], prf[1000005], c[2000010], lok;
string s, s1, s2;
int main()
{
	cin>>n;
	cin>>s1;
	cin>>s2;
	for(i=0; i<n-1; i++)
	{
	//	cout<<1;
		if(s1[n-2-i]=='N')
		{
			a[i]=1;
		}
		if(s1[n-2-i]=='S')
		{
			a[i]=2;
		}
		if(s1[n-2-i]=='E')
		{
			a[i]=3;
		}
		if(s1[n-2-i]=='W')
		{
			a[i]=4;
		}
		if(s2[i]=='S')
		{
			b[i]=1;
		}
		if(s2[i]=='N')
		{
			b[i]=2;
		}
		if(s2[i]=='W')
		{
			b[i]=3;
		}
		if(s2[i]=='E')
		{
			b[i]=4;
		}
	}
	for(i=0; i<n-1; i++)
	{
		c[i]=a[i];
	}
	c[n-1]=999;
	for(i=0; i<n-1; i++)
	{
		c[n+i]=b[i];
	}
	for(i=0; i<2*n-1; i++)
	{
		//cout<<c[i]<<' ';
	}
	cout<<endl;
	prf[0]=0;
	for(i=1; i<2*n-1; i++)
	{
		lok=prf[i-1];
		while((c[i]!=c[lok])&&(lok>0))
		{
			lok=prf[lok-1];
		}
		if(lok==0)
		{
			if(c[i]==c[0])
			{
				prf[i]=1;
			}
			else
			{
				prf[i]=0;
			}
		}
		else
		{
			prf[i]=lok+1;
		}
	}
	for(i=0; i<=2*n-2; i++)
	{
	//	cout<<prf[i]<<' ';
	}
	if(prf[2*n-2]>0)
	{
		cout<<"NO";
	}
	else
	{
		cout<<"YES";
	}
}