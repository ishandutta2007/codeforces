//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
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
#define s(x) scanf("%d",&x)
#define rep(i,x) for(int i=0;i<x;i++)
int dp[45][45][45][45]={};
int rui[45][45]={};
int n,m,q;
int f[45][45];
char s[45][45];
int main()
{
	scanf("%d %d %d",&n,&m,&q);
	for(int i=0;i<n;i++)
	{
		scanf("%s",&s[i]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			f[i+1][j+1]=s[i][j]-'0';
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			rui[i][j]=rui[i-1][j]+rui[i][j-1]-rui[i-1][j-1]+f[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=i;k<=n;k++)
			{
				for(int l=j;l<=m;l++)
				{
					dp[i][j][k][l]+=dp[i][j][k][l-1];
					dp[i][j][k][l]+=dp[i][j][k-1][l];
					dp[i][j][k][l]-=dp[i][j][k-1][l-1];
					for(int x=i;x<=k;x++)
					{
						for(int y=j;y<=l;y++)
						{
							if(rui[k][l]-rui[k][y-1]-rui[x-1][l]+rui[x-1][y-1]==0)
							{
								dp[i][j][k][l]++;
							}
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x1,y1,x2,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		printf("%d\n",dp[x1][y1][x2][y2]);
	}
}