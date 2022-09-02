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
char f[505][505];
bool ok[505][505]={};
int main()
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<n;i++)
	{
			scanf("%s",&f[i]);
	}
	if(!k)
	{
			for(int i=0;i<n;i++) printf("%s\n",f[i]);
			return 0;
	}
	int cur=0;
	queue<P>que;
	int emptyc=0;
	for(int i=0;i<n;i++)
	{
			for(int j=0;j<m;j++)
			{
				if(f[i][j]=='.')
				{
					if(que.empty()) que.push(mp(i,j));
					emptyc++;
				}
			}
	}
	
	while(!que.empty())
	{
		P p=que.front(); que.pop();
		if(ok[p.first][p.second]) continue;
		ok[p.first][p.second]=true;
		cur++;
		if(cur==emptyc-k)
		{	
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					if(!ok[i][j] && f[i][j]=='.') f[i][j]='X';
				}
			}
			for(int i=0;i<n;i++) printf("%s\n",f[i]);
			return 0;
		}
		int dx[4]={0,1,0,-1};
		int dy[4]={1,0,-1,0};
		for(int i=0;i<4;i++)
		{
				int nx=p.first+dx[i];
				int ny=p.second+dy[i];
				if(!(0<=nx && nx<n)) continue;
				if(!(0<=ny && ny<m)) continue;
				if(!ok[nx][ny] && f[nx][ny]=='.')
				{
					que.push(mp(nx,ny));
				}
		}
	}
}