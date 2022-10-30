#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#define MP make_pair
using namespace std;
const int N=11100,inf=1000000000;
typedef pair<int,int> PII;
struct Edge{int y,z,ne;};
int n,m,num,S,T;
int h[N];
Edge e[100000];int last[N];
queue<int> Q;
void add(int x,int y,int z)
{
	e[++num]=(Edge){y,z,last[x]};last[x]=num;
	e[++num]=(Edge){x,0,last[y]};last[y]=num;
}
int bfs()
{
	for (int i=1;i<=T;i++) h[i]=0;
	while (!Q.empty()) Q.pop();
	Q.push(S);h[S]=1;
	while (!Q.empty())
	{
		int now=Q.front();Q.pop();
		for (int j=last[now];j;j=e[j].ne)
		if (e[j].z&&h[e[j].y]==0)
		{
			h[e[j].y]=h[now]+1;
			Q.push(e[j].y);
			if (e[j].y==T) return 1;
		}
	}
	return 0;
}
int dfs(int i,int low)
{
	if (i==T) return low;
	int res=0;
	for (int j=last[i];j;j=e[j].ne)
	if (e[j].z&&h[e[j].y]==h[i]+1)
	{
		int tmp=dfs(e[j].y,min(low,e[j].z));
		res+=tmp,low-=tmp;
		e[j].z-=tmp,e[j^1].z+=tmp;
		if (low==0) break;
	}
	if (res==0) h[i]=-1;
	return res;
}
int chk(int mid)
{
	for (int i=1;i<=n;i++)
	e[i*2].z=mid,e[i*2+1].z=0;
	for (int i=n*2+2;i<=num;i+=2)
	e[i].z+=e[i+1].z,e[i+1].z=0;
	int flow=0;
	while (bfs()) 
	{
		flow+=dfs(S,inf);
	}
	return flow==m;
}
int main()
{
	scanf("%d%d",&n,&m);
	num=1;S=n+m+1,T=S+1;
	for (int i=1;i<=n;i++) add(S,i,0);
	for (int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,i+n,1);
		add(y,i+n,1);
	}
	for (int i=1;i<=m;i++) add(i+n,T,1);
	int l=0,r=5000;
	while (l<r)
	{
		int mid=(l+r)>>1;
		if (chk(mid)) r=mid;else l=mid+1;
	}
	chk(l);
	printf("%d\n",l);
	for (int i=n*2+2;i<n*2+2+m*4;i+=4)
	{
		if (e[i].z==0) printf("%d %d\n",e[i+1].y,e[i+3].y);
		else printf("%d %d\n",e[i+3].y,e[i+1].y);
	}
	return 0;
}