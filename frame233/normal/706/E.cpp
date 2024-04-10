// luogu-judger-enable-o2
// Author -- Frame
 
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
 
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
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const double &a,const double &b){return abs(a-b)<=eps;}
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
    while(ch<65||ch>122||(ch>90&&ch<97)) ch=getchar();
    register char *tar=s;
    *tar=ch,ch=getchar();
    while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) *(++tar)=ch,ch=getchar();
    return tar-s+1;
}
 
const int N=1005;
int n,m;
Finline int id(const int &x,const int &y)
{
    return x*(m+2)+y+1;
}
struct node{
    int val;
    int l,r,u,d;
}p[N*N];
int GetId(int x,int y)
{
    int cur=id(x,0);
    for(int i=1;i<=y;++i) cur=p[cur].r;
    return cur;
}
void solve(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
    int a=GetId(x1,y1),b=GetId(x1,y2);
    int c=GetId(x3,y3),d=GetId(x3,y4);
    int A=GetId(x1,y1),B=GetId(x2,y1);
    int C=GetId(x3,y3),D=GetId(x4,y3);
    for(int i=x1;i<=x2;++i)
    {
        std::swap(p[p[a].l].r,p[p[c].l].r);
        std::swap(p[p[b].r].l,p[p[d].r].l);
        std::swap(p[a].l,p[c].l);
        std::swap(p[b].r,p[d].r);
        a=p[a].d,b=p[b].d;
        c=p[c].d,d=p[d].d;
    }
    for(int i=y1;i<=y2;++i)
    {
        std::swap(p[p[A].u].d,p[p[C].u].d);
        std::swap(p[p[B].d].u,p[p[D].d].u);
        std::swap(p[A].u,p[C].u);
        std::swap(p[B].d,p[D].d);
        A=p[A].r,B=p[B].r;
        C=p[C].r,D=p[D].r;
    }
}
void print()
{
    for(int i=1;i<=n;++i)
    {
        int cur=id(i,0);
        for(int j=1;j<=m;++j)
        {
            cur=p[cur].r;
            printf("%d ",p[cur].val);
        }
        printf("\n");
    }
}
int main()
{
    int q,x;
    read(n,m,q);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            read(x);
            p[id(i,j)]=(node){x,id(i,j-1),id(i,j+1),id(i-1,j),id(i+1,j)};
        }
    }
    for(int i=1;i<=m;++i)
    {
        p[id(0,i)]=(node){0,id(0,i-1),id(0,i+1),0,id(1,i)};
        p[id(n+1,i)]=(node){0,id(n+1,i-1),id(n+1,i+1),id(n,i),0};
    }
    for(int i=1;i<=n;++i)
    {
        p[id(i,0)]=(node){0,0,id(i,1),id(i-1,0),id(i+1,0)};
        p[id(i,m+1)]=(node){0,id(i,m),0,id(i-1,m+1),id(i+1,m+1)};
    }
    p[id(0,0)]=(node){0,0,id(0,1),0,id(1,0)};
    p[id(0,m+1)]=(node){0,id(0,m),0,0,id(1,m+1)};
    p[id(n+1,0)]=(node){0,0,id(n+1,1),id(n,0),0};
    p[id(n+1,m+1)]=(node){0,id(n+1,m),0,id(n,m+1),0};
    int a,b,c,d,h,w;
    while(q--)
    {
        read(a,b,c,d,h,w);
        solve(a,b,a+h-1,b+w-1,c,d,c+h-1,d+w-1);
    }
    print();
    return 0;
}