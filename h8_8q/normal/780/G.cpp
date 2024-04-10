#include<bits/stdc++.h>

#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)

using namespace std;

namespace fastIO
{
    #define BUF_SIZE 100000
    bool IOerror=0;
    inline char nc()
	{
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
        if (p1==pend){
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin);
            if (pend==p1){IOerror=1;return -1;}
        }
        return *p1++;
    }
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
    inline int read()
	{
        bool sign=0; char ch=nc();int x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return 0;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
        return x;
    }
    #undef BUF_SIZE
};

using namespace fastIO;

const int N=4e5+5,mod=1e9+7;
int n,m,k,p,c[N];
long long dp[N];

struct Node
{
	int x,l,r,s,l1,l2;
	bool operator < (const Node &p)const
	{
		return x<p.x;
	}
}a[N];

struct Qus
{
	int opt,id,h,res;
	bool operator < (const Qus &p)const
	{
		return h>p.h;
	}
}b[N];

struct Seg
{
	int val[N*4];
	void build(int x,int l,int r)
	{
		val[x]=0;
		if(l==r) return;
		build(lc,l,mid);
		build(rc,mid+1,r);
	}
	inline void pushdown(int x)
	{
		if(a[val[x]].x>a[val[lc]].x)
			val[lc]=val[x];
		if(a[val[x]].x>a[val[rc]].x)
			val[rc]=val[x];
	}
	void update(int x,int l,int r,int L,int R,int v)
	{
		if(L<=l&&r<=R)
		{
			if(a[v].x>a[val[x]].x)
				val[x]=v;
			return;
		}
		pushdown(x);
		if(L<=mid) update(lc,l,mid,L,R,v);
		if(mid+1<=R) update(rc,mid+1,r,L,R,v);
	}
	int query(int x,int l,int r,int v)
	{
		if(l==r) return val[x];
		pushdown(x);
		if(v<=mid) return query(lc,l,mid,v);
		else return query(rc,mid+1,r,v);
	}
}sum;

void CDQ(int l,int r);

signed main()
{
	//freopen("fall.in","r",stdin);
	//freopen("fall.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=k;++i)
	{
		a[i].x=read();
		a[i].l=read();
		a[i].r=read();
		a[i].s=read();
		a[i].l1=a[i].l2=-1;
	}
	sort(a+1,a+1+k);
	for(int i=1;i<=k;++i)
	{
		if(a[i].l!=1) b[++p]=(Qus){i,a[i].l-1,a[i].x,0};
		if(a[i].r!=m) b[++p]=(Qus){i,a[i].r+1,a[i].x,0};
		b[++p]=(Qus){0,i,a[i].x+a[i].s,0};
	}
	for(int i=1;i<=m;++i)
		b[++p]=(Qus){-1,i,n+1,0};
	CDQ(1,p);
	for(int i=1;i<=p;++i)
		if(b[i].opt>0)
		{
			if(a[b[i].opt].l1==-1)
				a[b[i].opt].l1=b[i].res;
			else a[b[i].opt].l2=b[i].res;
		}
	for(int i=1;i<=k;++i)
		if(a[i].l2==-1)
			a[i].l2=a[i].l1;
	dp[0]=1;
	for(int i=1;i<=k;++i)
		dp[i]=(dp[a[i].l1]+dp[a[i].l2])%mod;
	long long ans=0;
	for(int i=1;i<=p;++i)
		if(b[i].opt==-1)
			ans=(ans+dp[b[i].res])%mod;
	printf("%lld\n",ans);
	return 0;
}

void CDQ(int l,int r)
{
	if(l==r) return;
	CDQ(l,mid);CDQ(mid+1,r);
	sort(b+l,b+mid+1);
	sort(b+mid+1,b+r+1);
	int qwq=0;
	for(int i=l;i<=mid;++i)
		if(!b[i].opt)
		{
			c[++qwq]=a[b[i].id].l;
			c[++qwq]=a[b[i].id].r;
		}
	for(int i=mid+1;i<=r;++i)
		if(b[i].opt) c[++qwq]=b[i].id;
	if(qwq==0) return;
	sort(c+1,c+1+qwq);
	qwq=unique(c+1,c+1+qwq)-c-1;
	int now=l-1;
	sum.build(1,1,qwq);
	for(int i=mid+1;i<=r;++i)
		if(b[i].opt)
		{
			while(now<mid&&(b[now+1].h>=b[i].h||b[now+1].opt))
			{
				++now;
				if(!b[now].opt)
				{
					int L=lower_bound(c+1,c+1+qwq,a[b[now].id].l)-c;
					int R=lower_bound(c+1,c+1+qwq,a[b[now].id].r)-c;
					sum.update(1,1,qwq,L,R,b[now].id);
				}
			}
			int ID=lower_bound(c+1,c+1+qwq,b[i].id)-c;
			int tmp=sum.query(1,1,qwq,ID);
			if(a[tmp].x>a[b[i].res].x)
				b[i].res=tmp;
		}
}