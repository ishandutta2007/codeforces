#include<iostream>
#include<cstdio>
#define MN 100000
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') f = -1;  ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
	return x * f;
}

int n,head[MN+5],s[20000005],s2[20000005],cnt=0,a[MN+5];
struct edge{int to,next;}e[MN*2+5];

inline void ins(int f,int t)
{
	e[++cnt]=(edge){t,head[f]};head[f]=cnt;	
}
int dd,d[MN+5];
void Dfs(int x,int fa,int dep)
{
	d[x]=dep;
	if(dep&1) ++s[a[x]];else ++s2[a[x]];
	int son=0;
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=fa)
			++son,Dfs(e[i].to,x,dep+1);
	if(!son) dd=dep;
}

int main()
{
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=2;i<=n;++i) 
	{
		int fa=read();
		ins(fa,i);ins(i,fa);	
	}
	Dfs(1,0,1);int ans=0,num=0;
		for(int i=1;i<=n;++i)
			if((d[i]&1)==(dd&1))	
				ans^=a[i],++num;
	long long aa=0;
	for(int i=1;i<=n;++i)
			if((d[i]&1)==(dd&1))
				aa+=(dd&1)?s2[a[i]^ans]:s[a[i]^ans];
	if(ans==0) aa+=1LL*num*(num-1)/2+1LL*(n-num)*(n-num-1)/2;
	cout<<aa;
	return 0;
}