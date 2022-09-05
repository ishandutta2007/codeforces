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
const int INF=1<<28;
int testn,n,a[111],b[111];
bool vis[111];
bool can(int x,int y)
{
	if(a[y]<a[x]&&a[x]<b[y]||a[y]<b[x]&&b[x]<b[y])return true;
	return false;
}
bool dfs(int start,int end)
{
	if(vis[start])return false;
	vis[start]=1;
	if(start==end)return true;
	for(int i=1;i<=n;i++)
	{
		if(can(start,i)&&dfs(i,end))
		{
			return true;
		}
	}
	return false;
}
int main()
{
	scanf("%d",&testn);
	while(testn--)
	{
		int o,x,y;
		scanf("%d%d%d",&o,&x,&y);
		if(o==1)
		{
			n++;
			a[n]=x;b[n]=y;
		}
		else if(o==2)
		{
			memset(vis,0,sizeof(vis));
			if(dfs(x,y))puts("YES");else puts("NO");
		}
	}
// 	system("pause");
	return 0;
}