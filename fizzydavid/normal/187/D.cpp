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
inline char getreal(){char c=_buff.get();while(c<=32)c=_buff.get();return c;}
struct node
{
	int l,r,tag,tl,tr;
	int lz;
	void addlz(ll v){lz=tag=v;}
}a[6000111];
#define ls a[p].tl
#define rs a[p].tr
int tot;
int newnode(int l,int r)
{
	tot++;
	a[tot].l=l;
	a[tot].r=r;
	a[tot].tl=a[tot].tr=0;
	a[tot].lz=0;
	return tot;
}
void pushdown(int p,int l,int r)
{
	int &lz=a[p].lz;
	if(lz)
	{
		if(!ls)ls=newnode(l,l+r>>1);
		a[ls].addlz(lz);
		if(!rs)rs=newnode(((l+r)>>1)+1,r);
		a[rs].addlz(lz);
		lz=0;
	}
}
void add(int x,int y,int v,int p=1)
{
	int l=a[p].l,r=a[p].r;
	if(x<=l&&r<=y)
	{
		a[p].addlz(v);
		return;
	}
	pushdown(p,l,r);
	int m=l+r>>1;
	if(x<=m)add(x,y,v,a[p].tl);
	if(m<y)add(x,y,v,a[p].tr);
}
int query(int x,int p=1)
{
	if(a[p].lz)return a[p].lz;
	int l=a[p].l,r=a[p].r;
	if(l==x&&x==r)return a[p].tag;
	int m=l+r>>1;
	if(x<=m)return query(x,a[p].tl);
	else query(x,a[p].tr);
}
int n;
ll T,Tg,Tr,l[100111],suml[100111];
ll ans[100111];
int main()
{
	getiii(n,Tg,Tr);
	T=Tg+Tr;
	n++;
	newnode(0,T-1);
	a[1].addlz(n);
	for(int i=1;i<=n;i++)geti(l[i]),suml[i]=suml[i-1]+l[i];
	ans[n]=0;
	for(int i=n;i>=1;i--)
	{
		if(i==n)ans[i]=0;
		else
		{
//			cerr<<i<<":";
			int id=query(((-suml[i])%T+T)%T);
//			cerr<<id<<" ";
			ll len=suml[id]-suml[i];
			if(id==n||len%T<Tg)
			{
				ans[i]=0;
				assert(id==n);
			}
			else ans[i]=ans[id]+(T-len%T)%T;
			int l=((-suml[i]+Tg)%T+T)%T,r=((-suml[i]+T-1)%T+T)%T;
			if(l<=r)add(l,r,i);
			else add(l,T-1,i),add(0,r,i);
//			cerr<<ans[i]<<" "<<l<<","<<r<<endl;
		}
	}
	int q;
	geti(q);
	for(int i=1;i<=q;i++)
	{
		int x;
		geti(x);
//		cerr<<"query:"<<x<<endl;
		int id=query(x%T);
		ll len=suml[id]+x,Ans;
//		cerr<<id<<" "<<len%T<<endl;
		if(id==n||len%T<Tg)
		{
			Ans=0;
			assert(id==n);
		}
		else Ans=ans[id]+((T-len%T)%T);
		putsi(Ans+suml[n]+x);
	}
	return 0;
}