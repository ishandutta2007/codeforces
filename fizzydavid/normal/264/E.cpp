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
const int mxsz=200100;
struct SGT
{
	int a[600111];
	#define ls p<<1
	#define rs p<<1|1
	SGT(){memset(a,0,sizeof(a));}
	void change(int x,int v,int l,int r,int p=1)
	{
		if(x==l&&x==r)
		{
			a[p]=v;
			return;
		}
		int m=l+r>>1;
		if(x<=m)change(x,v,l,m,ls);
		else change(x,v,m+1,r,rs);
		a[p]=max(a[ls],a[rs]);
	}
	void change(int x,int v){change(x,v,1,mxsz,1);}
	int query(int x,int y,int l,int r,int p=1)
	{
		if(x<=l&&r<=y)return a[p];
		int m=l+r>>1;
		if(x<=m&&m<y)return max(query(x,y,l,m,ls),query(x,y,m+1,r,rs));
		else if(x<=m)return query(x,y,l,m,ls);
		else return query(x,y,m+1,r,rs);
	}
	int query(int y){return query(1,y,1,mxsz,1);}
}sgtx,sgty;
int px[200111],py[200111],dp[200111],idn;
int idx[200111],idy[200111];
set<pair<int,int> >dpst;
set<int> sx,sy;
void add(int id,bool d)
{
	int x=px[id],y=py[id];
	sx.insert(x);
	sy.insert(y);
	if(!d)dp[id]=sgty.query(y)+1;
	else dp[id]=sgtx.query(x)+1;
	dpst.insert(MP(dp[id],id));
	sgtx.change(x,dp[id]);
	sgty.change(y,dp[id]);
}
int st[22],stn;
void del(int id)
{
//	cerr<<"del:"<<id<<endl;
	st[stn++]=id;
	int x=px[id],y=py[id];
	dpst.erase(MP(dp[id],id));
	sx.erase(x);
	sy.erase(y);
	sgtx.change(x,0);
	sgty.change(y,0);
}

int main()
{
	int n,q;
	getii(n,q);
	int base=0;
	sx.insert(0);sy.insert(0);dpst.insert(MP(0,0));
	while(q--)
	{
		int cmd,x,y;
		getii(cmd,x);
		if(cmd==1)
		{
			geti(y);
			x=n-x+1;
			y=11-y+base;
			px[++idn]=x;
			py[idn]=y;
			idx[x]=idy[y]=idn;
//			cerr<<"add:"<<x<<","<<y<<endl;
			while(*(--sy.end())>y)del(idy[*(--sy.end())]);
			add(idn,1);
			while(stn>0)add(st[--stn],1);
		}
		else
		{
			while(x--)
			{
				del(idx[*(--sx.end())]);
			}
			stn--;
			while(stn>0)add(st[--stn],0);
		}
		base++;
		putsi((--dpst.end())->FF);
	}
	return 0;
}