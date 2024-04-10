#include<iostream>
#include<list>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
#pragma comment(linker, "/STACK:367721060")
using namespace std;
int l[600][600];
int n;
int m;
int k;
bool used[600][600];
bool check(int x,int y)
{
	return ((x>=0) && (y>=0) && (x<n) && (y<m));
}

void dfs(int x,int y)
{
	used[x][y]=true;
	if(check(x+1,y)&&!used[x+1][y]&& l[x+1][y]==0)
		dfs(x+1,y);
	if(check(x-1,y)&&!used[x-1][y]&& l[x-1][y]==0)
		dfs(x-1,y);
	if(check(x,y+1)&&!used[x][y+1]&& l[x][y+1]==0)
		dfs(x,y+1);
	if(check(x,y-1)&&!used[x][y-1]&& l[x][y-1]==0)
		dfs(x,y-1);
	if(k>0)
	{
		l[x][y]=2;
		k--;
	}
}
int main()
{
std::ios::sync_with_stdio(0);

cin>>n>>m>>k;
for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	{
		char c;
		cin>>c;
		if(c=='#')
			l[i][j]=1;
	}
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	{
			if(l[i][j]==0)
			{
				dfs(i,j);
			}
	}
for(int i=0;i<n;i++)
{
	for(int j=0;j<m;j++)
	{
	
			if(l[i][j]==0)
				cout<<'.';
			if(l[i][j]==1)
				cout<<'#';
			if(l[i][j]==2)
				cout<<'X';
	}
	cout<<endl;
}
return 0;
}