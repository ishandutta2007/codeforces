#include<cstdio>
#include<iostream>
using namespace std;
const int N=600010;
struct Edge {int y,ne;};
int n,num,ma,maxi;
char t[N];
int ch[N][26],s[N],rt[N],c[N],g[N],dfn[N];
Edge e[N*2];int last[N];
void merge(int i,int j)
{
	for (int p=0;p<26;p++)
	{
		if (!ch[j][p]) continue;
		if (!ch[i][p]) ch[i][p]=ch[j][p],ch[j][p]=0;else
		merge(ch[i][p],ch[j][p]);
	}
	s[i]=1;for (int p=0;p<26;p++) s[i]+=s[ch[i][p]];
	s[j]=1;for (int p=0;p<26;p++) s[j]+=s[ch[j][p]];
}
void calc(int i,int fa)
{
	int first=0,p=0;
//	for (int j=last[i];j;j=e[j].ne)
//	if (e[j].y!=fa) dfs(e[j].y,i);
	for (int j=last[i];j;j=e[j].ne)
	if (e[j].y!=fa)
	{
		if (first) merge(p,rt[e[j].y]);
		else p=rt[e[j].y];
		first=1;
	}
	if (p==0) p=++num,s[p]=1;
	rt[i]=++num;
	ch[num][t[i]-'a']=p;
	s[num]=s[p]+1;
	int now=s[num]+c[i];
	if (now>ma) ma=now,maxi=1;else
	if (now==ma) maxi++;
}
void bfs()
{
	dfn[1]=1;
	int h=1,t=1;
	while (h<=t)
	{
		int now=dfn[h];h++;
		for (int j=last[now];j;j=e[j].ne)
		if (e[j].y!=g[now]) dfn[++t]=e[j].y,g[e[j].y]=now;
	}
}
void add(int x,int y) { e[++num]=(Edge){y,last[x]};last[x]=num;}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	scanf("%s",t+1);
	for (int i=2;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	num=0;
	bfs();	
	for (int i=n;i>=1;i--) calc(dfn[i],g[dfn[i]]);
	printf("%d\n%d\n",ma-1,maxi);
	return 0;
}