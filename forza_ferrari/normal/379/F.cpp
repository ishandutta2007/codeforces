#include<iostream>
#include<cstdio>
using namespace std;
int tot,n,fa[1000005],ch[1000005][2],s[1000005],top,stack[1000005],bin[1000005],maxn[1000005][2];
bool tag[1000005];
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
    s[x]=s[ch[x][0]]+s[ch[x][1]]+1;
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
    for(register int y=0;x;x=fa[y=x])
    {
        splay(x);
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
inline void LCT_link(int x,int y)
{
    makeroot(x);
    if(findroot(y)!=x)
        fa[x]=y;
}
int anc(int k)
{
    if(!bin[k])
        return k;
    return bin[k]=anc(bin[k]);
}
inline int dis(int x,int y)
{
    split(x,y);
    return s[y];
}
inline void link(int x,int y)
{
    x=anc(x);
    y=anc(y);
    if(x^y)
    {
        bin[y]=x;
        int a=maxn[x][0],b=maxn[x][1],c=maxn[y][0],d=maxn[y][1];
        if(dis(a,b)>dis(maxn[x][0],maxn[x][1]))
        {
            maxn[x][0]=a;
            maxn[x][1]=b;
        }
        if(dis(a,c)>dis(maxn[x][0],maxn[x][1]))
        {
            maxn[x][0]=a;
            maxn[x][1]=c;
        }
        if(dis(a,d)>dis(maxn[x][0],maxn[x][1]))
        {
            maxn[x][0]=a;
            maxn[x][1]=d;
        }
        if(dis(b,c)>dis(maxn[x][0],maxn[x][1]))
        {
            maxn[x][0]=b;
            maxn[x][1]=c;
        }
        if(dis(b,d)>dis(maxn[x][0],maxn[x][1]))
        {
            maxn[x][0]=b;
            maxn[x][1]=d;
        }
        if(dis(c,d)>dis(maxn[x][0],maxn[x][1]))
        {
            maxn[x][0]=c;
            maxn[x][1]=d;
        }
    }
}
int main()
{
    n=read();
    for(int i=1;i<=(n<<1)+4;++i)
        maxn[i][0]=maxn[i][1]=i;
    tot=4;
    LCT_link(1,2);
    LCT_link(1,3);
    LCT_link(1,4);
    link(1,2);
    link(1,3);
    link(1,4);
    while(n--)
    {
        int x=read();
        LCT_link(x,++tot);
        link(x,tot);
        LCT_link(x,++tot);
        link(x,tot);
        int f=anc(x),a=maxn[f][0],b=maxn[f][1];
        cout<<dis(a,b)-1<<'\n';
    }
    return 0;
}