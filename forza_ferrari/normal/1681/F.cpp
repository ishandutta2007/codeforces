#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,m,fa[500001],ch[500001][2],s[500001][2],top,stack[500001];
long long ans;
bool tag[500001];
vector<pair<int,int> > v[500001];
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
inline void push_up(int x)
{
    s[x][0]=s[ch[x][0]][0]+s[ch[x][1]][0]+s[x][1]+1;
}
inline bool nroot(int x)
{
    return x==ch[fa[x]][0]||x==ch[fa[x]][1];
}
inline void update(int x)
{
    ch[x][0]^=ch[x][1]^=ch[x][0]^=ch[x][1];
    tag[x]^=1;
}
inline void push_down(int x)
{
    if(tag[x])
    {
        if(ch[x][0])
            update(ch[x][0]);
        if(ch[x][1])
            update(ch[x][1]);
        tag[x]=0;
    }
}
inline void rotate(int x)
{
    int y=fa[x],z=fa[y],k=x==ch[y][1];
    if(nroot(y))
        ch[z][y==ch[z][1]]=x;
    ch[y][k]=ch[x][k^1];
    if(ch[x][k^1])
        fa[ch[x][k^1]]=y;
    ch[x][k^1]=y;
    fa[y]=x;
    fa[x]=z;
    push_up(y);
}
inline void splay(int x)
{
    int y=x;
    stack[top=1]=y;
    while(nroot(y))
        stack[++top]=y=fa[y];
    while(top)
        push_down(stack[top--]);
    while(nroot(x))
    {
        int y=fa[x],z=fa[y];
        if(nroot(y))
            rotate((x==ch[y][0])^(y==ch[z][0])? x:y);
        rotate(x);
    }
    push_up(x);
}
inline void access(int x)
{
    for(int y=0;x;x=fa[y=x])
    {
        splay(x);
        s[x][1]+=s[ch[x][1]][0]-s[y][0];
        ch[x][1]=y;
        push_up(x);
    }
}
inline void makeroot(int x)
{
    access(x);
    splay(x);
    update(x);
}
inline int findroot(int x)
{
    access(x);
    splay(x);
    while(ch[x][0])
    {
        push_down(x);
        x=ch[x][0];
    }
    splay(x);
    return x;
}
inline void split(int x,int y)
{
    makeroot(x);
    access(y);
    splay(y);
}
inline void link(int x,int y)
{
    makeroot(x);
    makeroot(y);
    fa[x]=y;
    s[y][1]+=s[x][0];
}
inline void cut(int x,int y)
{
    makeroot(x);
    if(findroot(y)!=x||fa[y]!=x||ch[x][0])
        return;
    fa[y]=ch[x][1]=0;
    push_up(x);
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i)
        s[i][0]=1;
    for(int i=1;i<n;++i)
    {
        int x=read(),y=read(),w=read();
        v[w].emplace_back(x,y);
        link(x,y);
    }
    for(int i=1;i<=n;++i)
    {
        for(auto j:v[i])
            cut(j.first,j.second);
        for(auto j:v[i])
            ans+=1ll*s[findroot(j.first)][0]*s[findroot(j.second)][0];
        for(auto j:v[i])
            link(j.first,j.second);
    }
    cout<<ans<<'\n';
    return 0;
}