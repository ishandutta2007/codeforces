#include<cstdio>
#include<iostream>
using namespace std;
struct rec
{
	int len;int a[13];
	rec() { len=0;}
	void ins(int k)
	{
		for (int i=1;i<=len;i++)
		if (k<=a[i])
		{
			for (int j=len+1;j>=i+1;j--) a[j]=a[j-1];
			a[i]=k;
			if (len<10) len++;
			return;
		}
		if (len<10) a[++len]=k;
	}
};
const int N=100010;
struct Edge {int y,ne;};
int f[N][20];
rec g[N][20];
int n,m,q,num;
int de[N];
Edge e[N*2];int last[N];
rec operator +(rec a,rec b)
{
	int i=1,j=1;
	rec c;c.len=0;
	while (i<=a.len&&j<=b.len&&c.len<10)
	if (a.a[i]<b.a[j]) 
		 c.a[++c.len]=a.a[i++];
	else c.a[++c.len]=b.a[j++];
	while (i<=a.len&&c.len<10)
		 c.a[++c.len]=a.a[i++];
	while (j<=b.len&&c.len<10)
		 c.a[++c.len]=b.a[j++];
	return c;
}
void add(int x,int y) { e[++num]=(Edge){y,last[x]};last[x]=num;}
void dfs(int i)
{
	de[i]=de[ f[i][0] ]+1;
	for (int p=0;f[i][p];p++) f[i][p+1]=f[ f[i][p] ][p],g[i][p+1]=g[i][p]+g[ f[i][p] ][p];
	for (int j=last[i];j;j=e[j].ne)
	if (e[j].y!=f[i][0])
	{
		f[e[j].y][0]=i;
		dfs(e[j].y);
	}
}
rec calc(int i,int j)
{
	rec tmp;tmp.len=0;
	if (de[i]<de[j]) swap(i,j);
	for (int p=18;p>=0;p--) if (de[i]-de[j]>=(1<<p)) tmp=tmp+g[i][p],i=f[i][p];
	for (int p=18;p>=0;p--) if (f[i][p]!=f[j][p]) tmp=tmp+g[i][p]+g[j][p],i=f[i][p],j=f[j][p];
	if (i!=j) tmp=tmp+g[ f[i][0] ][0]+g[i][0]+g[j][0];
	else tmp=tmp+g[i][0];
	return tmp;
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	for (int i=1;i<=m;i++)
	{
		int x;
		scanf("%d",&x);
		g[x][0].ins(i);
	}
	dfs(1);
	while (q--)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		rec tmp=calc(x,y);
		int k=min(tmp.len,z);
		printf("%d ",k);
		for (int i=1;i<=k;i++) printf("%d ",tmp.a[i]);
		printf("\n");
	}
	return 0;
}