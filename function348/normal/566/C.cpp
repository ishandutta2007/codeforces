#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long LL;
const int N=200010;
struct Edge {int y,z,ne;};
Edge e[N*2];int last[N];
int n,ans1,num,rt,minn;
double ans2;
int size[N],w[N],v[N];
double der[N];
void add(int x,int y,int z) { e[++num]=(Edge){y,z,last[x]};last[x]=num;}
double dfs2(int i,int fa,LL len,double p)
{
	double tmp=pow(len,p)*w[i];
	for (int j=last[i];j;j=e[j].ne)
	if (e[j].y!=fa)
		tmp+=dfs2(e[j].y,i,len+e[j].z,p);
	return tmp;
}
void dfs3(int i,int fa)
{
	size[i]=1;
	for (int j=last[i];j;j=e[j].ne)
	if (!v[e[j].y]&&e[j].y!=fa)
	{
		dfs3(e[j].y,i);
		size[i]+=size[e[j].y];
	}
}
void dfs4(int i,int fa,int p)
{
	int tmp=size[p]-size[i];
	for (int j=last[i];j;j=e[j].ne)
	if (!v[e[j].y]&&e[j].y!=fa) 
	{
		dfs4(e[j].y,i,p);
		tmp=max(tmp,size[e[j].y]);
	}
	if (tmp<minn) rt=i,minn=tmp;
}
double dfs5(int i,int fa,LL len,double p)
{
	double res=pow(len,p)*w[i];
	for (int j=last[i];j;j=e[j].ne)
	if (e[j].y!=fa)
		res+=dfs5(e[j].y,i,len+e[j].z,p);
	return res;
}
void dfs(int i,int fa)
{
	if (v[i]) return;
	rt=0;minn=n+1;
	dfs3(i,0);dfs4(i,0,i);
	v[rt]=1;
	double tmp=dfs2(rt,0,0,1.5);
	if (tmp<ans2) ans2=tmp,ans1=rt;
	num=0;int root=rt;
	double all=0;
	for (int j=last[root];j;j=e[j].ne)
	{
		der[++num]=dfs5(e[j].y,root,e[j].z,0.5);
		all-=der[num];
	}
	num=0;
	for (int j=last[root];j;j=e[j].ne)
	{
		num++;
		der[num]=all+2*der[num];
		if (der[num]>0) { dfs(e[j].y,root);break;}
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&w[i]);
	for (int i=1;i<n;i++) 
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);add(y,x,z);
	}
	ans2=1e+23;
	dfs(1,0);
	printf("%d %.6lf\n",ans1,ans2);
	return 0;
}