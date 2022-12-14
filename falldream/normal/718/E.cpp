#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 100010
#define MD 15
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char st[MN+5];long long Ans[MD+5];
int n,head[MN+5],d[9][MN+5],D[9][9],top,q[MN+5],cnt=0,ans=0,val[MN+5],num[9][1<<8];
struct edge{int to,next,w;}e[MN*4+5];
inline void ins(int f,int t,int w){e[++cnt]=(edge){t,head[f],w};head[f]=cnt;}
void Update(int c,int x)
{
	for(int j=head[x];j;j=e[j].next)
		if(d[c][x]+e[j].w<d[c][e[j].to]) 
		{
			d[c][q[++top]=e[j].to]=d[c][x]+e[j].w;
			if(e[j].to>n)
				for(int k=head[e[j].to];k;k=e[k].next)
					if(d[c][e[j].to]<d[c][e[k].to]) d[c][q[++top]=e[k].to]=d[c][e[j].to];
		}
}	
int main()
{
	n=read();scanf("%s",st+1);
	memset(d,40,sizeof(d));memset(D,40,sizeof(D));
	for(int i=1;i<n;++i) ins(i,i+1,1),ins(i+1,i,1);
	for(int i=1;i<=n;++i) ins(i,st[i]-'a'+1+n,1),ins(st[i]-'a'+1+n,i,0);
	for(int c=1;c<=8;++c)
	{
		top=0;
		for(int i=1;i<=n;++i) if(st[i]-'a'+1==c) d[c][i]=0,q[++top]=i;
		for(int i=1;i<=top;++i) Update(c,q[i]);
		for(int i=1;i<=n;++i) D[c][st[i]-'a'+1]=min(D[c][st[i]-'a'+1],d[c][i]);
	}
	for(int i=1;i<=n;++num[st[i]-'a'+1][val[i]],++i)for(int j=1;j<=8;++j)if(d[j][i]>D[j][st[i]-'a'+1])val[i]|=1<<j-1;
	for(int i=0;i<1<<8;++i) for(int Kind=1;Kind<=8;++Kind) if(num[Kind][i])
		for(int j=0;j<1<<8;++j) for(int kind=1;kind<=8;++kind) if(num[kind][j])
			{
				int res=1e9;
				for(int k=1;k<=8;++k) 
					res=min(res,D[Kind][k]+D[k][kind]+1+bool(j&(1<<k-1))+bool(i&(1<<k-1)));
				Ans[res]+=1LL*num[Kind][i]*num[kind][j];
			}
	for(int i=1;i<=n;++i)
	{
		for(int j=-MD;j<=MD;++j) if(i+j>=1&&i+j<=n)
		{
			int res=1e9;
			for(int k=1;k<=8;++k)
				res=min(res,d[k][i]+d[k][i+j]+1);
			--Ans[res];++Ans[min(res,j<0?-j:j)];
		}
	}
	for(ans=15;!Ans[ans];--ans);
	printf("%d %lld\n",ans,Ans[ans]>>1);
	return 0;
}