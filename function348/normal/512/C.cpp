#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
const int N=210;
struct Edge {int y,z,ne;};
int n,num,S,T,cnt;
int h[N];
Edge e[N*N*2];int last[N];
queue <int> Q;
int b[N][N];
int a[N],v[N*N*2];
void add(int x,int y,int z) 
{ 
	e[++num]=(Edge){y,z,last[x]};last[x]=num;
	e[++num]=(Edge){x,0,last[y]};last[y]=num;
}
int bfs()
{
	for (int i=1;i<=T;i++) h[i]=0;
	while (!Q.empty()) Q.pop();
	h[S]=1;
	Q.push(S);
	while (!Q.empty())
	{
		int now=Q.front();Q.pop();
		for (int j=last[now];j;j=e[j].ne)
		if (h[e[j].y]==0&&e[j].z)
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
	if (h[e[j].y]==h[i]+1&&e[j].z)
	{
		int tmp=dfs(e[j].y,min(low,e[j].z));
		res+=tmp;low-=tmp;
		e[j].z-=tmp;e[j^1].z+=tmp;
		if (low==0) break;
	}
	if (low==0) h[i]=-1;
	return res;
}
void dfs1(int i)
{
	if (h[i]==-1) return;
	h[i]=-1;
	b[cnt][0]++;
	b[cnt][ b[cnt][0] ]=i;
	for (int j=last[i];j;j=e[j].ne)
	{
		if (a[i]&1)
		{
			if (e[j].z==0) dfs1(e[j].y);
		}
		else
		{
			if (e[j].z==1) dfs1(e[j].y);
		}
	}
}
int main()
{
	scanf("%d",&n);
	S=n+1,T=n+2;num=1;
	if (n&1) { printf("Impossible\n");return 0;}
	cnt=0;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) cnt+=a[i]&1;
	if (cnt!=n/2) { printf("Impossible\n");return 0;}
	for (int i=2;i<=20000;i++)
	{
		v[i]=1;
		for (int j=2;j*j<=i;j++)
		if (i%j==0) { v[i]=0;break;}
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	if (v[a[i]+a[j]]&&a[i]%2==1&&a[j]%2==0) add(i,j,1);
	for (int i=1;i<=n;i++) 
	if (a[i]%2==1) add(S,i,2);else add(i,T,2);
	int flow=0;
	while (bfs()) 
	flow+=dfs(S,100000);
	if (flow!=n) { printf("Impossible\n");return 0;}
	for (int i=1;i<=n;i++) h[i]=0;
	cnt=0;
	h[S]=h[T]=-1;
	for (int i=1;i<=n;i++)
	if (h[i]==0) 
	{
		cnt++;
		dfs1(i);
	}
	printf("%d\n",cnt);
	for (int i=1;i<=cnt;i++)
	{
		printf("%d ",b[i][0]);
		for (int j=1;j<=b[i][0];j++) printf("%d%c",b[i][j],j<b[i][0]?' ':'\n');
	}
	return 0;
}