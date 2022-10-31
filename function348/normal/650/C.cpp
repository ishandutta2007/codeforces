#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1000010;
struct Edge {int y,ne;};
int n,m,num,cnt,mx;
int a[N],id[N],ans[N],v[N];
int c1[N],c2[N],q1[N],q2[N];
Edge e[N*4];int last[N];
int cmp(int i,int j) { return a[i]<a[j];}
void add(int i,int j) { e[++num]=(Edge){j,last[i]};last[i]=num;}
void dfs1(int i)
{
	int ii=id[i]/m,jj=id[i]%m;
	v[i]=cnt;mx=max(mx,max(c1[ii],c2[jj]));
	for (int j=last[i];j;j=e[j].ne)
	if (v[e[j].y]!=cnt) dfs1(e[j].y);
}
void dfs2(int i)
{
	v[i]=cnt;ans[id[i]]=mx+1;
	int ii=id[i]/m,jj=id[i]%m;
	c1[ii]=max(c1[ii],ans[id[i]]);
	c2[jj]=max(c2[jj],ans[id[i]]);
	for (int j=last[i];j;j=e[j].ne)
	if (v[e[j].y]!=cnt) dfs2(e[j].y);
}
int main()
{
//	freopen("data.in","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++)
		scanf("%d",&a[i*m+j]);
	for (int i=0;i<n*m;i++) id[i]=i;
	sort(id,id+n*m,cmp);
	int las=0;
	id[n*m]=n*m;
	for (int i=0;i<n*m;i++) q1[i]=q2[i]=-1;
	for (int p=1;p<=n*m;p++)
	if (a[id[p]]!=a[id[p-1]])
	{
		
		for (int i=las;i<p;i++)
		{
			int ii=id[i]/m,jj=id[i]%m;
			if (q1[ii]!=-1) add(i,q1[ii]),add(q1[ii],i);q1[ii]=i;
			if (q2[jj]!=-1) add(i,q2[jj]),add(q2[jj],i);q2[jj]=i;
		}
		for (int i=las;i<p;i++)
		if (ans[id[i]]==0)
		{
			mx=0;
			cnt++;dfs1(i);
			cnt++;dfs2(i);
		}
		num=0;
		for (int i=las;i<p;i++)
		{
			int ii=id[i]/m,jj=id[i]%m;
			q1[ii]=q2[jj]=-1;
			last[i]=0;
		}
		las=p;
		
	}
	for (int i=0;i<n*m;i++)
		printf("%d%c",ans[i],((i+1)%m==0)?'\n':' ');
	return 0;
}