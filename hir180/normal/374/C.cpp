//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
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
bool used[1005][1005]={};
bool now[1005][1005]={};
int d[1005][1005];
char f[1005][1005];
int n,m;
int solve(int x,int y)
{
	map<char,char>nxt;
	nxt['D']='I';nxt['I']='M';nxt['M']='A';nxt['A']='D';
	if(d[x][y]) return d[x][y];
	if(now[x][y]) return INF;
	used[x][y]=now[x][y]=true;
	int ret=1;
	int dx[4]={0,1,0,-1};
	int dy[4]={1,0,-1,0};
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i]; int ny=y+dy[i];
		if(!(0<=nx && nx<n)) continue;
		if(!(0<=ny && ny<m)) continue;
		if(f[nx][ny]!=nxt[f[x][y]]) continue;
		ret=max(ret,solve(nx,ny)+1);
	}now[x][y]=false;
	return d[x][y]=ret;
}
int main()
{
	srand((unsigned int)time(NULL));
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%s",&f[i]);
	}
	int ret=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(used[i][j]) continue;
			if(f[i][j]=='D')
			{
				ret=max(ret,solve(i,j));
			}
		}
	}
	if(ret<4) puts("Poor Dima!"); else if(ret<=n*m) printf("%d\n",ret/4);else puts("Poor Inna!");
}