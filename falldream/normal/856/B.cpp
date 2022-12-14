#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define MN 1000002
#define S 0
#define T 1000002
#define INF 1000000000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
char st[MN+5];
int n,c[MN+5][27],dn=1,cnt,head[MN+5];
int pp,nd[MN+5],len[MN+5],ans,C[MN+5],d[MN+5],q[MN+5],top,Len[MN+5];
struct edge{int to,next,w;}e[MN*30+5];
inline void ins(int f,int t,int w)
{
 //   cout<<"ins"<<f<<" "<<t<<" "<<w<<endl;
    e[++cnt]=(edge){t,head[f],w};head[f]=cnt;
    e[++cnt]=(edge){f,head[t],0};head[t]=cnt;
}

void Insert(int x)
{
    ans+=1;nd[++pp]=x;head[x]=0;
    memset(c[x],0,sizeof(c[x]));
    if(len[x]&1) ins(S,x,1);
    else ins(x,T,1);
}

bool bfs()
{
    memset(d,0,sizeof(int)*(dn+2));d[T]=0;int i,j;
    for(d[q[top=i=1]=S]=1;i<=top;++i)
        for(j=C[q[i]]=head[q[i]];j;j=e[j].next)
            if(e[j].w&&!d[e[j].to]) d[q[++top]=e[j].to]=d[q[i]]+1;
    return d[T];
}

int dfs(int x,int f)
{
    if(x==T) return f;int used=0;
    for(int&i=C[x];i;i=e[i].next)
        if(e[i].w&&d[e[i].to]==d[x]+1)
        {
            int w=dfs(e[i].to,min(f-used,e[i].w));
            used+=w;e[i].w-=w;e[i^1].w+=w;
            if(used==f) return f;
        }
    return d[x]=-1,used;
}

int main()
{
    for(int t=read();t;--t)
    {
        memset(c[1],0,sizeof(c[1]));
        n=read();cnt=1;dn=0;head[S]=head[T]=0;pp=0;ans=0;dn=1;
        for(int i=1,k=1;i<=n;++i)
        {
            scanf("%s",st+k);int x=1,m=strlen(st+k);Len[i]=m;
            for(int j=1;j<=m;++j)
            {
                if(!c[x][st[j+k-1]-'a']) len[c[x][st[j+k-1]-'a']=++dn]=j,Insert(dn);
                x=c[x][st[j+k-1]-'a'];
              //  cout<<i<<" "<<j<<" "<<st[j+k-1]<<" "<<x<<endl;
            }
            k+=m;
        }
        for(int i=1,k=1;i<=n;k+=Len[i++])
        {
            int x=c[1][st[k]-'a'],y=1;
            for(int j=k+1;j<k+Len[i];++j)
            {
                if(!c[y][st[j]-'a']) break;
                x=c[x][st[j]-'a'];y=c[y][st[j]-'a'];
                if(len[x]&1) ins(x,y,INF);
                else ins(y,x,INF);
            }
        }
        while(bfs()) ans-=dfs(S,INF);
        printf("%d\n",ans);
    }
    return 0;
}