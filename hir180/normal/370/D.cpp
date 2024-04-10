//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
//HIR180
//IOI2014N
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
#define f first
#define s second
#define rep(i,x) for(int i=0;i<x;i++)
int rui[2005][2005]={},n,m;
char f[2005][2005];
int main()
{
	srand((unsigned int)time(NULL));
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%s",&f[i]);
	int lx=INF,ly=INF,rx=-INF,ry=-INF;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(i) rui[i][j]+=rui[i-1][j];
			if(j) rui[i][j]+=rui[i][j-1];
			if(i&&j) rui[i][j]-=rui[i-1][j-1];
			rui[i][j]+=(f[i][j]=='w');
			if(f[i][j]=='w')
			{
				lx=min(i,lx);
				ly=min(j,ly);
				rx=max(i,rx);
				ry=max(j,ry);
			}
		}
	}
	int unit=max(rx-lx,ry-ly)+1; 
	if(unit==1)
	{
		for(int i=0;i<n;i++) printf("%s\n",f[i]);
		return 0;
	}
	for(int i=0;i<=n-unit;i++)
	{
		for(int j=0;j<=m-unit;j++)
		{
			int x=rui[i+unit-1][j+unit-1]-rui[i-1][j+unit-1]-rui[i+unit-1][j-1]+rui[i-1][j-1];
			int y=rui[i+unit-2][j+unit-2]-rui[i][j+unit-2]-rui[i+unit-2][j]+rui[i][j];
			if(x-y==rui[n-1][m-1])
			{
				for(int k=j;k<=j+unit-1;k++)
				{
					if(f[i][k]!='w') f[i][k]='+';
					if(f[i+unit-1][k]!='w') f[i+unit-1][k]='+';
				}
				for(int k=i;k<=i+unit-1;k++)
				{
					if(f[k][j]!='w') f[k][j]='+';
					if(f[k][j+unit-1]!='w') f[k][j+unit-1]='+';
				}
				for(int i=0;i<n;i++) printf("%s\n",f[i]);
				return 0;
			}
		}
	}
	puts("-1");
}