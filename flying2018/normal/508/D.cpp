#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 300010
using namespace std;
int nxt[N<<1],to[N<<1],head[N],cnt;
int deg[N];
void add(int u,int v)
{
	nxt[++cnt]=head[u];
	to[cnt]=v;
	head[u]=cnt;
	deg[u]++,deg[v]--;
}
char str[4];
string ans;
void dfs(int u)
{
	for(int &i=head[u];i;)
	{
		int v=to[i];
		i=nxt[i];
		dfs(v);
	}
	ans+=(char)(u&255);
}
int main()
{
	int n;
	scanf("%d",&n);
	int s=0,t=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",str+1);
		int u=str[1]*256+str[2],v=str[2]*256+str[3];
		add(u,v);
		s=u;
	}
	for(int i=0;i<N-10;i++)
	if(deg[i])
	{
		if(deg[i]>1 || deg[i]<-1){puts("NO");return 0;}
		if(deg[i]==1) s=i;
		if(deg[i]==-1){if(t){puts("NO");return 0;}t=i;}
	}
	dfs(s);
	ans+=char(s/256);
	if(ans.size()!=n+2){puts("NO");return 0;}
	puts("YES");
	reverse(ans.begin(),ans.end());
	cout<<ans;
	return 0;
}