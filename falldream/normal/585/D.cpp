#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int ans=-1e9,aa,bb,cc,n,a[30],b[30],c[30],s[15],lim,S[15];
struct My_Map
{
	#define magic 1000007
	struct edge{long long x;int next,w;}e[3000005];
	int cnt=0,head[magic+5];
	void ins(long long H,int W)
	{
		int j=H%magic;
		for(int i=head[j];i;i=e[i].next)
			if(e[i].x==H)
			{
				e[i].w=max(e[i].w,W);
				return;
			}
		e[++cnt]=(edge){H,head[j],W};head[j]=cnt;
	}
	int Query(long long H)
	{
		for(int i=head[H%magic];i;i=e[i].next)
			if(e[i].x==H) return e[i].w;
		return -2e9;
	}
}mp;
void dfs1(int x,int A,int B,int C)
{
	if(x>lim) 
	{
		long long Hash=(long long)1e9*(B-A)+(A-C);
		mp.ins(Hash,A);
		return;
	}
	dfs1(x+1,A+a[x],B+b[x],C);
	dfs1(x+1,A+a[x],B,C+c[x]);
	dfs1(x+1,A,B+b[x],C+c[x]);
}

void dfs2(int x,int A,int B,int C)
{
	if(x==lim)
	{
		long long Hash=(long long)1e9*(A-B)+(C-A);
		int mx=mp.Query(Hash)+A;
		if(mx>ans) ans=mx,memcpy(S,s,sizeof(S)),aa=mx-A,bb=mx-B,cc=mx-C;
		return;
	}	
	s[x-lim]=1;dfs2(x-1,A+a[x],B+b[x],C);
	s[x-lim]=2;dfs2(x-1,A+a[x],B,C+c[x]);
	s[x-lim]=3;dfs2(x-1,A,B+b[x],C+c[x]); 
}

void Search(int x,int A,int B,int C)
{
	if(x>lim) 
	{
		if(A==aa&&B==bb&&C==cc)
		{
			for(int i=1;i<=lim;++i) puts(s[i]==1?"LM":(s[i]==2?"LW":"MW"));
			for(int i=lim+1;i<=n;++i) puts(S[i-lim]==1?"LM":(S[i-lim]==2?"LW":"MW"));
			exit(0);	
		}
		return;
	}
	s[x]=1;Search(x+1,A+a[x],B+b[x],C);
	s[x]=2;Search(x+1,A+a[x],B,C+c[x]);
	s[x]=3;Search(x+1,A,B+b[x],C+c[x]);
}

int main()
{
	n=read();lim=n>>1;
	for(int i=1;i<=n;++i) a[i]=read(),b[i]=read(),c[i]=read();
	dfs1(1,0,0,0);dfs2(n,0,0,0);
	if(ans==-1e9) puts("Impossible");
	else Search(1,0,0,0);
	return 0;
}