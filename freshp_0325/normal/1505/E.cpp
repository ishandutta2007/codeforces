#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[666][666];
bool vis[666][666];
bool Outside(int x,int y){return x<1 || y<1 || x>n || y>m;}
void dfs(int x,int y)
{
	vis[x][y]=true;
	if(x==n && y==m)	return ;
	int xx=x,yy=y;
	++yy;
	if(Outside(xx,yy))
	{
		--yy;
		++xx;
		dfs(xx,yy);
	}
	else
	{
		if(s[xx][yy]=='*')	dfs(xx,yy);
		else
		{
			--yy;
			++xx;
			if(!Outside(xx,yy) && s[xx][yy]=='*')	dfs(xx,yy);
			else
			{
				++yy,--xx;
				dfs(xx,yy);
			}
		}
	}
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)	scanf("%s",s[i]+1);
	dfs(1,1);
	int ans=0;
	for(int i=1;i<=n;++i)	for(int j=1;j<=m;++j)	ans+=(vis[i][j] && (s[i][j]=='*'));
	printf("%d",ans);
	return 0;
}