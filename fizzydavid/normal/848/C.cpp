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
const int mxc=100111;
struct fizzytreap
{
	struct node
	{
		int tl,tr,key,val,sz;
		ll s0,sum;
		void init(){tl=tr=sum=s0=sz=val=0;key=rand();}
		node(){init();}
	}a[mxc*22];
	int tot,rt[mxc];
	int newnode(){a[++tot].sz=1;return tot;}
	void init(){tot=0;memset(rt,0,sizeof(rt));}
	fizzytreap(){init();}
	#define ls a[p].tl
	#define rs a[p].tr
	void update(int p)
	{
		if(!p)return;
		a[p].sz=a[ls].sz+a[rs].sz+1;
		a[p].sum=a[ls].sum+a[rs].sum+a[p].s0;
	}
	int merge(int p,int q)
	{
		if(!p)return q;
		if(!q)return p;
		if(a[p].key<a[q].key)
		{
			a[p].tr=merge(a[p].tr,q);
			update(p);
			return p;
		}
		else
		{
			a[q].tl=merge(p,a[q].tl);
			update(q);
			return q;
		}
	}
	pair<int,int> split(int p,int k)
	{
		if(!p)return MP(0,0);
		pair<int,int> ret;
		if(k<=a[ls].sz)
		{
			ret=split(ls,k);
			a[p].tl=ret.SS;
			ret.SS=p;
		}
		else
		{
			ret=split(rs,k-a[ls].sz-1);
			a[p].tr=ret.FF;
			ret.FF=p;
		}
		update(p);
		return ret;
	}
	bool tmp;
	int findrk(int p,int v)
	{
		if(!p)return 0;
		if(v==a[p].val){tmp=1;return a[ls].sz;}
		return v<=a[p].val?findrk(ls,v):findrk(rs,v)+a[ls].sz+1;
	}
	pair<int,pair<int,int> > splitval(int &rt,int v)
	{
		tmp=0;
		int rk=findrk(rt,v);
		pair<int,int> pp=split(rt,rk);
		if(tmp)return MP(pp.FF,split(pp.SS,1));
		int p=newnode();a[p].val=v;
		return MP(pp.FF,MP(p,pp.SS));
	}
	void addv(int &rt,int x,int v)
	{
		pair<int,pair<int,int> > pp=splitval(rt,x);
		a[pp.SS.FF].s0+=v;
		update(pp.SS.FF);
		rt=merge(merge(pp.FF,pp.SS.FF),pp.SS.SS);
	}
	void add(int x,int y,int v)
	{
		for(int i=x;i<mxc;i+=i&(-i))addv(rt[i],y,v);
	}
	ll query(int &rt,int x,int y)
	{
//		cerr<<"query:"<<rt<<" "<<x<<" "<<y<<endl;
		pair<int,int> pp=split(rt,findrk(rt,x));
		pair<int,int> pp2=split(pp.SS,findrk(pp.SS,y+1));
		ll ret=a[pp2.FF].sum;
		rt=merge(pp.FF,merge(pp2.FF,pp2.SS));
		return ret;
	}
	ll query(int xl,int xr,int yl,int yr)
	{
		xl--;
		ll ret=0;
		while(xl!=xr)
		{
			if(xr>xl)ret+=query(rt[xr],yl,yr),xr-=xr&(-xr);
			else ret-=query(rt[xl],yl,yr),xl-=xl&(-xl);
		}
		return ret;
	}
	void out(int p)
	{
		if(!p)return;
		cerr<<"rt:"<<a[p].val<<" "<<a[p].tl<<","<<a[p].tr<<" "<<a[p].s0<<" "<<a[p].sum<<" "<<a[p].sz<<endl;
		out(ls);
		out(rs);
	}
}fz;
int n,m,a[100111];
set<int> st[100111];
void addc(int t,int l,int r)
{
	if(t==1)fz.add(l,r,r-l);
	else fz.add(l,r,-(r-l));
}
void add(int x,int p)
{
	st[x].insert(p);
	int pre=-1,nxt=-1;
	set<int>::iterator it=st[x].lower_bound(p);
	if(it!=st[x].begin())it--,pre=*it,it++;
	it++;if(it!=st[x].end())nxt=*it;
	if(pre!=-1&&nxt!=-1)addc(2,pre,nxt);
	if(pre!=-1)addc(1,pre,p);
	if(nxt!=-1)addc(1,p,nxt);
}
void del(int x,int p)
{
	int pre=-1,nxt=-1;
	set<int>::iterator it=st[x].lower_bound(p);
	if(it!=st[x].begin())it--,pre=*it,it++;
	it++;if(it!=st[x].end())nxt=*it;
	if(pre!=-1&&nxt!=-1)addc(1,pre,nxt);
	if(pre!=-1)addc(2,pre,p);
	if(nxt!=-1)addc(2,p,nxt);
	st[x].erase(p);
}
ll ans[1000111];
int main()
{
	getii(n,m);
	for(int i=1;i<=n;i++)geti(a[i]);
	for(int i=1;i<=n;i++)add(a[i],i);
	for(int i=1;i<=m;i++)
	{
		int q,x,y;
		getiii(q,x,y);
		if(q==1)
		{
			del(a[x],x);
			add(y,x);
			a[x]=y;
		}
		else
		{
			putsi(fz.query(x,y,x,y));
		}
	}
	return 0;
}