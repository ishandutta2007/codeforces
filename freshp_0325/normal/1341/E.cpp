#include<cstdio>
#include<queue> 
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
bool vis[10005][1005];
int dis[10005][1005],d[10005],m,n,g,r,ans=1008600111;
struct proof{
	int dis,where,now;
	//  
	proof(){dis=0,where=0,now=0;}
	proof(int DIS,int WHERE,int NOW){dis=DIS,where=WHERE,now=NOW;}
	bool operator < (proof another) const {return dis>another.dis;}
};
void Dijkstra()
{
	priority_queue<proof> Q;
	for(int i=1;i<=n;++i)	for(int j=0;j<=1000;++j)	dis[i][j]=1008600111;
	if(d[1]==g)
	{
		dis[1][0]=g+r;
		Q.push(proof(dis[1][0],1,0));
	}
	else
	{
		dis[1][d[1]]=d[1];
		Q.push(proof(dis[1][d[1]],1,d[1]));
	}
	while(!Q.empty())
	{
		proof now=Q.top();
		Q.pop();
		if(vis[now.where][now.now])	continue;
		vis[now.where][now.now]=true;
		if(!now.now && m-d[now.where]<=g)
		{
			ans=min(ans,dis[now.where][now.now]+m-d[now.where]);
			continue;
		}
		if(dis[now.where][now.now]>=ans)	continue;// 
		if(now.where-1)
		{
			int far=d[now.where]-d[now.where-1];
			if(now.now+far<g)
			{
				if(dis[now.where-1][now.now+far]>dis[now.where][now.now]+far)
				{
					dis[now.where-1][now.now+far]=dis[now.where][now.now]+far;
					Q.push(proof(dis[now.where-1][now.now+far],now.where-1,now.now+far));
				}
			}
			else if(now.now+far==g)
			{
				if(dis[now.where-1][0]>dis[now.where][now.now]+far+r)
				{
					dis[now.where-1][0]=dis[now.where][now.now]+far+r;
					Q.push(proof(dis[now.where-1][0],now.where-1,0));
				}
			}
		}
		if(now.where-n)
		{
			int far=d[now.where+1]-d[now.where];
			if(now.now+far<g)
			{
				if(dis[now.where+1][now.now+far]>dis[now.where][now.now]+far)
				{
					dis[now.where+1][now.now+far]=dis[now.where][now.now]+far;
					Q.push(proof(dis[now.where+1][now.now+far],now.where+1,now.now+far));
				}
			}
			else if(now.now+far==g)
			{
				if(dis[now.where+1][0]>dis[now.where][now.now]+far+r)
				{
					dis[now.where+1][0]=dis[now.where][now.now]+far+r;
					Q.push(proof(dis[now.where+1][0],now.where+1,0));
				}
			}
		}
	}
}
int main(){
	scanf("%d %d",&m,&n);
	for(int i=1;i<=n;++i)	scanf("%d",&d[i]);
	sort(d+1,d+1+n);
	scanf("%d %d",&g,&r);
	if(m<=r)	return printf("%d",m)&0;
	if(d[1]>g)	return printf("-1")&0;
	Dijkstra();
	printf("%d",ans==1008600111?-1:ans); 
	return 0;
}