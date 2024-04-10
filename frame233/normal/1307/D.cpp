// Author -- Frame

#pragma GCC optimize(2)

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>
#include<map>
#include<bitset>
#include<queue>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-8;

uint seed=19260817;
const uint _RAND_MAX_=4294967295u;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp& x)
{
    register char ch(getchar());
    bool f(false);
    while(ch<48||ch>57) f|=ch==45,ch=getchar();
    x=ch&15,ch=getchar();
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
    if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args)
{
    read(t);read(args...);
}
Finline int read_str(char *s)
{
    register char ch(getchar());
    while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
    register char *tar=s;
    *tar=ch,ch=getchar();
    while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
    return tar-s+1;
}

const int N=400005;
struct node{
    int u,d;
    Finline bool operator < (const node &o)const
    {
        return d>o.d;
    }
};
std::priority_queue<node> q;
int dis1[N],dis2[N];
struct edge{
    int v,nxt;
}c[N];
int front[N],cnt;
Finline void add(int u,int v)
{
    c[++cnt]=(edge){v,front[u]},front[u]=cnt;
}
void dij(int S,int *dis)
{
    while(!q.empty()) q.pop();
    dis[S]=0;
    q.push((node){S,0});
    while(!q.empty())
    {
        node x=q.top();
        q.pop();
        if(dis[x.u]!=x.d) continue;
        for(int i=front[x.u];i;i=c[i].nxt)
        {
            if(dis[c[i].v]>dis[x.u]+1)
            {
                dis[c[i].v]=dis[x.u]+1;
                q.push((node){c[i].v,dis[c[i].v]});
            }
        }
    }
}
int p[N];
struct Node{
    int x,y,D;
    Finline bool operator < (const Node &o)const
    {
        return D<o.D;
    }
}a[N];
int maxx[N];
int minn[N];
int main()
{
	int n,m,k;
    read(n,m,k);
    for(int i=1;i<=k;++i) read(p[i]);
    int x,y;
    for(int i=1;i<=m;++i)
    {
        read(x,y);
        add(x,y),add(y,x);
    }
    memset(dis1,63,sizeof(dis1));
    memset(dis2,63,sizeof(dis2));
    dij(1,dis1);
    dij(n,dis2);
    for(int i=1;i<=k;++i)
    {
        a[i]=(Node){dis1[p[i]],dis2[p[i]],dis1[p[i]]-dis2[p[i]]};
    }
    std::sort(a+1,a+k+1);
    minn[1]=a[1].x;
    for(int i=2;i<=k;++i)
    {
        minn[i]=max(minn[i-1],a[i].x);
    }
    maxx[k]=a[k].y;
    for(int i=k-1;i>=1;--i)
    {
        maxx[i]=max(maxx[i+1],a[i].y);
    }
    int ans=0;
    for(int i=1;i<=k;++i)
    {
        if(i<k) chmax(ans,a[i].x+maxx[i+1]);
        if(i>1) chmax(ans,a[i].y+minn[i-1]);
    }
    ++ans;
    chmin(ans,dis1[n]);
    printf("%d\n",ans);
    return 0;
}