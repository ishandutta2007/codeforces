#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int col[1005][1005],v[2],n,m;
int dx[]={1,-1,2,-2,1,-1,2,-2},dy[]={2,2,1,1,-2,-2,-1,-1};
void dfs(int x,int y,int z)
{
	if(x<1||x>n||y>m||y<1)return;
	if(col[x][y]!=-1)return;
	col[x][y]=z;v[z]++;
	for(int i=0;i<8;i++)dfs(x+dx[i],y+dy[i],z^1);
}
signed main(){
	memset(col,-1,sizeof(col));
	n=read(),m=read();
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(col[i][j]!=-1)continue;
			dfs(i,j,0);
			ans+=max(v[0],v[1]);
			v[0]=v[1]=0;
		}
	}
	cout<<ans<<'\n';
	return 0;
}