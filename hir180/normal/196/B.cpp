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
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
char f[1505][1505];
bool used[1505][1505];
int pre[1505][1505][2];
int h,w,dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
bool dfs(int x,int y)
{
	int nx=((x%h)+h)%h;
	int ny=((y%w)+w)%w;
	if(f[nx][ny]=='#') return 0;
	int &zx=pre[nx][ny][0];
	int &zy=pre[nx][ny][1];
	if(used[nx][ny]) return mp(zx,zy)!=mp(x,y);
	zx=x,zy=y,used[nx][ny]=true;
	for(int i=0;i<4;i++)
	{
		if(dfs(x+dx[i],y+dy[i]))return 1;
	}
	return 0;
}
int main()
{
	srand((unsigned int)time(NULL));
	scanf("%d %d",&h,&w);
	for(int i=0;i<h;i++)
	{
		scanf("%s",&f[i]);
	}
	int sx,sy;bool ok=false;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(f[i][j] == 'S')
			{
				ok=dfs(i,j);
			}
		}
	}
	puts(ok?"YES":"NO");
}