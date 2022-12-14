#include<algorithm>
#include<iostream>
#include<cstdio>
#define MN 300000
#define mod 1000000007
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,head[MN+5],c[MN+5],cnt=0,f[MN+5],F[MN+5];
struct edge{int to,next;}e[MN+5];
inline void ins(int f,int t){e[++cnt]=(edge){t,head[f]};head[f]=cnt;}

void Dp(int x)
{
	if(c[x]) F[x]=1; else f[x]=1;
	for(int i=head[x];i;i=e[i].next)
	{
		Dp(e[i].to);	
		F[x]=(1LL*F[x]*(f[e[i].to]+F[e[i].to])+1LL*f[x]*F[e[i].to])%mod;
		f[x]=1LL*f[x]*(f[e[i].to]%mod+F[e[i].to])%mod;
	}
}

int main()
{
	n=read();
	for(int i=2;i<=n;++i) ins(read()+1,i);
	for(int i=1;i<=n;++i) c[i]=read();
	Dp(1);printf("%d\n",F[1]);
	return 0;
}