#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>

#define int long long
#define lowbit(x) (x&(-x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
#define fan(x) (((x-1)^1)+1)
#define max Max
#define min Min
#define abs Abs

using namespace std;

inline int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<1)+(ans<<3)+c-'0';c=getchar();}
	return ans*f;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a>b?b:a;}
template<typename T,typename TT> inline T Max(T a,TT b){return a>b?a:b;}

const int N=2e5+5;
int t,n,q;
char s[N],f[N];

struct Seg
{
    int val[N*4],lazy[N*4];
    inline void pushup(int x)
    {
        val[x]=val[lc]+val[rc];
    }
    inline void pushdown(int x,int l,int r)
    {
        if(lazy[x]!=-1)
        {
            val[lc]=lazy[x]*(mid-l+1);
            val[rc]=lazy[x]*(r-mid);
            lazy[lc]=lazy[x];
            lazy[rc]=lazy[x];
        }
        lazy[x]=-1;
    }
    void build(int x,int l,int r)
    {
        if(l==r)
        {
            val[x]=f[l]-'0';
            return;
        }
        build(lc,l,mid);
        build(rc,mid+1,r);
        pushup(x);
        lazy[x]=-1;
    }
    void update(int x,int l,int r,int L,int R,int v)
    {
        if(L<=l&&r<=R)
        {
            val[x]=(r-l+1)*v;
            lazy[x]=v;
            return;
        }
        pushdown(x,l,r);
        if(L<=mid) update(lc,l,mid,L,R,v);
        if(mid+1<=R) update(rc,mid+1,r,L,R,v);
        pushup(x);
        return;
    }
    int query(int x,int l,int r,int L,int R)
    {
        if(L<=l&&r<=R) return val[x];
        int res=0;
        pushdown(x,l,r);
        if(L<=mid) res+=query(lc,l,mid,L,R);
        if(mid+1<=R) res+=query(rc,mid+1,r,L,R);
        return res;
    }
}a;

struct Qus
{
    int l,r;
}b[N];

signed main()
{
	t=read();
    while(t--)
    {
        n=read();q=read();
        scanf("%s",s+1);
        scanf("%s",f+1);
        a.build(1,1,n);
        for(int i=1;i<=q;++i)
            b[i].l=read(),b[i].r=read();
        int flag=1;
        for(int i=q;i>=1;--i)
        {
            int x=a.query(1,1,n,b[i].l,b[i].r);
            int y=b[i].r-b[i].l+1-x;
            if(x==y)
            {
                flag=0;
                break;
            }
            if(x<y) a.update(1,1,n,b[i].l,b[i].r,0);
            else a.update(1,1,n,b[i].l,b[i].r,1);
        }
        for(int i=1;i<=n;++i)
            if(a.query(1,1,n,i,i)!=s[i]-'0')
                flag=0;
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
	return 0;
}