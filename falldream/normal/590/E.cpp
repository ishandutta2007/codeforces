#include<iostream>
#include<cstring>
#include<cstdio>
#include<bitset>
#define MN 10000100
#define MX 750
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

namespace FLOW
{
	#define S 0
	#define T 1501	
	#define MM 4000000
	#define INF 2000000000
	int d[T+5],q[T+5],head[T+5],c[T+5],cnt,top;
	struct edge{int to,next,w;}e[MM+5];
	void init(){cnt=1;memset(head,0,sizeof(head));}
	inline void ins(int f,int t,int w)
	{
	//	cout<<"ins"<<f<<" "<<t<<" "<<w<<endl;
		e[++cnt]=(edge){t,head[f],w};head[f]=cnt;	
		e[++cnt]=(edge){f,head[t],0};head[t]=cnt;
	}
	bool bfs()
	{
		memset(d,0,sizeof(d));int i,j;
		for(d[q[top=i=1]=S]=1;i<=top;++i)
			for(j=c[q[i]]=head[q[i]];j;j=e[j].next)
				if(e[j].w&&!d[e[j].to]) d[q[++top]=e[j].to]=d[q[i]]+1;
		return d[T];	
	}
	int dfs(int x,int f)
	{
		if(x==T) return f;int used=0;	
		for(int&i=c[x];i;i=e[i].next)
			if(e[i].w&&d[e[i].to]==d[x]+1)
			{
				int w=dfs(e[i].to,min(f-used,e[i].w));
				e[i].w-=w;e[i^1].w+=w;used+=w;
				if(used==f) return f;	
			}
		return d[x]=-1,used;
	}
	int dinic()
	{
		int ans=0;
		while(bfs()) ans+=dfs(S,INF);
		return ans;
	}
	#undef MM
	#undef INF
}
bitset<MX+5> mark[MX+5];
int n,c[2][MN+5],fail[MN+5],top,cnt,lt[MX+5],rt[MX+5],b[MX+5],cc=0;
int num[MX+5],dn=0,ed[MN+5],res[MX+5][MX+5],q[MN+5],head[MN+5],ans;
char st[MN+5];struct edge{int to,next;}e[MN+MX*1000+5];
inline void Ins(int f,int t){e[++cc]=(edge){t,head[f]};head[f]=cc;}

int GetFlow()
{
	int Now=0;FLOW::init();
	for(int k=1;k<=n;++k) if(!b[k]) 
		{
			FLOW::ins(S,k,1),FLOW::ins(k+n,T,1);++Now;
			for(int j=1;j<=n;++j) if(!b[j]&&mark[k][j]) FLOW::ins(k,j+n,1); 
		}
	int res=FLOW::dinic();
	return Now-res;
}

int main()
{   //clock_t beg=clock();
//	freopen("1.in","r",stdin);
	FLOW::init();int was=0;
	c[0][0]=c[1][0]=cnt=1;n=read();
	for(int i=1,l=1;i<=n;++i) 
	{
		int x=1;scanf("%s",st+l);
		int len=strlen(st+l);
		lt[i]=l;rt[i]=l+len-1;l+=len;
		for(register int j=lt[i];j<=rt[i];++j)
		{
			if(!c[st[j]-'a'][x]) c[st[j]-'a'][x]=++cnt;
			x=c[st[j]-'a'][x];	
		}
		if(ed[x]) b[i]=1,++was; else ed[x]=i;
	}
	q[top=1]=1;
	for(register int i=1;i<=top;++i)
	{
		int x=q[i];if(!ed[x])ed[x]=ed[fail[x]];
		if(c[0][x])
		{
			int y=fail[x];
			while(!c[0][y]) y=fail[y];	
			fail[q[++top]=c[0][x]]=c[0][y];
		}
		if(c[1][x])
		{
			int y=fail[x];
			while(!c[1][y]) y=fail[y];	
			fail[q[++top]=c[1][x]]=c[1][y];
		} 
	}
	for(int i=1;i<=n;++i)
	{
		int x=1;
		for(int j=lt[i];j<=rt[i];++j) 
		{
			x=c[st[j]-'a'][x];	
			if(ed[fail[x]]&&j==rt[i]) mark[i][ed[fail[x]]]=1;
			if(ed[x]&&j!=rt[i]) mark[i][ed[x]]=1; 
		}
	} 
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)	
			if(mark[i][k]) mark[i]|=mark[k];
	printf("%d\n",ans=GetFlow());
	for(int i=1,F=ans;i<=n;++i) if(F&&!b[i])
	{
		q[top=1]=i;b[i]=1;int Now=0;
		for(int j=1;j<=n;++j) if((mark[i][j]||mark[j][i])&&!b[j]) b[j]=1,q[++top]=j;
		if(GetFlow()==F-1) --F,printf("%d ",i),b[i]=1;
		else for(int k=1;k<=top;++k) b[q[k]]=0;
	}
//	cerr<<clock()-beg;
	return 0;
}