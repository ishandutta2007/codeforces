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
int head[N],next[N<<1],to[N<<1],dis[N],v[N],cnt;
void add(int u,int v){next[++cnt]=head[u],to[head[u]=cnt]=v,next[++cnt]=head[v],to[head[v]=cnt]=u;}
void work(int x)
{
	memset(dis,0,sizeof dis);
	int s=1;
	v[1]=x;
	while(s)
	{
		int u=v[s--];
		for(int i=head[u];i;i=next[i])
		{
			int t=to[i];
			if(!dis[t])dis[t]=dis[u]+1,v[++s]=t;	
		} 
	}
	dis[x]=0;
}
int max(int n)
{
	int ans=0;
	for(int i=1;i<=n;++i)if(dis[i]>dis[ans])ans=i;
	return ans;
}
int main()
{
    for(int x=read();x--;)
    {
    	memset(head,0,sizeof head),cnt=0;
    	int n=read(),a=read(),b=read(),da=read(),db=read();
    	for(int i=n;--i;)add(read(),read());
    	work(a);
    	if(dis[b]<=da||db<=da<<1){puts("Alice");continue;}
    	work(max(n));
    	puts(dis[max(n)]<=da<<1?"Alice":"Bob");
	}
	return 0;
}