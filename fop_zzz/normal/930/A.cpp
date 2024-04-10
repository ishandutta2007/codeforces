#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<queue>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define inf 1e9
using namespace std;
inline int read()
{
	int t=0,f=1;char c=getchar();
	while(!isdigit(c))	{if(c=='-')	f=-1;c=getchar();}
	while(isdigit(c))	t=t*10+c-'0',c=getchar();
	return t*f;
}
inline void write(int x){if(x>=10)	write(x/10);putchar(x%10+'0');}
inline void writeln(int x){write(x);puts("");}
inline void write_p(int x){write(x);putchar(' ');}
int n,head[200001],cnt,nxt[200001],poi[200001],ans,tot[200001];
inline void add(int x,int y){poi[++cnt]=y;nxt[cnt]=head[x];head[x]=cnt;}
inline void Dfs(int x,int dep)
{
	tot[dep]++;
	for(int i=head[x];i;i=nxt[i])
		Dfs(poi[i],dep+1);
}
int main()
{
	n=read();
	For(i,2,n)	add(read(),i);
	Dfs(1,0);
	For(i,1,n)	if(tot[i]&1)	ans++;
	writeln(ans+1);
}