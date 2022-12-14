#include<iostream>
#include<cstring>
#include<cstdio>
#define S 0
#define T 77
#define INF 2000000000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char st[105];
int n,b[105],pi=0,ans=0,d[105],q[105],top,tail,head[105],cnt=1,num[30];
bool inq[105],mark[105];
struct edge{int to,next,w,c;}e[T*T+5];

inline void ins(int f,int t,int w,int c)
{
	e[++cnt]=(edge){t,head[f],w, c};head[f]=cnt;	
	e[++cnt]=(edge){f,head[t],0,-c};head[t]=cnt;
}
inline int nxt(int x){return ++x>T?0:x;}
inline int lst(int x){return --x<0?T:x;}
bool modlabel()
{
	for(int i=S;i<T;++i) d[i]=INF;d[q[top=1]=T]=tail=0;	
	while(top!=tail)
	{
		int x=q[tail=nxt(tail)];
		for(int i=head[x];i;i=e[i].next)
			if(e[i^1].w&&d[x]+e[i^1].c<d[e[i].to])
			{
				d[e[i].to]=d[x]+e[i^1].c;
				if(!inq[e[i].to])
				{
					inq[e[i].to]=1;
					if(d[e[i].to]<d[q[nxt(tail)]]) q[tail]=e[i].to,tail=lst(tail);
					else q[top=nxt(top)]=e[i].to;
				}
			}  
		inq[x]=0;
	}
	if(d[S]==INF) return false;
	pi+=d[S];
	for(int i=S;i<=T;++i)for(int j=head[i];j;j=e[j].next)e[j].c+=d[e[j].to]-d[i];
	return true;
}

int dfs(int x,int f)
{
	if(x==T) return ans+=pi*f,f;mark[x]=1;int used=0;
	for(int i=head[x];i;i=e[i].next)
		if(!e[i].c&&e[i].w&&!mark[e[i].to])
		{
			int w=dfs(e[i].to,min(f-used,e[i].w));
			used+=w;e[i].w-=w;e[i^1].w+=w;
			if(used==f) return f; 
		}
	return used;
}

int main()
{
	n=read();scanf("%s",st+1);
	for(int i=1;i<=n;++i) ++num[st[i]-'a'+1],b[i]=read();
	for(int i=1;i<=26;++i)
	{
		ins(S,i,num[i],0);
		for(int j=1;j<<1<=n;++j) ins(i,j+26,1,-max((st[j]==i+'a'-1)?b[j]:0,(st[n+1-j]==i+'a'-1)?b[n+1-j]:0)); 
	}
	for(int i=1;i<<1<=n;++i) ins(i+26,T,2,0);
	while(modlabel()) 
		do memset(mark,0,sizeof(mark));
		while(dfs(S,INF));
	printf("%d\n",-ans);
	return 0;
}