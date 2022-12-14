#include<algorithm>
#include<iostream>
#include<cstdio> 
#include<vector>
#define num(x,y) (((x)-1)*m+y)
#define MN 1000000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
vector<int> v[MN+5];
int n,m,*a[MN+5],s[MN+5],*rk[MN+5],Rk[MN+5],now,f[MN+5],in[MN+5],top,q[MN+5];
bool cmp(int x,int y){return a[now][x]<a[now][y];}
bool cmp2(int x,int y){return a[x][now]<a[y][now];}
inline int getfa(int x){return s[x]?s[x]=getfa(s[x]):x;}
inline void Merge(int x,int y){if(getfa(x)!=getfa(y))s[getfa(x)]=getfa(y);}
inline void ins(int y,int x){v[x].push_back(y);++in[y];}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i) 
	{
		a[i]=new int[m+5];
		rk[i]=new int[m+5];
		for(int j=1;j<=m;++j) a[i][j]=read(),rk[i][j]=j;
		now=i;sort(rk[i]+1,rk[i]+m+1,cmp);
		for(int j=1,k;j<=m;j=k+1)
		{
			for(k=j;k<=m&&a[i][rk[i][j]]==a[i][rk[i][k]];++k);--k;
			for(int l=j+1;l<=k;++l) Merge(num(i,rk[i][l]),num(i,rk[i][j]));	
		}
	} 
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=n;++j) Rk[j]=j;
		now=i;sort(Rk+1,Rk+n+1,cmp2);	
		for(int j=1,k;j<=n;j=k+1)
		{
			for(k=j;k<=n&&a[Rk[j]][i]==a[Rk[k]][i];++k);--k;
			for(int l=j+1;l<=k;++l) Merge(num(Rk[l],i),num(Rk[j],i));	
		}
	}
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=n;++j) Rk[j]=j;
		now=i;sort(Rk+1,Rk+n+1,cmp2);	
		for(int j=1,k,pre=0;j<=n;pre=j,j=k+1)
		{
			for(k=j;k<=n&&a[Rk[j]][i]==a[Rk[k]][i];++k);--k;
			if(pre) ins(getfa(num(Rk[j],i)),getfa(num(Rk[pre],i)));
		} 
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1,k,pre=0;j<=m;pre=j,j=k+1)
		{
			for(k=j;k<=m&&a[i][rk[i][j]]==a[i][rk[i][k]];++k);--k;
			if(pre) ins(getfa(num(i,rk[i][j])),getfa(num(i,rk[i][pre])));
		}	
	}
	for(int i=1;i<=n*m;++i) if(!in[i]&&getfa(i)==i) f[q[++top]=i]=1;
	for(int i=1;i<=top;++i) 
		for(int j=0;j<v[q[i]].size();++j)
			if(f[v[q[i]][j]]=max(f[v[q[i]][j]],f[q[i]]+1),!--in[v[q[i]][j]]) q[++top]=v[q[i]][j];
	for(int i=1;i<=n;++i,puts("")) for(int j=1;j<=m;++j) printf("%d ",f[getfa(num(i,j))]);
	return 0;
}