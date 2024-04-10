#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=200010;
ll ans;
int n,m,tot;
int to[maxn],val[maxn],rt[maxn],f[maxn],v[maxn],bel[maxn];
vector<int> p[2][maxn];
vector<int>::iterator it;
struct node
{
    int ch[2],siz;
}s[maxn*61];
inline void insert(int &x,int z,int w)
{
    if(!x)  x=++tot;
    int i,u=x,d;
    for(i=29;~i;i--)
    {
        d=(w>>i)&1;
        if(!s[u].ch[d]) s[u].ch[d]=++tot;
        u=s[u].ch[d],s[u].siz++;
    }
    s[u].siz=z;
}
inline void query(int x,int y,int z,int w)
{
    int i,d,ret=0;
    for(i=29;~i;i--)
    {
        d=(w>>i)&1;
        if(s[s[x].ch[d]].siz==s[s[y].ch[d]].siz)    d^=1,ret|=(1<<i);
        x=s[x].ch[d],y=s[y].ch[d];
    }
    if(ret<val[z])   val[z]=ret,to[z]=s[x].siz;
}
int find(int x)
{
    return (f[x]==x)?x:(f[x]=find(f[x]));
}
inline int rd()
{
    int ret=0,f=1;  char gc=getchar();
    while(gc<'0'||gc>'9') {if(gc=='-')    f=-f;   gc=getchar();}
    while(gc>='0'&&gc<='9')   ret=ret*10+(gc^'0'),gc=getchar();
    return ret*f;
}
int main()
{
    n=rd();
    int i,d=0;
    for(i=1;i<=n;i++)    v[i]=rd();
    sort(v+1,v+n+1);
    for(i=1;i<=n;i++)    if(i==1||v[i]>v[i-1])    p[0][++m].push_back(v[i]);
    while(m>1)
    {
        n=m,m=0,memset(val,0x3f,sizeof(val[0])*(n+1)),memset(rt,0,sizeof(rt[0])*(n+1));
        memset(s,0,sizeof(s[0])*(tot+1)),tot=0;
        for(i=1;i<=n;i++)    for(it=p[d][i].begin();it!=p[d][i].end();it++)  insert(rt[i],i,*it),insert(rt[0],i,*it);
        for(i=1;i<=n;i++)    for(it=p[d][i].begin();it!=p[d][i].end();it++)  query(rt[0],rt[i],i,*it);
        for(i=1;i<=n;i++)    p[d^1][i].clear(),f[i]=i;
        for(i=1;i<=n;i++)    if(find(to[i])!=find(i))    f[f[i]]=f[to[i]],ans+=val[i];
        for(i=1;i<=n;i++)    if(find(i)==i)  bel[i]=++m;
        for(i=1;i<=n;i++)    for(it=p[d][i].begin();it!=p[d][i].end();it++)  p[d^1][bel[f[i]]].push_back(*it);
        d^=1;
    }
    printf("%I64d",ans);
    return 0;
}