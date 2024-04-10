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
int s[200111],sn;
int sa[200111],lcp[200111],rk[200111],nrk[200111],nsa[200111],b[200111];
int tab[20][200111];
void makeb(int n)
{
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++)b[rk[i]]++;
	for(int i=1;i<=200002;i++)b[i]+=b[i-1];
}
#define bunny(x) MP(rk[x],x+k<=n?rk[x+k]:-1)
void construct_sa(int n)
{
//	for(int i=1;i<=n;i++)cerr<<s[i]<<" ";cerr<<endl;
	sn=n;
	for(int i=1;i<=n;i++)rk[i]=s[i];
	makeb(n);
	for(int i=n;i>=1;i--)sa[b[rk[i]]--]=i;
	for(int k=1;k<n;k<<=1)
	{
		makeb(n);
		for(int i=n;i>=1;i--)if(sa[i]>k)nsa[b[rk[sa[i]-k]]--]=sa[i]-k;
		for(int i=n;i>=1;i--)if(sa[i]>n-k)nsa[b[rk[sa[i]]]--]=sa[i];
		nrk[nsa[1]]=1;
		for(int i=2;i<=n;i++)nrk[nsa[i]]=nrk[nsa[i-1]]+(bunny(nsa[i-1])<bunny(nsa[i]));
		swap(nrk,rk);
		swap(nsa,sa);
	}
//	for(int i=1;i<=n;i++)cerr<<sa[i]<<" ";cerr<<endl;
	for(int i=1;i<=n;i++)rk[sa[i]]=i;
	int h=0;
	for(int i=1;i<=n;i++)
	{
		if(h>0)h--;
		if(rk[i]==1)continue;
		int j=sa[rk[i]-1];
		while(i+h<=n&&j+h<=n&&s[i+h]==s[j+h])h++;
		lcp[rk[i]-1]=h;
	}
	for(int i=1;i<n;i++)tab[0][i]=lcp[i];
	for(int i=1;i<20;i++)
	{
		for(int j=1;j<=n-(1<<i)+1;j++)
		{
			tab[i][j]=min(tab[i-1][j],tab[i-1][j+(1<<(i-1))]);
		}
	}
}
map<int,int> mp;int mptot;
int n,q,a[100111];
void prework()
{
	for(int i=1;i<n;i++)s[i]=a[i+1]-a[i];
	for(int i=n;i<2*n-1;i++)s[i]=-s[i-n+1];
	for(int i=1;i<2*n-1;i++)
	{
		int &v=mp[s[i]];
		if(v==0)v=++mptot;
		s[i]=v;
	}
	construct_sa(2*n-2);
}
int qx[100111],qy[100111],ans[100111];
pair<int,int> querylcp(int x,int v)
{
	int l=x;
	for(int i=19;i>=0;i--)
	{
		if(l>=(1<<i)&&tab[i][l-(1<<i)]>=v)
		{
			l-=1<<i;
		}
	}
	int r=x;
	for(int i=19;i>=0;i--)
	{
		if(r+(1<<i)<=sn&&tab[i][r]>=v)
		{
			r+=1<<i;
		}
	}
	return MP(l,r);
}
struct query
{
	int x,y,v,id;
	query(int X=0,int Y=0,int V=0,int Id=0)
	{
		x=X;y=Y;v=V;id=Id;
	}
	bool operator<(const query &t)const
	{
		return x<t.x;
	}
}qr[800111];
struct BIT
{
	int a[200111];
	BIT()
	{
		memset(a,0,sizeof(a));
	}
	void add(int x)
	{
		for(int i=x;i<=200005;i+=i&(-i))a[i]++;
	}
	int query(int x)
	{
		int ret=0;
		for(int i=x;i;i-=i&(-i))ret+=a[i];
		return ret;
	}
}bit;
int qn;
void addquery(int xl,int xr,int yl,int yr,int id)
{	
	if(xl>1)qr[qn++]=query(xl-1,yl-1,1,id);
	qr[qn++]=query(xr,yl-1,-1,id);
	if(xl>1)qr[qn++]=query(xl-1,yr,-1,id);
	qr[qn++]=query(xr,yr,1,id);
}
void solve()
{
	sort(qr,qr+qn);
	int it=0;
	for(int i=1;i<=sn;i++)
	{
		bit.add(sa[i]);
		while(it<qn&&qr[it].x<=i)
		{
			ans[qr[it].id]+=bit.query(qr[it].y)*qr[it].v;
			it++;
		}
	}
}
int main()
{
	geti(n);
	for(int i=1;i<=n;i++)geti(a[i]);
	prework();
	geti(q);
	for(int i=1;i<=q;i++)
	{
		int x,y;
		getii(x,y);
		qx[i]=x;qy[i]=y;
		if(x==y)ans[i]=n-1;
		else
		{
			pair<int,int> pp=querylcp(rk[x],y-x);
//			cerr<<"pp="<<pp.FF<<","<<pp.SS<<endl;
			int r=x-(y-x+1);
			int l=y+1;
//			cerr<<1<<","<<r<<" "<<l<<","<<n-1<<endl;
			if(1<=r)
			{
				addquery(pp.FF,pp.SS,1+n-1,r+n-1,i);
			}
			if(l<=n)
			{
				addquery(pp.FF,pp.SS,l+n-1,sn,i);
			}
		}
	}
	solve();
	for(int i=1;i<=q;i++)putsi(ans[i]);
	return 0;
}