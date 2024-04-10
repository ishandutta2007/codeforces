//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
typedef long long ll;
const int Imx=2147483647;
const ll Lbig=2e18;
const int mod=1e9+7;
//My i/o stream
struct fastio
{
	char s[100000];
	int it,len;
	fastio(){it=len=0;}
	inline char get()
	{
		if(it<len)return s[it++];it=0;
		len=fread(s,1,100000,stdin);
		if(len==0)return EOF;else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while(c==' '||c=='\n')c=get();
		if(it>0)it--;
		return c!=EOF;
	}
}_buff;
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putchar(' ')
#define putii(x,y) puti(x),puti(y)
#define putiii(x,y,z) putii(x,y),puti(z)
#define putsi(x) putnum(x),putchar('\n')
#define putsii(x,y) puti(x),putsi(y)
#define putsiii(x,y,z) putii(x,y),putsi(z)
inline ll getnum()
{
	ll r=0;bool ng=0;char c;c=_buff.get();
	while(c!='-'&&(c<'0'||c>'9'))c=_buff.get();
	if(c=='-')ng=1,c=_buff.get();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=_buff.get();
	return ng?-r:r;
}
template<class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline char getreal(){char c=_buff.get();while(c==' '||c=='\n')c=_buff.get();return c;}
struct SGT
{
	struct node
	{
		int mx1,mcnt1,smx1;
		int mx2,mcnt2,smx2;
		ll sum;
		void init(){mx1=0;smx1=-1;mcnt1=0;mx2=0;smx2=-1;mcnt2=0;sum=0;}
		node(){init();}
	}a[400111];
	#define ls p<<1
	#define rs p<<1|1
	void update(int p,bool f1,bool f2)
	{
		if(f1)
		{
			if(a[ls].mx1==a[rs].mx1)a[p].mx1=a[ls].mx1,a[p].mcnt1=a[ls].mcnt1+a[rs].mcnt1,a[p].smx1=max(a[ls].smx1,a[rs].smx1);
			else if(a[ls].mx1>a[rs].mx1)a[p].mx1=a[ls].mx1,a[p].mcnt1=a[ls].mcnt1,a[p].smx1=max(a[ls].smx1,a[rs].mx1);
			else a[p].mx1=a[rs].mx1,a[p].mcnt1=a[rs].mcnt1,a[p].smx1=max(a[rs].smx1,a[ls].mx1);
		}
		if(f2)
		{
			if(a[ls].mx2==a[rs].mx2)a[p].mx2=a[ls].mx2,a[p].mcnt2=a[ls].mcnt2+a[rs].mcnt2,a[p].smx2=max(a[ls].smx2,a[rs].smx2);
			else if(a[ls].mx2>a[rs].mx2)a[p].mx2=a[ls].mx2,a[p].mcnt2=a[ls].mcnt2,a[p].smx2=max(a[ls].smx2,a[rs].mx2);
			else a[p].mx2=a[rs].mx2,a[p].mcnt2=a[rs].mcnt2,a[p].smx2=max(a[rs].smx2,a[ls].mx2);
		}
		a[p].sum=a[ls].sum+a[rs].sum;
	}
	void pushseg(int p,int m1,int m2)
	{
//		cerr<<"pushseg:"<<p<<" "<<m1<<" "<<m2<<" "<<a[p].smx1<<","<<a[p].mx1<<" "<<a[p].smx2<<","<<a[p].mx2<<endl;
		assert(m1>a[p].smx1);
		if(m1<a[p].mx1)a[p].sum-=1ll*a[p].mcnt1*(a[p].mx1-m1),a[p].mx1=m1;
		assert(m2>a[p].smx2);
		if(m2<a[p].mx2)a[p].sum-=1ll*a[p].mcnt2*(a[p].mx2-m2),a[p].mx2=m2;
	}
	void pushdown(int p)
	{
		pushseg(ls,a[p].mx1,a[p].mx2);
		pushseg(rs,a[p].mx1,a[p].mx2);
	}
	void modify(int x,int v1,int v2,int l,int r,int p=1)
	{
//		cerr<<"modify:"<<x<<" "<<v1<<" "<<v2<<" "<<l<<" "<<r<<" "<<p<<endl;
		if(x==l&&x==r)
		{
			a[p].mx1=v1;a[p].mcnt1=1;
			a[p].mx2=v2;a[p].mcnt2=1;
			a[p].smx1=a[p].smx2=0;
			a[p].sum=v1+v2;
			return;
		}
		pushdown(p);
		int m=l+r>>1;
		if(x<=m)modify(x,v1,v2,l,m,ls);
		else modify(x,v1,v2,m+1,r,rs);
		update(p,1,1);
	}
	void miniA(int x,int y,int k,int l,int r,int p=1)
	{
//		cerr<<"miniA:"<<x<<" "<<y<<" "<<k<<" "<<l<<" "<<r<<" "<<p<<endl;
		if(k>=a[p].mx1)return;
		if(l<r)pushdown(p);
		int m=l+r>>1;
		if(x<=l&&r<=y)
		{
			if(k>a[p].smx1)
			{
				a[p].sum-=1ll*a[p].mcnt1*(a[p].mx1-k);
				a[p].mx1=k;
			}
			else
			{
				miniA(x,y,k,l,m,ls);
				miniA(x,y,k,m+1,r,rs);
				update(p,1,0);
			}
			return;
		}
		if(x<=m)miniA(x,y,k,l,m,ls);
		if(m<y)miniA(x,y,k,m+1,r,rs);
		update(p,1,0);
	}
	void miniB(int x,int y,int k,int l,int r,int p=1)
	{
		if(k>=a[p].mx2)return;
		if(l<r)pushdown(p);
		int m=l+r>>1;
		if(x<=l&&r<=y)
		{
			if(k>a[p].smx2)
			{
				a[p].sum-=1ll*a[p].mcnt2*(a[p].mx2-k);
				a[p].mx2=k;
			}
			else
			{
				miniB(x,y,k,l,m,ls);
				miniB(x,y,k,m+1,r,rs);
				update(p,0,1);
			}
			return;
		}
		if(x<=m)miniB(x,y,k,l,m,ls);
		if(m<y)miniB(x,y,k,m+1,r,rs);
		update(p,0,1);
	}
	ll query(int x,int y,int l,int r,int p=1)
	{
		if(x<=l&&r<=y)return a[p].sum;
		pushdown(p);
		int m=l+r>>1;
		if(x<=m&&m<y)return query(x,y,l,m,ls)+query(x,y,m+1,r,rs);
		else if(x<=m)return query(x,y,l,m,ls);
		else return query(x,y,m+1,r,rs);
	}
	void out(int l,int r,int p=1)
	{
		cerr<<p<<":"<<l<<","<<r<<" "<<a[p].mx1<<","<<a[p].mcnt1<<" "<<a[p].smx1<<" "<<a[p].mx2<<","<<a[p].mcnt2<<" "<<a[p].smx2<<" "<<a[p].sum<<endl;
		if(l==r)return;
		int m=l+r>>1;
		out(l,m,ls);
		out(m+1,r,rs);
	}
}sgt;
struct SGT2
{
	int a[400111];
	SGT2(){memset(a,63,sizeof(a));}
	int mini(int x,int y,int k,int l,int r,int p=1)
	{
		if(x<=l&&r<=y)
		{
			a[p]=min(a[p],k);
			return 0;
		}
		int m=l+r>>1;
		if(x<=m)mini(x,y,k,l,m,ls);
		if(m<y)mini(x,y,k,m+1,r,rs);
	}
	int query(int x,int l,int r,int p=1)
	{
		int ans=a[p];
		if(x==l&&x==r)return ans;
		int m=l+r>>1;
		if(x<=m)return min(query(x,l,m,ls),ans);
		else return min(query(x,m+1,r,rs),ans);
	}
}cura,curb;
int mxn=100005;
int q;
int fa[100111],fb[100111];
int gfa(int x){return fa[x]==x?x:fa[x]=gfa(fa[x]);}
int gfb(int x){return fb[x]==x?x:fb[x]=gfb(fb[x]);}
bool useda[100111],usedb[100111];
void acti(int x)
{
	int ca=cura.query(x,1,mxn);
	int cb=curb.query(x,1,mxn);
//	cerr<<"acti:"<<x<<" "<<ca<<" "<<cb<<endl;
	sgt.modify(x,ca,cb,1,mxn);
}
void minia(int l,int r,int k)
{
	cura.mini(l,r,k,1,mxn);
	for(int i=gfa(l);i<=r;i=gfa(i))
	{
		if(usedb[i])acti(i);
		useda[i]=1;
		fa[gfa(i)]=gfa(i+1);
	}
}
void minib(int l,int r,int k)
{
	curb.mini(l,r,k,1,mxn);
	for(int i=gfb(l);i<=r;i=gfb(i))
	{
		if(useda[i])acti(i);
		usedb[i]=1;
		fb[gfb(i)]=gfb(i+1);
	}
}

int main()
{
//	freopen("855F.in","r",stdin);
//	freopen("855F-sgtb.out","w",stdout);
	for(int i=1;i<=mxn;i++)fa[i]=fb[i]=i;
	geti(q);
	while(q--)
	{
		int cmd,l,r;
		getiii(cmd,l,r);r--;
//		cerr<<"------------cmd="<<cmd<<endl;
		if(cmd==1)
		{
			int k;
			geti(k);
			if(k<0)minib(l,r,-k),sgt.miniB(l,r,-k,1,mxn);
			else minia(l,r,k),sgt.miniA(l,r,k,1,mxn);
			
		}
		else
		{
			ll ans=sgt.query(l,r,1,mxn);
			putsi(ans);
		}
//		sgt.out(1,mxn);
	}
	return 0;
}