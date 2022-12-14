#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#include<set>
#include<map>
#define ll long long
#define ld long double
#define pa pair<int,int>
#define mp(x,y) make_pair(x,y)
#define MN 300000
using namespace std;
inline int read()
{
    int x = 0,f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-') f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:-x;
}

int n,m,head[MN+5],mark[MN+5],ans=1,cnt=0,col[MN+5];
struct edge{int to,next;}e[MN*2+5];
vector<int> v[MN+5];

inline void ins(int f,int t)
{
    e[++cnt]=(edge){t,head[f]};head[f]=cnt;
    e[++cnt]=(edge){f,head[t]};head[t]=cnt;
}

void Solve(int x,int fa)
{
    for(int i=0;i<v[x].size();++i) mark[col[v[x][i]]]=x;
    for(int i=0,j=1;i<v[x].size();++i)
    {
        for(;mark[j]==x;++j);
        if(!col[v[x][i]]) col[v[x][i]]=j++;
    }
    for(int i=head[x];i;i=e[i].next)
        if(e[i].to!=fa) Solve(e[i].to,x);
}

int main()
{
    n=read();m=read();
    for(int i=1;i<=n;++i)
    {
        int x=read();ans=max(ans,x);
        for(int j=1;j<=x;++j) v[i].push_back(read());
    }
    for(int i=1;i<n;++i) ins(read(),read());
    Solve(1,0);printf("%d\n",ans);
    for(int i=1;i<=m;++i)
        printf("%d ",col[i]?col[i]:1);
    return 0;
}