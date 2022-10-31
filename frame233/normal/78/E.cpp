#include<cstdio>
#include<cstring>
const int N=20005,inf=0x7fffffff;
const int dx[]={1,0,0,-1},dy[]={0,1,-1,0};
struct node{
    int x,y,dep;
};
node __q[N];
int __l,__r;
struct edge{
    int v,nxt,w;
}c[N<<5];
char s1[13][13],s2[13][13];
int front[N],cnt=-1;
int dep[N],cur[N],s,t;
int _q[N],_l,_r;
double tim[13][13];
inline int min(int a,int b){return a<b?a:b;}
inline void add(int u,int v,int w)
{
    c[++cnt]=(edge){v,front[u],w},front[u]=cnt;
    c[++cnt]=(edge){u,front[v],0},front[v]=cnt;
}
bool bfs()
{
    memset(dep,255,sizeof(dep));
    memcpy(cur,front,sizeof(cur));
    dep[s]=0,_q[_l=_r=1]=s;
    while(_l!=_r+1)
    {
        int x=_q[_l++];
        for(int i=front[x];~i;i=c[i].nxt)
        {
            if(c[i].w&&!~dep[c[i].v])
            {
                dep[c[i].v]=dep[x]+1;
                _q[++_r]=c[i].v;
            }
        }
    }
    return ~dep[t];
}
int dfs(int x,int flow)
{
    if(x==t||!flow) return flow;
    int f=0,rf;
    for(int &i=cur[x];~i;i=c[i].nxt)
    {
        if(dep[c[i].v]==dep[x]+1&&(rf=dfs(c[i].v,min(c[i].w,flow))))
        {
            flow-=rf,f+=rf;
            c[i].w-=rf,c[i^1].w+=rf;
            if(!flow) return f;
        }
    }
    return f;
}
int dinic()
{
    int ans=0;
    while(bfs()) ans+=dfs(s,inf);
    return ans;
}
int main()
{
    memset(front,255,sizeof(front));
    int n,T;
    scanf("%d %d",&n,&T);
    int sum=n*n;
    s=sum*(t+100)+1,t=s+1;
    for(int i=1;i<=n;++i) scanf("%s",s1[i]+1);
    for(int i=1;i<=n;++i) scanf("%s",s2[i]+1);
    int id=0,_x=0,_y=0;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            ++id;
            if(s1[i][j]>='1'&&s1[i][j]<='9')
            {
                add(s,id,s1[i][j]-48);
            }
            if(s1[i][j]=='Z')
            {
                tim[i][j]=0;
                _x=i,_y=j;
            }
            else if(s1[i][j]=='Y')
            {
                tim[i][j]=0;
            }
            else
            {
                tim[i][j]=T+0.5;
            }
        }
    }
    __q[__l=__r=1]=(node){_x,_y,0};
    node x,tmp;
    while(__l!=__r+1)
    {
        x=__q[__l++];
        if(x.dep==t) continue;
        for(int i=0;i<4;++i)
        {
            tmp=x;
            tmp.x+=dx[i],tmp.y+=dy[i],++tmp.dep;
            if(tmp.x>=1&&tmp.x<=n&&tmp.y>=1&&tmp.y<=n&&tim[tmp.x][tmp.y]>tmp.dep)
            {
                tim[tmp.x][tmp.y]=tmp.dep;
                __q[++__r]=tmp;
            }
        }
    }
    id=0;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            ++id;
            if(s2[i][j]>='1'&&s2[i][j]<='9')
            {
                add(id+((int)tim[i][j])*sum,t,s2[i][j]-48);
            }
            for(int k=0;k<tim[i][j];++k)
            {
                add(id+k*sum,id+sum*(k+1),inf);
                for(int dir=0;dir<4;++dir)
                {
                    int u=i+dx[dir],v=j+dy[dir];
                    if(u>=1&&u<=n&&v>=1&&v<=n&&tim[u][v]>=k+1)
                    {
                        add(id+k*sum,(u-1)*n+v+(k+1)*sum,inf);
                    }
                }
            }
        }
    }
    printf("%d\n",dinic());
//    for(int i=front[t];~i;i=c[i].nxt)
//    {
//        if(c[i].w)
//        {
//            printf("to %d  flow : %d\n",c[i].v%sum,c[i].w);
//        }
//    }
//    printf("\n");
//    for(int i=1;i<=n;++i)
//    {
//    	for(int j=1;j<=n;++j)
//    	{
//    		printf("%.2lf ",tim[i][j]);
//		}
//		putchar('\n');
//	}
    return 0;
}