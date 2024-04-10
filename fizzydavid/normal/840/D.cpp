//by yjz
#include<bits/stdc++.h>
#include<ctime>
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
int cnt[300111];
int a[300111],n,q;
const int B=555;
struct Query
{
	int l,r,k,id;
	bool operator<(const Query &t)const
	{
		if(l/B!=t.l/B)return l/B<t.l/B;
		else return r<t.r;
	}
}qv[300111];

int v[300111],vn,ans[300111];
int main()
{
	srand(time(NULL));
	getii(n,q);
	for(int i=1;i<=n;i++)
	{
		geti(a[i]);
		v[vn++]=a[i];
	}
	sort(v,v+vn);
	for(int i=1;i<=n;i++)a[i]=lower_bound(v,v+vn,a[i])-v;
	for(int i=1;i<=q;i++)
	{
		int l,r,k;
		getiii(l,r,k);
		qv[i].l=l;
		qv[i].r=r;
		qv[i].k=k;
		qv[i].id=i;
	}
	sort(qv+1,qv+q+1);
	int L=1,R=0;
	for(int i=1;i<=q;i++)
	{
		int l=qv[i].l,r=qv[i].r,k=qv[i].k;
		while(R<r)cnt[a[++R]]++;
		while(L>l)cnt[a[--L]]++;
		while(R>r)cnt[a[R--]]--;
		while(L<l)cnt[a[L++]]--;
		int cans=-1;
		for(int j=0;j<100;j++)
		{
			int pos=(rand()<<15|rand())%(r-l+1)+l;
			if(cnt[a[pos]]*k>r-l+1)
			{
				if(cans==-1||a[pos]<cans)cans=a[pos];
			}
		}
//		cerr<<"cans="<<cans<<endl;
		if(cans==-1)ans[qv[i].id]=-1;
		else ans[qv[i].id]=v[cans];
	}
	for(int i=1;i<=q;i++)putsi(ans[i]);
	return 0;
}