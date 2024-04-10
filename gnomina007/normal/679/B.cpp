#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include <cstdio>
#include<cmath>
#include <string>
using namespace std;
pair<long long, long long> xe;
long long n, m,  wp, dp, cp, last[100005], dyn[100005], mx[100005], pos[100005], i, j, sq[100005], rq[100005], ma, sql;
long long bp(long long xm)
{
	long long lb, rb, mid, i1;
	if(xm<99000)
	{
		return sq[xm];
	}
	else
	{
		lb=2; 
		rb=200009;
		for(i1=0; i1<50; i1++)
		{
			mid=(rb+lb+i1%2)/2;
			if(mid*mid*mid<=xm)
			{
				lb=mid;
			}
			else
			{
				rb=mid;
			}
		}
		return lb;
	}
}
pair<long long, long long> ans(long long t)
{
	sql++;
	if(sql<20)
	{
///	cout<<t<<endl;
	}
	long long f1, f2, f3, a1, a2, a3, b1, b2, b3;
	pair<long long, long long> rt, ry;
	if(t<98000)
	{
		return(make_pair(mx[t], pos[t]));
	}
	else
	{
		f1=bp(t);
		f2=f1*f1*f1;
		f3=(f1-1)*(f1-1)*(f1-1);
		rt=ans(t-f2);
		ry=ans(f2-f3-1);
		a1=rt.first;
		a2=rt.second;
		b1=ry.first;
		b2=ry.second;
		if(b1>a1)
		{
			return make_pair(b1+1, b2+f3);
		}
		else
		{
			return make_pair(a1+1, a2+f2);
		}
	}
}
int main()
{
	cin>>m;
	sq[1]=1;
	for(i=2; i<100002; i++)
	{
		if((sq[i-1]+1)*(sq[i-1]+1)*(sq[i-1]+1)==i)
		{
			sq[i]=sq[i-1]+1;
		}
		else
		{
			sq[i]=sq[i-1];
		}
	}
	for(i=1; i<100002; i++)
	{
		rq[i]=sq[i]*sq[i]*sq[i];
	}
	dyn[1]=1;
	mx[1]=1;
	pos[1]=1;
	for(i=2; i<100000; i++)
	{
		dyn[i]=dyn[i-rq[i]]+1;
		if(dyn[i]<mx[i-1])
		{
			mx[i]=mx[i-1];
			pos[i]=pos[i-1];
		}
		else
		{
			mx[i]=dyn[i];
			pos[i]=i;
		}
	}
	xe=ans(m);
	cout<<xe.first<<' '<<xe.second;
}