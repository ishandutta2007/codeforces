#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 100000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,k,head[MN+5],cnt=0,ban[MN+5],Ban[MN+5],d[MN+5],bad[MN+5],Bad[MN+5],Ans[MN+5],ans=0;
struct edge{int to,next;}e[MN*2+5];
inline void ins(int f,int t)
{
	e[++cnt]=(edge){t,head[f]};head[f]=cnt;
	e[++cnt]=(edge){f,head[t]};head[t]=cnt;	
}

void Del(int x,double mid)
{
//	cout<<"Del"<<x<<" "<<mid<<endl;
	ban[x]=1;
	for(int i=head[x];i;i=e[i].next)
		if(!ban[e[i].to]&&(double)(++bad[e[i].to])/d[e[i].to]>1-mid)
			Del(e[i].to,mid);
}

bool Solve(double mid)
{
//	printf("Solve %.10lf\n",mid);
	memcpy(bad,Bad,sizeof(bad));
	memcpy(ban,Ban,sizeof(Ban));
//	for(int i=1;i<=n;++i) if(!ban[i]) cout<<i<<" "<<bad[i]<<" "<<d[i]<<endl; 
	for(int i=1;i<=n;++i) if(!ban[i]&&(double)bad[i]/d[i]>1-mid) Del(i,mid);
	for(int i=1;i<=n;++i) if(!ban[i]) return true;
	return false;
}

void dfs(int x)
{
	Ans[++ans]=x;ban[x]=1;	
	for(int i=head[x];i;i=e[i].next)
		if(!ban[e[i].to]) dfs(e[i].to);
}

int main()
{
	n=read();m=read();k=read();
	for(int i=1,j;i<=k;++i) j=read(),ban[j]=Ban[j]=1;
	for(int i=1;i<=m;++i) 
	{
		int x=read(),y=read();
		++d[x];++d[y];bad[x]+=ban[y];bad[y]+=ban[x];	
		ins(x,y);
	}
	memcpy(Bad,bad,sizeof(bad));
	double l=0,r=1,mid,res;
	for(int i=1;i<=100;++i)
	{
		mid=(l+r)/2.0;
		if(Solve(mid)) res=mid,l=mid;
		else r=mid;	
	}
	Solve(res);//printf("%.10lf\n",res);
	for(int i=1;i<=n;++i) if(!ban[i])
	{
		dfs(i);printf("%d\n",ans);
		for(int i=1;i<=ans;++i) printf("%d ",Ans[i]);
		return 0;
	}
	return 0;
}