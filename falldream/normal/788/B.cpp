#include<iostream>
#include<cstdio>
#define ll long long
#define MN 1000000
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') f = -1;  ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
	return x * f;
}

int n,m,cnt=0,head[MN+5],num=0,num2=0,s[MN+5];
struct edge{int to,next;}e[MN*2+5];
ll ans=0;
bool mark[MN+5],b[MN+5];
void ins (int f,int t){e[++cnt]=(edge){t,head[f]};head[f]=cnt;}

void dfs(int x)
{
	mark[x]=1;
	for(int i=head[x];i;i=e[i].next)
		if(!mark[e[i].to])
			dfs(e[i].to);
}

int main()
{
	n=read();m=read();
	for(int i=1;i<=m;i++) 
	{
		int u=read(),v=read();
		if(u==v) num2++,b[u]=1;
		else ins(u,v),ins(v,u),num++,s[u]++,s[v]++;
	}
	for(int i=1;i<=n;i++) 
		if(b[i]||head[i]) 
		{
			dfs(i);break;
		}
	for(int i=1;i<=n;i++) if(!mark[i]&&(head[i]||b[i])) return 0*puts("0");
	for(int i=1;i<=n;i++) ans+=1LL*s[i]*(s[i]-1)/2;
	ans+=1LL*num2*(m-num2)+1LL*num2*(num2-1)/2;
	printf("%lld",ans);
	return 0;
}