
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
long long n, m, i, u[405][405], x, y, j, och[500], lb, rb, used[405], cur, dist[405], pol[405];
int main()
{
	cin>>n>>m;
	for(i=0; i<m; i++)
	{
		cin>>x>>y;
		u[x][y]=1;
		u[y][x]=1;
	}
	for(i=1; i<=n; i++)
	{
		u[i][i]=-1;
		dist[i]=999999;
	}
	if(u[1][n]==1)
	{
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				if(i!=j)
				{
					u[i][j]=1-u[i][j];
				}
			}
		}
	}
	och[0]=1;
	lb=0; 
	rb=1;
	pol[1]=1;
	dist[1]=0;
	for(i=0; i<n; i++)
	{
		if(lb!=rb)
		{
		cur=och[lb]; 
		lb++;
		used[cur]=1;
		for(j=1; j<=n; j++)
		{
			if(u[cur][j]==1)
			{
				//cout<<cur<<' '<<j<<endl;
				if(pol[j]==0)
				{
					pol[j]=1;
					och[rb]=j;
					rb++;
					dist[j]=min(dist[j], dist[cur]+1);
				}
			}
		}	
		}
	}
	if(dist[n]==999999)
	{
		dist[n]=-1;
	}
	cout<<dist[n];
}