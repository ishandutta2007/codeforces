#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
 
struct node { ll x,y; }a[300010];
 
int n;
 
inline ll rd()
{
    ll x=0,f=1;char ch=getchar();
    for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
    for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
    return x*f;
}
 
inline void print(ll x)
{
    static char s[233];
    if (!x) { putchar('0');putchar('\n');return; }
    int tot=0;
    for (;x;x/=10) s[++tot]=x%10+'0';
    for (;tot;tot--) putchar(s[tot]);
    putchar('\n');
}
 
ll num[300010],tag[300010];
int ch[300010][2],fa[300010],size[300010],tot,root;
 
inline int newnode(ll x)
{
    int now=++tot;
    size[now]=1;num[now]=x;tag[now]=0;
    return now;
}
 
inline void gao(int o,ll hh) { num[o]+=hh;tag[o]+=hh; }
 
inline void pushdown(int o)
{
    if (!tag[o]) return;
    if (ch[o][0]) gao(ch[o][0],tag[o]);
    if (ch[o][1]) gao(ch[o][1],tag[o]);
    tag[o]=0;
}
 
inline void pushup(int o) { size[o]=size[ch[o][0]]+size[ch[o][1]]+1; }
 
inline ll calc(int sz,ll a,ll b) { return a*sz+b; }
 
inline pii split(int x,ll a,ll b,int sz)
{
    if (!x) return pii(0,0);
    pushdown(x);
    if (num[x]<calc(size[ch[x][0]]+sz,a,b))
    {
        pii hh=split(ch[x][0],a,b,sz);
        ch[x][0]=hh.second;hh.second=x;
        pushup(x);return hh;
    }
    else
    {
        pii hh=split(ch[x][1],a,b,sz+size[ch[x][0]]+1);
        ch[x][1]=hh.first;hh.first=x;
        pushup(x);return hh;
    }
}
 
inline int merge(int x,int y)
{
    if (!x||!y) return x|y;
    pushdown(x);pushdown(y);
    if (rand()%(size[x]+size[y])<size[x]) { ch[x][1]=merge(ch[x][1],y);pushup(x);return x; }
    else { ch[y][0]=merge(x,ch[y][0]);pushup(y);return y; }
}
 
ll c[300010];
int tt=0;
 
inline void dfs(int x)
{
    pushdown(x);
    if (ch[x][0]) dfs(ch[x][0]);
    c[++tt]=num[x];
    if (ch[x][1]) dfs(ch[x][1]);
}
 
inline bool cmp(const node &x,const node &y) { return (x.x<y.x); }
 
int main()
{
    srand(19260816);
    n=rd();
    for (int i=1;i<=n;i++) a[i].x=rd(),a[i].y=a[i].x;
    tot=root=0;
    for (int i=1;i<=n;i++)
    {
        pii hh=split(root,a[i].x,a[i].y,0);
        int now=newnode(calc(size[hh.first],a[i].x,a[i].y));
        if (hh.second) gao(hh.second,a[i].x);
        root=merge(merge(hh.first,now),hh.second);
    }
    dfs(root);
    for (int i=1;i<=n;i++) c[i]+=c[i-1];
    ll ans=0;
    for (int i=0;i<=n;i++) ans=max(ans,c[i]);
    printf("%lld\n",ans);
    return 0;
}