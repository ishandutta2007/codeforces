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
const ll INF=0x7ffffffffffffff;
const double eps=1e-8;

uint seed=19260817;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}
Finline bool _cmp(const double &a,const double &b){return abs(a-b)<=eps;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool ismax(_Tp &a,const _Tp &b){return a>=b?1:a=b,0;}
template <typename _Tp>Finline bool ismin(_Tp &a,const _Tp &b){return a<=b?1:a=b,0;}
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

const int N=200005,mod=1000000007;
struct node{
    int in,out;
    Finline bool operator < (const node &o)const
    {
        return in<o.in;
    }
}a[N];
Finline void add(int &a,const int &b){(a+=b)>=mod&&(a-=mod);}
struct seg_tr{
    struct node{
        int ls,rs;
        ll minn;
        int sum;
        Finline node(){minn=INF;}
    }f[N<<2];
    int node_cnt;
    Finline void PushUp(const int &x)
    {
        if(f[f[x].ls].minn<f[f[x].rs].minn)
        {
            f[x].minn=f[f[x].ls].minn;
            f[x].sum=f[f[x].ls].sum;
        }
        else if(f[f[x].ls].minn>f[f[x].rs].minn)
        {
            f[x].minn=f[f[x].rs].minn;
            f[x].sum=f[f[x].rs].sum;
        }
        else
        {
            f[x].minn=f[f[x].ls].minn;
            f[x].sum=(f[f[x].ls].sum+f[f[x].rs].sum)%mod;
        }
    }
    int build(const int &l,const int &r)
    {
        int cur=++node_cnt;
        if(l==r) return cur;
        int mid=(l+r)>>1;
        f[cur].ls=build(l,mid);
        f[cur].rs=build(mid+1,r);
        return cur;
    }
    void Update(const int &pos,const int &l,const int &r,const int &cur,const ll &val,const int &tot)
    {
        if(l==r)
        {
            if(f[cur].minn>val)
            {
                f[cur].minn=val;
                f[cur].sum=tot;
            }
            else if(f[cur].minn==val)
            {
                add(f[cur].sum,tot);
            }
            return;
        }
        int mid=(l+r)>>1;
        if(pos<=mid) Update(pos,l,mid,f[cur].ls,val,tot);
        else Update(pos,mid+1,r,f[cur].rs,val,tot);
        PushUp(cur);
    }
    std::pair<ll,int> Query(const int &L,const int &R,const int &l,const int &r,const int &cur)
    {
        if(L<=l&&r<=R)
        {
            return std::make_pair(f[cur].minn,f[cur].sum);
        }
        int mid=(l+r)>>1;
        std::pair<ll,int> Lt=L<=mid?Query(L,R,l,mid,f[cur].ls):std::make_pair(INF,0);
        std::pair<ll,int> Rt=R>mid?Query(L,R,mid+1,r,f[cur].rs):std::make_pair(INF,0);
        if(Lt.first<Rt.first) return Lt;
        if(Lt.first>Rt.first) return Rt;
        return std::make_pair(Lt.first,(Lt.second+Rt.second)%mod);
    }
}tr;
int f[N],g[N];
int t[N<<1];
Finline bool cmp(const int &a,const node &b){return a<b.out;}
int main()
{
    int n;
    read(n);
    int pos=0;
    for(int i=1;i<=n;++i)
    {
        read(a[i].out,a[i].in);
        t[++pos]=a[i].in;
        t[++pos]=a[i].out;
    }
    std::sort(t+1,t+pos+1);
    int len=std::unique(t+1,t+pos+1)-t-1;
    for(int i=1;i<=n;++i)
    {
        a[i].in=std::lower_bound(t+1,t+len+1,a[i].in)-t;
        a[i].out=std::lower_bound(t+1,t+len+1,a[i].out)-t;
    }
    std::sort(a+1,a+n+1);
    int root=tr.build(0,len);
    tr.Update(0,0,len,root,0,1);
    for(int i=1;i<=n;++i)
    {
        std::pair<ll,int> tmp=tr.Query(0,a[i].in,0,len,root);
        f[i]=tmp.first+t[a[i].in];
        g[i]=tmp.second;
        tr.Update(a[i].out,0,len,root,f[i]-t[a[i].out],g[i]);
    }
    int ans=0;
    ll res=INF;
    for(int i=n;i>=1;--i)
    {
        if(a[i].out>a[n].in)
        {
            if(res>f[i])
            {
                res=f[i];
                ans=g[i];
            }
            else if(res==f[i])
            {
                add(ans,g[i]);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}