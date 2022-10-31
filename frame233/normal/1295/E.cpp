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
 
const int N=200005;
int p[N],a[N];
struct seg_tr{
    struct Node{
        int ls,rs;
        ll tag;
        ll minn;
    }f[N<<1];
    int node_cnt;
    Finline void PushUp(int x)
    {
        f[x].minn=min(f[f[x].ls].minn,f[f[x].rs].minn);
    }
    int build(int l,int r)
    {
        int cur=++node_cnt;
        if(l==r) return cur;
        int mid=(l+r)>>1;
        f[cur].ls=build(l,mid);
        f[cur].rs=build(mid+1,r);
        return cur;
    }
    Finline void add(int cur,ll val)
    {
        f[cur].minn+=val;
        f[cur].tag+=val;
    }
    Finline void PushDown(int cur)
    {
        if(f[cur].tag)
        {
            add(f[cur].ls,f[cur].tag);
            add(f[cur].rs,f[cur].tag);
            f[cur].tag=0;
        }
    }
    void Update(int L,int R,int l,int r,int cur,ll val)
    {
        if(L<=l&&r<=R)
        {
            add(cur,val);
            return;
        }
        PushDown(cur);
        int mid=(l+r)>>1;
        if(L<=mid) Update(L,R,l,mid,f[cur].ls,val);
        if(R>mid) Update(L,R,mid+1,r,f[cur].rs,val);
        PushUp(cur);
    }
    Finline ll Query(){return f[1].minn;}
}tr;
int main()
{
	int n;
    read(n);
    tr.build(0,n);
    for(int i=1;i<=n;++i)
    {
        read(p[i]);
    }
    for(int i=1;i<=n;++i)
    {
        read(a[i]);
        tr.Update(p[i],n,0,n,1,a[i]);
    }
    ll ans=INF;
    for(int i=1;i<n;++i)
    {
        tr.Update(0,p[i]-1,0,n,1,a[i]);
        tr.Update(p[i],n,0,n,1,-a[i]);
        chmin(ans,tr.Query());
    }
    printf("%lld\n",ans);
    return 0;
}