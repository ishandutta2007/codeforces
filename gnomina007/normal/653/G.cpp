#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include <cstdio>
#include<cmath>
#include <string>
using namespace std;
vector<int> v[500005];
long long bp(long long a, long long b) 
{
	long long xw=1000000007, lk;
	if(b==0)
	{
		return 1;
	}
	if(b%2==1)
	{
		return ((a*bp(a, b-1))%xw);
	}
	if(b>1)
	{
		if(b%2==0)
		{
			lk=bp(a, b/2);
			return((lk*lk)%xw);
		}
	}
}
long long obr(long long q)
{
	return bp(q, 1000000005);
}
long long n, pq, t[500005], i, j, used[500005], cur, c1, ans, l[500005], ln, fact[500005], obf[500005], c[500005], s[500005], ln1;
int main()
{
	pq=1000000007;
	fact[0]=1;
	obf[0]=1;
	for(i=1; i<500005; i++)
	{
		fact[i]=(fact[i-1]*i)%pq;
		obf[i]=obr(fact[i]);
	}
	cin>>n;
	for(i=0; i<n; i++)
	{
		cin>>t[i];
	}
	//cout<<111;
	for(i=0; i<n; i++)
	{
		cur=t[i];
		for(j=2; j*j<555000; j++)
		{
			c1=0;
			while(cur%j==0)
			{
				cur=cur/j;
				c1++;
			}
			if(c1>0)
			{
			   v[j].push_back(c1);
			}
			if(cur==1)
			{
				j=999999;
			}
		}
		if(cur>1)
		{
			v[cur].push_back(1);
		}
	}
	for(i=2; i<70; i++)
	{
	//	cout<<i<<' '<<v[i].size()<<endl;
	}
	for(j=0; j<n; j++)
	{
		c[j]=fact[n-1];
		c[j]=c[j]*obf[j]%pq;
		c[j]=c[j]*obf[n-1-j]%pq;
		s[j+1]=(c[j]+s[j])%pq;
	}
	//s[n+1]=s[n]+1;
	for(i=2; i<500005; i++)
	{
		if(v[i].size()>0)
		{
			c1=v[i].size();
			for(j=0;j<c1;j++)
			{
				l[j]=v[i][j];
			}
			sort(l, l+c1);
			//reverse(l, l+c1);
			//cout<<i<<endl;
			for(j=0;j<c1;j++)
			{
				//cout<<l[j]<<' ';
			}
			for(j=0; j<=c1-1; j++)
			{
				ln=(s[j+n-c1]-s[(c1-j-1)]+pq)%pq;
				ln=(ln*l[j])%pq;
			//	cout<<ln<<' ';
				ans=(ans+ln)%pq;
			}
			//cout<<endl;
		}
	}
	cout<<ans;
}