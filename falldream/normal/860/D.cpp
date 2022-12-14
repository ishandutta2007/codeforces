#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define MN 200000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct edge{int to,next,w;}e[MN*2+5];
int n,m,cnt=0,head[MN+5],mark[MN+5],ans[MN+5][3],vis[MN+5],F[MN+5],num=0;
vector<pair<int,int> > v[MN+5];
inline void ins(int f,int t,int w)
{
    e[++cnt]=(edge){t,head[f],w};head[f]=cnt;
    e[++cnt]=(edge){f,head[t],w};head[t]=cnt;
}

void Add(int x,int y,int z)
{
    ++num;
    ans[num][0]=x;
    ans[num][1]=y;
    ans[num][2]=z;
}

int Solve(int x,int fa)
{
 //   cout<<"Solve"<<x<<" "<<fa<<endl;
    vis[x]=1;
    for(int i=head[x];i;i=e[i].next)
        if(e[i].to!=fa)
        {
            if(!vis[e[i].to])
            {
                if(F[e[i].to]=e[i].w,Solve(e[i].to,x)) v[x].push_back(make_pair(e[i].to,e[i].w));
            }
            else if(vis[e[i].to]&&!mark[e[i].w]) v[x].push_back(make_pair(e[i].to,e[i].w));
        }
    if(fa!=0) v[x].push_back(make_pair(fa,F[x]));
    //cout<<x<<endl;
    //for(int i=0;i<v[x].size();++i)
     //   printf("%d %d\n",v[x][i].first,v[x][i].second);
    for(int i=0;i+2<=v[x].size();i+=2)
    {
        mark[v[x][i].second]=1;
        mark[v[x][i+1].second]=1;
        Add(v[x][i].first,x,v[x][i+1].first);
    }
    if(mark[F[x]]!=1) return 1;
    else return 0;
}

int main()
{
    n=read();m=read();
    for(int i=1;i<=m;++i)
    {
        int x=read(),y=read();
        ins(x,y,i);
    }
    for(int i=1;i<=n;++i) if(!vis[i]) Solve(i,0);
    cout<<num<<endl;
    for(int i=1;i<=num;++i)
        printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
    return 0;
}