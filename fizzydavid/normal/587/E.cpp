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
typedef unsigned int ui;
struct node
{
	ui a[32];
	int tn,lazy;
	void init(){tn=lazy=0;memset(a,0,sizeof(a));}
	node(){init();}
	void insert(ui v)
	{
		if(tn==32)return;
		for(int i=tn-1;i>=0;i--)
		{
			if((v^a[i])<v)v^=a[i];
		}
		if(!v)return;
		int pos=lower_bound(a,a+tn,v)-a;
		for(int i=tn;i>pos;i--)a[i]=a[i-1];
		a[pos]=v;
		tn++;
	}
	ui& last(){return a[tn-1];}
}a[800111];
node merge(node l,node r)
{
	node ret;
	if(l.tn<r.tn)
	{
		ret=r;
		for(int i=0;i<l.tn;i++)ret.insert(l.a[i]);
	}
	else
	{
		ret=l;
		for(int i=0;i<r.tn;i++)ret.insert(r.a[i]);
	}
	ret.lazy=0;
	return ret;
}
#define ls p<<1
#define rs p<<1|1
void pushdown(int p)
{
	int &v=a[p].lazy;
	if(v!=0)
	{
		a[ls].lazy^=v;
		a[ls].last()^=v;
		a[rs].lazy^=v;
		a[rs].last()^=v;
		v=0;
	}
}
ui ia[200111];
void build(int l,int r,int p=1)
{
	if(l==r)
	{
		a[p].tn=1;
		a[p].a[0]=ia[l];
		return;
	}
	int m=l+r>>1;
	build(l,m,ls);
	build(m+1,r,rs);
	a[p]=merge(a[ls],a[rs]);
}
node query(int x,int y,int l,int r,int p=1)
{
	if(x<=l&&r<=y)return a[p];
	pushdown(p);
	int m=l+r>>1;
	if(x<=m&&m<y)return merge(query(x,y,l,m,ls),query(x,y,m+1,r,rs));
	else if(x<=m)return query(x,y,l,m,ls);
	else return query(x,y,m+1,r,rs);
}
void modify(int x,int y,int v,int l,int r,int p=1)
{
	if(x<=l&&r<=y)
	{
		a[p].lazy^=v;
		a[p].last()^=v;
		return;
	}
	pushdown(p);
	int m=l+r>>1;
	if(x<=m)modify(x,y,v,l,m,ls);
	if(m<y)modify(x,y,v,m+1,r,rs);
	a[p]=merge(a[ls],a[rs]);
}

const ll MSK=(1ll<<31)-1;
void out(int l,int r,int p=1)
{
	cerr<<l<<","<<r<<" "<<a[p].lazy<<" "<<a[p].tn<<" "<<(a[p].last()&MSK)<<endl;
	if(l==r)return;
	int m=l+r>>1;
	out(l,m,ls);out(m+1,r,rs);
}
int n,q;
int main()
{
	getii(n,q);
	for(int i=1;i<=n;i++)geti(ia[i]),ia[i]|=1ll<<31;
	build(1,n,1);
	for(int i=1;i<=q;i++)
	{
		int t,x,y,v;
		getiii(t,x,y);
		if(t==1)
		{
			geti(v);
			modify(x,y,v,1,n);
		}
		else
		{
			node tmp=query(x,y,1,n),cur;
			for(int i=0;i<tmp.tn;i++)
			{
//				cerr<<"insert:"<<(tmp.a[i]&MSK)<<endl;
				cur.insert(tmp.a[i]&MSK);
			}
			putsi(1ll<<cur.tn);
		}
//		out(1,n,1);
	}
	return 0;
}