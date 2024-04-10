#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
#define pb push_back 
#define mp make_pair
int n,m,row[55][55],col[55][55];
bool a[55][55];
bool fun(int i,int j,int x,int y)
{
	return (i==x)?(row[i][j-1]==row[i][y]):(col[i-1][j]==col[x][j]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		cin.ignore();
		for(int j=1;j<=m;j++)
		{
			char c;
			scanf("%c",&c);
			a[i][j]=(c=='B')?1:0;
			row[i][j]=row[i][j-1]+(c=='W');
			col[i][j]=col[i-1][j]+(c=='W');
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int x=1;x<=n;x++)
			{
				for(int y=1;y<=m;y++)
				{
					if(a[i][j]&&a[x][y])
					{
						if(fun(i,j,i,y)&&fun(i,y,x,y))continue;
						if(fun(i,j,x,j)&&fun(x,j,x,y))continue;
						puts("NO");
						return 0;
					}
				}
			}
		}
	}
	puts("YES");
	return 0;
}