#include<cstdio>
#include<cstring>
const int N=1001;
int read() 
{ 	
    int a=0;char b=1,c; 
    do if((c=getchar())==45)b=-1;while(!(c&16)); 
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())&16); 
    return a*b; 
} 
int head[N],next[N<<1],to[N<<1],val[N<<1],l[N],r[N],dis[N][N],dui[N],fui[N];
int main()
{
    int n=read(),m=read(),k=read();
    for(int i=1;i<=m;++i)next[i<<1]=head[l[i]=read()],to[head[l[i]]=i<<1]=r[i]=read(),val[i<<1]=val[i<<1|1]=read(),next[i<<1|1]=head[r[i]],to[head[r[i]]=i<<1|1]=l[i];
	memset(dis,0x7f,sizeof dis);
	for(int x=1;x<=n;++x)
    {
    	memset(fui,0,sizeof fui),dis[x][dui[1]=x]=dis[x][0]=0;
	    int s=1;
	    while(s)
	    {
	        int u=dui[1];
	        fui[dui[1]=dui[s--]]=1;
	        for(int i=1;i<<1<=s;)
	        {
	            int son=i<<1==s||dis[x][dui[i<<1]]<dis[x][dui[i<<1|1]]?i<<1:i<<1|1;
	            if(dis[x][dui[i]]>dis[x][dui[son]]){int t=dui[i];fui[dui[i]=dui[son]]=i,fui[dui[i=son]=t]=son;}
	            else break;
	        }
	        for(int i=head[u];i;i=next[i])
	        {
	            int v=to[i];
	            if(dis[x][u]+val[i]<dis[x][v])
	            {
	                dis[x][v]=dis[x][u]+val[i];
	                if(!fui[v])dui[fui[v]=++s]=v;
	                for(int j=fui[v];dis[x][dui[j]]<dis[x][dui[j>>1]];j>>=1){int t=dui[j];fui[dui[j]=dui[j>>1]]=j,fui[dui[j>>1]=t]=j>>1;}
	            }
	        }
	    }
	}
	memset(dui,0,sizeof dui);
    while(k--)
    {
        int a=read(),b=read();
        for(int i=1;i<=m;++i)
        {
        	int t=dis[a][l[i]]+dis[b][r[i]]<dis[a][r[i]]+dis[b][l[i]]?dis[a][l[i]]+dis[b][r[i]]:dis[a][r[i]]+dis[b][l[i]];
        	dui[i]+=dis[a][b]<t?dis[a][b]:t;
		}
    }
    n=0x7fffffff;
    for(int i=1;i<=m;++i)if(dui[i]<n)n=dui[i];
    printf("%d",n);
    return 0;
}