#include<cstdio>
#include<cstring>
const int N=1E5+10;
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
int head[N],next[N<<1],to[N<<1],sum[N],vc[N],dis[N];
int main()
{
	int n=read(),j=1,s=1;
	for(int i=1,u,v;i<n;++i)next[i<<1]=head[u=read()],++sum[to[head[u]=i<<1]=v=read()],next[i<<1|1]=head[v],++sum[to[head[v]=i<<1|1]=u];
	while(sum[j]!=1)++j;
	vc[1]=j;
	while(s)
	{
		int u=vc[s--];
		for(int i=head[u];i;i=next[i])if(!dis[to[i]])dis[vc[++s]=to[i]]=dis[u]+1;
	}
	dis[j]=0;
	while(j<=n&&(sum[j]!=1||!(dis[j]&1)))++j;
	putchar(j>n?'1':'3'),putchar(' ');
	memset(vc,0,sizeof vc);
	int ans=n-1;
	for(int i=1;i<=n;++i)if(sum[i]==1)
	{
		--ans;
		if(!vc[to[head[i]]])vc[to[head[i]]]=1,++ans;
	}
	write(ans);
}