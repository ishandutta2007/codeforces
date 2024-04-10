#include<algorithm>
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
long long sum[MN+5];
int n,k,p,head[MN+5],cnt=0,rk[MN+5],dep[MN+5],ans=0;
struct edge{int to,next;}e[MN*2+5];
inline void ins(int f,int t)
{
	e[++cnt]=(edge){t,head[f]};head[f]=cnt;
	e[++cnt]=(edge){f,head[t]};head[t]=cnt;	
}

void Pre(int x,int fa)
{
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=fa) dep[e[i].to]=dep[x]+1,Pre(e[i].to,x);
}
bool cmp(int x,int y){return dep[x]<dep[y];}
int main()
{
	n=read();k=read();p=read();
	for(int i=1;i<n;++i) ins(read(),read());
	for(int i=1;i<=n;++i) rk[i]=i;
	Pre(1,0);sort(rk+1,rk+n+1,cmp);
	for(int i=1;i<=n;++i) sum[i]=sum[i-1]+dep[rk[i]];
	for(int i=1,j=1;i<=dep[rk[n]];++i)
	{
		while(j<n&&dep[rk[j+1]]<=i) ++j;
		int l=max(2,j-k+1),r=j,mid,res=-1;
		while(l<=r)
		{
			mid=l+r>>1;int len=j-mid+1;
			long long c=1LL*i*len-(sum[j]-sum[mid-1]);
			if(c<=p) res=mid,r=mid-1;
			else l=mid+1;
		}
		if(res!=-1) ans=max(ans,j-res+1);
	} 
	printf("%d\n",ans);
	return 0;
}