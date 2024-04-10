#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 501
#define MAXM 5001
int N,M;pair<int,int>pre[MAXN][MAXM];bool vis[MAXN][MAXM];
void print(int x,int y){if(x||y)print(pre[x][y].first,pre[x][y].second),cout<<y-pre[x][y].second;}
int main()
{
	cin>>N>>M;queue<pair<int,int>>q;q.push({0,0});vis[0][0]=1;
	while(!q.empty())
	{
		int x=q.front().first,y=q.front().second;q.pop();
		For(i,0,9)if(y+i<=M&&!vis[(x*10+i)%N][y+i])vis[(x*10+i)%N][y+i]=1,pre[(x*10+i)%N][y+i]={x,y},q.push({(x*10+i)%N,y+i});
	}
	if(!vis[0][M])cout<<"-1\n";else print(0,M);return 0;
}