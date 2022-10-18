#include<iostream>
#include<cstdio>
#include<algorithm>
#include<ctime>
using namespace std;
#define int long long
const int mod=998244353;
int t,n,m,tot,root,ch[2000001][2],val[2000001],key[2000001],s[2000001],tag[2000001],fac[4000001],inv[4000001];
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
inline int pw(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)
            res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}
inline int c(int x,int y)
{
    if(x<y)
        return 0;
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
inline int newnode(int w)
{
    s[++tot]=1;
    val[tot]=w;
    key[tot]=rand();
    tag[tot]=ch[tot][0]=ch[tot][1]=0;
    return tot;
}
inline void push_up(int k)
{
    if(k)
        s[k]=s[ch[k][0]]+s[ch[k][1]]+1;
}
inline void push_down(int k)
{
    if(k&&tag[k])
    {
        if(ch[k][0])
        {
            val[ch[k][0]]+=tag[k];
            tag[ch[k][0]]+=tag[k];
        }
        if(ch[k][1])
        {
            val[ch[k][1]]+=tag[k];
            tag[ch[k][1]]+=tag[k];
        }
        tag[k]=0;
    }
}
int merge(int x,int y)
{
    if(!x||!y)
        return x+y;
    if(key[x]<key[y])
    {
        push_down(x);
        ch[x][1]=merge(ch[x][1],y);
        push_up(x);
        return x;
    }
    push_down(y);
    ch[y][0]=merge(x,ch[y][0]);
    push_up(y);
    return y;
}
void split(int node,int k,int &x,int &y)
{
    if(!node)
    {
        x=y=0;
        return;
    }
    push_down(node);
    if(val[node]<=k)
    {
        x=node;
        split(ch[node][1],k,ch[node][1],y);
    }
    else
    {
        y=node;
        split(ch[node][0],k,x,ch[node][0]);
    }
    push_up(node);
}
bool find(int node,int k)
{
    if(!node)
        return 0;
    if(val[node]==k)
        return 1;
    push_down(node);
    if(k<val[node])
        return find(ch[node][0],k);
    return find(ch[node][1],k);
}
signed main()
{
    srand(time(NULL));
    t=read();
    fac[0]=inv[0]=1;
    for(register int i=1;i<=400000;++i)
        fac[i]=fac[i-1]*i%mod;
    inv[400000]=pw(fac[400000],mod-2);
    for(register int i=399999;i;--i)
        inv[i]=inv[i+1]*(i+1)%mod;
    while(t--)
    {
        root=tot=0;
        n=read(),m=read();
        for(register int i=1;i<=m;++i)
        {
            read();
            int w=read(),x=0,y=0;
            bool flag=find(root,w);
            split(root,w-1,x,y);
            if(y)
            {
                ++val[y];
                ++tag[y];
            }
            root=merge(flag? x:merge(x,newnode(w+1)),y);
        }
        printf("%lld\n",c(n+n-1-tot,n));
    }
    return 0;
}