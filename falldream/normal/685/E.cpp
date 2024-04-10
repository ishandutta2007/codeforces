#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#define MN 200000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,Q,Ans[MN+5],X[MN+5],Y[MN+5],d[1005][1005];
vector<int> v[MN+5];
struct ques{int f,t,lim,id;};
vector<ques>q[MN+5];
int main()
{
	n=read();m=read();Q=read();
	for(int i=1;i<=m;++i)
	{
		int x=read(),y=read();
		v[x].push_back(i);
		v[y].push_back(i);	
		X[i]=x;Y[i]=y;
	}
	for(int i=1;i<=Q;++i)
	{
		int l=read(),r=read(),s=read(),t=read();
		q[l].push_back((ques){s,t,r,i});
	}
	memset(d,63,sizeof(d));
	for(register int i=m;i;--i)
	{
		int x=X[i],y=Y[i];d[x][y]=d[y][x]=i;
		for(int k=1;k<=n;++k)
		{
			int mn=min(d[x][k],d[y][k]);
			d[x][k]=d[y][k]=mn;	
		}
		for(int j=0;j<q[i].size();++j) Ans[q[i][j].id]=(d[q[i][j].f][q[i][j].t]<=q[i][j].lim);
	}
	for(int i=1;i<=Q;++i) puts(Ans[i]?"Yes":"No"); 
	return 0;
}