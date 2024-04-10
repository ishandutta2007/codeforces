#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
struct edge
{
    int nxt,to;
}e[1000001<<1];
int n,tot,h[1000001],d[1000001],ans;
vector<pair<int,int> > v;
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
inline void add(int x,int y)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
}
void dfs(int k,int f,int t)
{
    v.push_back(make_pair(k,t));
    int tmp=t;
    for(register int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        if(tmp==ans&&t>d[k])
        {
            tmp=ans-d[k];
            v.push_back(make_pair(k,tmp));
        }
        if(tmp==d[k]&&t<=d[k])
        {
            tmp=0;
            v.push_back(make_pair(k,tmp));
        }
        dfs(e[i].to,k,++tmp);
        v.push_back(make_pair(k,tmp));
    }
    if(t>=1&&tmp!=t-1)
        v.push_back(make_pair(k,t-1));
}
int main()
{
    n=read();
    for(register int i=1;i<n;++i)
    {
        int x=read(),y=read();
        add(x,y);
        add(y,x);
        ++d[x];
        ++d[y];
        ans=max(ans,max(d[x],d[y]));
    }
    dfs(1,0,0);
    printf("%d\n",(int)v.size());
    for(auto i:v)
        printf("%d %d\n",i.first,i.second);
    return 0;
}