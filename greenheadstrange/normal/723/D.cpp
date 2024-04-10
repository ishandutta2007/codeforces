#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <queue>
#define maxn 200005
using namespace std;
int n,k,m;
struct lake
{
	int size;
	int pl[2501][2];
	bool operator<(const lake &a)const
	{
		return size>a.size;
	}
};
priority_queue <lake> qq;
int mp[55][55];
bool hv[55][55];
int q[2505][2];
int fr=0,ed=0;
int mv[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

int lks=0;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++)
	{
		getchar();
		for(int j=0;j<m;j++)
		{
			char a;
			scanf("%c",&a);
			if(a=='.') mp[i][j]=1;
			else mp[i][j]=0;
		}
	}
	memset(hv,false,sizeof(hv));
	for(int i=1;i<n-1;i++)
		for(int j=1;j<m-1;j++)
		{
			bool flag=true;
			if(hv[i][j] || !mp[i][j] ) continue;
			fr=0;ed=0;
			q[ed][0]=i,q[ed++][1]=j;
			hv[q[fr][0]][q[fr][1]]=true;
			while(fr<ed)
			{
				for(int l=0;l<4;l++)
				{
					int np[2];
					np[0]=q[fr][0]+mv[l][0];
					np[1]=q[fr][1]+mv[l][1];
					if( (np[0]==n-1 || np[0]==0 || np[1]==m-1 || np[1]==0) &&mp[np[0]][np[1]]) flag=false;
					if(np[0]<n-1 && np[0]>0 && np[1]<m-1 &&np[1]>0 && !hv[np[0]][np[1]] &&mp[np[0]][np[1]])
					{
						hv[np[0]][np[1]]=true;
						q[ed][0]=np[0],q[ed++][1]=np[1];
					}
				}
				fr++;
			}
			if(!flag) continue;
			lake now;
			now.size=ed;
			for(int l=0;l<ed;l++) now.pl[l][0]=q[l][0],now.pl[l][1]=q[l][1];
			qq.push(now);
			lks++;
		}
	int ans=0;
	for(int i=0;i<lks-k;i++)
	{
		lake now=qq.top();
		qq.pop();
		ans+=now.size;
		for(int j=0;j<now.size;j++) mp[now.pl[j][0]][now.pl[j][1]]=0;
	}
	printf("%d\n",ans);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			if(mp[i][j])printf(".");
			else printf("*");
		printf("\n");
	}
		
		
	return 0;
}