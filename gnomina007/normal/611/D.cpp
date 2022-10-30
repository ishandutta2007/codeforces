#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include <cstdio>
#include<cmath>
#include <string>
using namespace std;
int n, p, a[5005], s[5005][5005], dyn[5005][5005], i, lvl[5005][5005], k, b[5005], j, td, xx, yy, xx1, yy1, kt;
string t;
int main()
{
	p=1000000007;
	cin>>n;
	cin>>t;
	for(i=0; i<n; i++)
	{
		a[i+1]=t[i]-'0';
	}
	for(i=1; i<=n; i++)
	{
		lvl[i][i]=a[i];
	}
	for(k=1; k<=n; k++)
	{
		for(i=1; i+k<=n; i++)
		{
			lvl[i][i+k]=10*lvl[i][i+k-1]+(a[i+k]);
			if(k==1)
			{
				//cout<<i<<' '<<lvl[i][i+k]<<endl;
			}
		}
		for(j=0; j<n-k; j++)
		{
			b[j]=10000*lvl[j+1][j+k+1]+j+1;
			if(k==1)
			{
			//	cout<<j<<' '<<b[j]<<endl;
			}
		}
		sort(b, b+n-k);
		for(j=0; j<n-k; j++)
		{
		//	cout<<b[j]<<endl;
		}
		td=1;
		for(j=0; j<n-k; j++)
		{
			xx1=b[j]/10000;
			yy1=b[j]%10000;
			if(j>0)
			{
				if(xx1>xx)
				{
					td++;
				}
			}
			lvl[yy1][yy1+k]=td;
			xx=xx1;
			yy=yy1;
		}
	}
	for(i=0; i<=n; i++)
	{
		for(j=1; j+i<=n; j++)
		{
			//cout<<j<<' '<<j+i<<' '<<lvl[j][j+i]<<endl;
		}
	}
	for(i=1; i<=n; i++)
	{
		dyn[1][i]=1;
		s[i][1]=1;
	}
	for(i=2; i<=n; i++)
	{
		for(j=2; j<=i; j++)
		{
			kt=2*j-i;
			if(kt<1)
			{
				kt=1;
			}
			if(kt>1)
			{
				if(lvl[kt-1][j-1]<lvl[j][i])
				{
					kt--;
				}
			}
			if(i==3)
			{
				if(j==3)
				{
				//	cout<<kt<<endl;
				}
			}
			if(a[j]==0)
			{
				dyn[j][i]=0;
			}
			else
			{
				dyn[j][i]=(s[j-1][j-1]-s[j-1][kt-1]+p)%p;
			}
		}
		for(j=2; j<=i; j++)
		{
			s[i][j]=(s[i][j-1]+dyn[j][i])%p;
		}
	}
	//cout<<dyn[3][3]<<endl;
	cout<<s[n][n];
}