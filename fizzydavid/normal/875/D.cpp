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
int n,a[200111];
int tabm[200111],tabo[200111];
void modify(int x,int v)
{
	for(int i=x;i<200005;i+=i&(-i))
	{
		tabm[i]=max(tabm[i],v);
		tabo[i]|=v;
	}
}
int querym(int x)
{
	int ret=0;
	for(int i=x;i;i-=i&(-i))ret=max(ret,tabm[i]);
	return ret;
}
int queryo(int x)
{
	int ret=0;
	for(int i=x;i;i-=i&(-i))ret|=tabo[i];
	return ret;
}
void clear()
{
	memset(tabm,0,sizeof(tabm));
	memset(tabo,0,sizeof(tabo));
}
int Ll[200111],lr[200111],rl[200111],rr[200111];
int main()
{
	geti(n);
	for(int i=1;i<=n;i++)geti(a[i]);
//	n=200000;
//	for(int i=1;i<=n;i++)a[i]=rand()%100;
	int l,r;
	for(int i=n;i>=1;i--)
	{
		modify(i,a[i]);
		l=i,r=n;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(querym(mid)>a[i])r=mid-1;
			else l=mid+1;
		}
		rr[i]=r;
		
		l=i,r=n;
		while(l<=r)
		{
			int mid=l+r>>1;
			if((queryo(mid)|a[i])==a[i])l=mid+1;
			else r=mid-1;
		}
		rl[i]=l;
	}
	clear();
	reverse(a+1,a+n+1);
	for(int i=n;i>=1;i--)
	{
		l=i,r=n;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(querym(mid)>=a[i])r=mid-1;
			else l=mid+1;
		}
		Ll[n-i+1]=n-r+1;
		
		l=i,r=n;
		while(l<=r)
		{
			int mid=l+r>>1;
			if((queryo(mid)|a[i])==a[i])l=mid+1;
			else r=mid-1;
		}
		lr[n-i+1]=n-l+1;
		modify(i,a[i]);
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		lr[i]=max(Ll[i]-1,lr[i]);
		rl[i]=min(rr[i]+1,rl[i]);
		
//		cerr<<Ll[i]<<" "<<lr[i]<<" "<<rl[i]<<" "<<rr[i]<<endl;
//		if(Ll[i]>lr[i]||rl[i]>rr[i])continue;
		ans+=1ll*(lr[i]-Ll[i]+1)*(rr[i]-i+1)+
		     1ll*(rr[i]-rl[i]+1)*(i-Ll[i]+1)-
		     1ll*(lr[i]-Ll[i]+1)*(rr[i]-rl[i]+1);
	}
	cout<<ans<<endl;
	/*
	int tans=0;
	for(int i=1;i<=n;i++)
	{
		int mx=a[i],oo=a[i];
		for(int j=i;j<=n;j++)
		{
			mx=max(mx,a[j]);
			oo|=a[j];
			if(oo>mx)tans++;
		}
	}
	cerr<<tans<<endl;*/
	return 0;
}