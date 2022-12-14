#include<iostream>
#include<cstdio>
#define MN 200000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,k,head[MN+5],cnt=0,a[MN+5],ans=0,mid,f[MN+5],num[MN+5],mx[MN+5],mx2[MN+5],from[MN+5];
struct edge{int to,next;}e[MN*2+5];
inline void ins(int f,int t)
{
	e[++cnt]=(edge){t,head[f]};head[f]=cnt;
	e[++cnt]=(edge){f,head[t]};head[t]=cnt;	
}
void Add(int x,int flag,int v,int id)
{
	if(flag) f[x]+=v;	
	else 
	{
		++num[x];
		if(v>mx[x]) mx2[x]=mx[x],mx[x]=v,from[x]=id;	
		else if(v>mx2[x]) mx2[x]=v;
	}
}
void dfs(int x,int fa)
{
	num[x]=mx[x]=mx2[x]=from[x]=0;f[x]=a[x]>=mid;
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=fa)
		{
			int v=e[i].to;dfs(v,x);
			Add(x,!num[v],f[v]+mx[v],v);
		}
	if(a[x]<mid) f[x]=mx[x]=mx2[x]=0,++num[x];
}

void Solve(int x,int fa)
{
//	cout<<"Solve"<<x<<" "<<fa<<" "<<f[x]<<" "<<mx[x]<<endl;
	if(a[x]>=mid) ans=max(ans,f[x]+mx[x]);
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=fa)
		{
			int v=e[i].to;
			if(a[x]>=mid)
			{
				if(!num[v]) Add(v,!num[x],f[x]-f[v]+mx[x],x);	
				else Add(v,num[x]==1,f[x]+(from[x]==v?mx2[x]:mx[x]),x);
			}
			else Add(v,0,0,x);
			Solve(v,x); 
		}
}

int main()
{
	n=read();k=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<n;++i) ins(read(),read());
	int l=1,r=1e6,res;
	while(l<=r)
	{
	//	cout<<"begincalc"<<(l+r>>1)<<endl;
		mid=l+r>>1;ans=0;
		dfs(1,0);Solve(1,0);
		if(ans>=k) res=mid,l=mid+1;
		else r=mid-1;	
	}	
	printf("%d\n",res);
	return 0;
}