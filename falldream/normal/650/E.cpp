#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#define MN 500000
#define P(x,y) make_pair(min(x,y),max(x,y))
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
using namespace std;
int n,s[MN+5],head[MN+5],cnt=0,ans=0;
struct edge{int to,next;}e[MN*2+5];
struct res{int a,b,c,d;}Ans[MN+5];
vector<pair<int,int> > v[MN+5];
map<pair<int,int>,int> mp;
inline int getfa(int x){return s[x]?s[x]=getfa(s[x]):x;}
inline void ins(int f,int t)
{
    e[++cnt]=(edge){t,head[f]};head[f]=cnt;
    e[++cnt]=(edge){f,head[t]};head[t]=cnt;
}
void Merge(int x,int y)
{
    x=getfa(x);y=getfa(y);
    if(x==y) return;
    if(v[x].size()<v[y].size()) swap(x,y);
    for(int j=0;j<v[y].size();++j) v[x].push_back(v[y][j]);
    s[y]=x;
}
pair<int,int> Find(int x)
{
    for(;;)
        if(getfa(v[x].back().second)==x) v[x].pop_back();
        else return v[x].back();
}
void dfs(int x,int fa)
{
    for(int i=head[x];i;i=e[i].next)
        if(e[i].to!=fa)
        {
            dfs(e[i].to,x);
            if(mp[P(x,e[i].to)])
            {
                pair<int,int> g=Find(getfa(e[i].to));
                Ans[++ans]=(res){x,e[i].to,g.first,g.second};
                Merge(g.first,g.second);
            }
        }
}
int main()
{
    n=read();
    for(int i=1;i<n;++i)
    {
        int x=read(),y=read();
        ins(x,y);mp[P(x,y)]=1;
    }
    for(int i=1;i<n;++i)
    {
        int x=read(),y=read();
        if(mp[P(x,y)]) Merge(x,y),mp[P(x,y)]=0;
        else v[getfa(x)].push_back(make_pair(x,y)),
             v[getfa(y)].push_back(make_pair(y,x));
    }
    dfs(1,0);
    printf("%d\n",ans);
    for(int i=1;i<=ans;++i) printf("%d %d %d %d\n",Ans[i].a,Ans[i].b,Ans[i].c,Ans[i].d);
    return 0;
}