#include<cstdio>
#include<iostream>
#include<set>
#include<queue>
#include<map>
#include<vector>
#include<cstring>
#include<algorithm>
#define fr first
#define sc second
#define MP make_pair
using namespace std;
void upmax(int &a,int b) { if (a<b) a=b;}
void upmin(int &a,int b) { if (a>b) a=b;}
typedef long long LL;
typedef pair<int,int> PII;
//---------------------------------
struct Edge{int y,z,ne;};
const int N=10101,inf=1<<30;
int n,m,k,cas,S,T,num;
Edge e[N];int last[N];
int h[N],d[N],ans[N];
queue<int> Q;
void add(int x,int y,int z)
{
	e[++num]=(Edge){y,z,last[x]};last[x]=num;
	e[++num]=(Edge){x,0,last[y]};last[y]=num;
}
int bfs()
{
	for (int i=1;i<=T;i++) h[i]=-1;
	while (!Q.empty()) Q.pop();
	Q.push(S);h[S]=0;
	while (!Q.empty())
	{
		int i=Q.front();Q.pop();
		for (int j=last[i];j;j=e[j].ne)
		if (h[e[j].y]==-1&&e[j].z)
		{
			h[e[j].y]=h[i]+1;
			if (e[j].y==T) return 1;
			Q.push(e[j].y);
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
		e[j].z-=tmp;e[j^1].z+=tmp;
		res+=tmp;low-=tmp;
		if (low==0) break;
	}
	if (res==0) h[i]=-1;
	return res;
}
int main()
{
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d%d%d",&n,&m,&k);
		S=n+m+1,T=S+1,num=1;
		for (int i=1;i<=T;i++) last[i]=d[i]=0;
		for (int i=1;i<=m;i++) 
		{
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,i+n,1);add(y,i+n,1);
			add(i+n,T,1);
			d[x]++;d[y]++;
		}
		int all=0;
		for (int i=1;i<=n;i++)
		if (d[i]>k) 
		{
			add(S,i,(d[i]-k)*2);
			all+=(d[i]-k)*2;
		}
		int flow=0;
		while (bfs()) flow+=dfs(S,inf);
		if (flow!=all)
		{
			for (int i=1;i<=m;i++) printf("0 ");
			cout<<endl;
			continue;
		}
		for (int i=1;i<=m;i++) ans[i]=0;
		num=1;flow=0;
		for (int i=1;i<=n;i++)
		for (int j=last[i];j;j=e[j].ne)
		if (e[j].z==0)
		{
			ans[e[j].y-n]=num;
			flow++;
			if (flow==2) num++,flow=0;
		}
		for (int i=1;i<=m;i++)
		{
			if (ans[i]==0) ans[i]=++num;
			printf("%d ",ans[i]);
		}
		cout<<endl;
	}
	return 0;
}