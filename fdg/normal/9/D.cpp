#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <cmath>

#define dat cin
#define sol cout

using namespace std;

long long ans=0,n,h,D[50][50][50]={0};

long long rec(long l,long r,int curh)
{
	if (D[l][r][curh]!=-1) return D[l][r][curh];
	if (l==r)
	{
		if (curh==1) D[l][r][curh]=1;
		else D[l][r][curh]=0;
		return D[l][r][curh];
	}
	D[l][r][curh]=0;
	for(int i=l;i<=r;i++)
	{
		long long a=0,b=0;
		for(int j=1;j<=curh-1;j++)
		{
			if (D[l][i-1][j]==-1) D[l][i-1][j]=rec(l,i-1,j);
			if (j<=i-l) a+=D[l][i-1][j];
		}
		for(int j=1;j<=curh-1;j++)
		{
			if (D[i+1][r][j]==-1) D[i+1][r][j]=rec(i+1,r,j);
			if (j<=r-i) b+=D[i+1][r][j];
		}
		if (i==l) a=1;
		if (i==r) b=1;
		D[l][r][curh]+=a*D[i+1][r][curh-1]+b*D[l][i-1][curh-1]-D[i+1][r][curh-1]*D[l][i-1][curh-1];
	}
	return D[l][r][curh];
}


int main()
{
	dat >> n >> h;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int t=1;t<=n;t++)
				D[i][j][t]=-1;
	for(int i=h;i<=n;i++)
		ans+=rec(1,n,i);
	sol << ans << endl;
	return 0;
}