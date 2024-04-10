//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
typedef long long ll;
const int Imx=2147483647;
const int mod=1000000007;
const ll Lbg=2e18;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
inline ll getnum()
{
	register ll r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=getchar();
	if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
#define fm(x) ((x)>=mod?(x)-mod:(x))
int ia[100111],ib[100111];
struct node
{
	ll sa,sb,ssa,ssb;
	int cnt;
	node(){sa=sb=ssa=ssb=cnt=0;}
};
struct FruitCandy
{
	node a[400111];
	int n;
	#define ls p<<1
	#define rs p<<1|1
	node merge(const node &l,const node &r)const
	{
		node ret;
		ret.sa=fm(l.sa+r.sa);
		ret.sb=fm(l.sb+r.sb);
		ret.cnt=l.cnt+r.cnt;
		ret.ssa=(l.ssa+r.ssa+1ll*l.sa*r.cnt)%mod;
		ret.ssb=(l.ssb+r.ssb+1ll*r.sb*l.cnt)%mod;
		return ret;
	}
	void update(int p)
	{
		a[p]=merge(a[ls],a[rs]);
	}
	void build(int l,int r,int p)
	{
		if(l==r)
		{
			a[p].sa=a[p].ssa=ia[l];
			a[p].sb=a[p].ssb=ib[l];
			a[p].cnt=1;
			return;
		}
		int m=l+r>>1;
		build(l,m,ls);
		build(m+1,r,rs);
		update(p);
	}
	int Build(int N)
	{
		n=N;
		build(1,n,1);
	}
	int x,y;
	void change(int l,int r,int p)
	{
		if(l==x&&r==x)
		{
			if(a[p].cnt)
			{
				a[p].cnt=a[p].sa=a[p].sb=a[p].ssa=a[p].ssb=0;
			}
			else
			{
				a[p].sa=a[p].ssa=ia[l];
				a[p].sb=a[p].ssb=ib[l];
				a[p].cnt=1;
			}
			return;
		}
		int m=l+r>>1;
		if(x<=m)change(l,m,ls);else change(m+1,r,rs);
		update(p);
	}
	void Change(int X)
	{
		x=X;
		change(1,n,1);
	}
	node query(int l,int r,int p)
	{
		if(x<=l&&r<=y)return a[p];
		int m=l+r>>1;
		if(x<=m&&m<y)return merge(query(l,m,ls),query(m+1,r,rs));
		else if(x<=m)return query(l,m,ls);
		else return query(m+1,r,rs);
	}
	node Query(int X,int Y)
	{
		x=X;y=Y;
		if(x>y)return node();
		return query(1,n,1);
	}
}sgt;
int n,a[100111],b[100111],c[100111];
ll suma[100111],sumb[100111];
int hsv[100111],hsn;
struct BIT
{
	int a[100111];
	void init(){memset(a,0,sizeof(a));}
	void add(int x)
	{
		for(int i=x;i<100100;i+=i&(-i))a[i]++;
	}
	int query(int x)
	{
		int ret=0;
		for(int i=x;i>0;i-=i&(-i))ret+=a[i];
		return ret;
	}
}A;
pair<int,int> pp[100111];
int id[100111],idl[100111],idr[100111];
ll calcdlt(int x)
{
//	cout<<"calcdlt:"<<x<<endl;
	node tl,tr;
	tl=sgt.Query(idl[x],id[x]-1);
	tr=sgt.Query(id[x]+1,idr[x]);
	tl.ssa=(tl.ssa-tl.sa+mod)%mod;
	tr.ssb=(tr.ssb-tr.sb+mod)%mod;
//	cout<<1ll*tl.sa*tr.sb<<" "<<1ll*tl.ssa*b[x]<<" "<<1ll*tr.ssb*a[x]<<endl;
	return (1ll*tl.sa*tr.sb+1ll*tl.ssa*b[x]+1ll*tr.ssb*a[x])%mod;
}
int main()
{
	geti(n);
	for(int i=1;i<=n;i++)
	{
		geti(c[i]);
		pp[i]=MP(c[i],i);
		hsv[hsn++]=c[i];
	}
	sort(pp+1,pp+n+1);
	for(int i=1;i<=n;i++)
	{
		id[pp[i].SS]=i;
	}
	int pre=1;
	for(int i=1;i<=n;i++)
	{
		if(i>1&&pp[i].FF!=pp[i-1].FF)pre=i;
		idl[pp[i].SS]=pre;
	}
	pre=n;
	for(int i=n;i>=1;i--)
	{
		if(i<n&&pp[i].FF!=pp[i+1].FF)pre=i;
		idr[pp[i].SS]=pre;
	}
	sort(hsv,hsv+hsn);
	for(int i=1;i<=n;i++)
	{
		c[i]=lower_bound(hsv,hsv+hsn,c[i])-hsv+1;
	}
	A.init();
	for(int i=1;i<=n;i++)
	{
		ia[id[i]]=a[i]=A.query(c[i]);
		A.add(c[i]);
	}
	A.init();
	for(int i=n;i>=1;i--)
	{
		ib[id[i]]=b[i]=A.query(c[i]);
		A.add(c[i]);
	}
	for(int i=1;i<=n;i++)suma[i]=(suma[i-1]+a[pp[i].SS])%mod;
	for(int i=1;i<=n;i++)sumb[i]=(sumb[i-1]+b[pp[i].SS])%mod;
	ll cans=0;
	for(int i=1;i<=n;i++)
	{
		cans+=1ll*(suma[id[i]-1]-suma[idl[i]-1])*(sumb[idr[i]]-sumb[id[i]])%mod;
//		cout<<(suma[id[i]-1]-suma[idl[i]-1])<<" "<<(sumb[idr[i]]-sumb[id[i]])<<endl;
	}
	cans=(cans%mod+mod)%mod;
//	cout<<"cans="<<cans<<endl;
	sgt.Build(n);
	int q;
	geti(q);
	for(int i=1;i<=q;i++)
	{
		int t,x;
		getii(t,x);
		ll dlt=calcdlt(x);
		if(t==1)cans=(cans-dlt+mod)%mod;
		else cans=(cans+dlt)%mod;
		putsi(cans);
		sgt.Change(id[x]);
	}
	return 0;
}