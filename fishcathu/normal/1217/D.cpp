#include<cstdio>
const int N=5001;
int read() 
{ 	
    int a=0;char b=1,c; 
    do if((c=getchar())==45)b=-1;while(!(c&16)); 
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())&16); 
    return a*b; 
} 
void write(int x) 
{
    if(x<0)putchar('-'),x=-x; 
    char a[10],s=0; 
    do a[s++]=x%10|48;while(x/=10); 
    do putchar(a[--s]);while(s);
}
int head[N],next[N],to[N],clo[N],ans[N],cyc=1; 
void dfs(int x)
{
	clo[x]=1;
	for(int i=head[x];i;i=next[i])
	{
		int t=to[i];
		if(!clo[t])dfs(t),ans[i]=1;
		else if(clo[t]==1)ans[i]=2,cyc=2;
		else ans[i]=1;
	}
	clo[x]=2;
}
int main()
{
	int n=read(),m=read();
	for(int i=1,u;i<=m;++i)next[i]=head[u=read()],to[head[u]=i]=read();
	for(int i=1;i<=n;++i)if(!clo[i])dfs(i);
	write(cyc),putchar('\n');
	for(int i=1;i<=m;++i)write(ans[i]),putchar(' ');
	return 0;
}