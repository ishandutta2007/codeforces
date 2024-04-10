#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include <cstdio>
#include<cmath>
#include <string>
using namespace std;
vector<int> v[100005];
long long i, j, x, ans, cur, n, k, m, a[100005], b[100005], way[100005], lvl[100005], och[300005], lb, rb, sum, obr[100005];
int main()
{
	cin>>n>>m;
	for(i=0; i<m; i++)
	{
		cin>>a[i]>>b[i];
		lvl[a[i]]++;
		v[b[i]].push_back(a[i]);
	}
	lb=0; rb=0;
	for(i=1; i<=n; i++)
	{
		if(lvl[i]==0)
		{
			och[rb]=i;
			rb++;
		}
	}
	while(rb>lb)
	{
		x=och[lb];
		for(i=0; i<v[x].size(); i++)
		{
			way[v[x][i]]=max(way[v[x][i]], way[x]+1);
			lvl[v[x][i]]--;
			if(lvl[v[x][i]]==0)
			{
				och[rb]=v[x][i];
				rb++;
			}
		}
		lb++;
	}
	for(i=1; i<=n; i++)
	{
		sum=sum+way[i];
	}
	if(sum<((n*(n-1))/2))
	{
		cout<<-1;
	}
	else
	{
		for(i=0; i<m; i++)
		{
			if((way[a[i]]-way[b[i]])==1)
			{
				cur++;
				if(cur==(n-1))
				{
					ans=i;
				}
			}
		}
		cout<<ans+1;
	}
}