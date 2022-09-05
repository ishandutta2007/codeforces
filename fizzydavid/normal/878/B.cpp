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
int n,m,k,a[100111],b[200111];
pair<int,int> st[100111];
int stn;
int standardize(int a[],int n)
{
	stn=0;
	for(int i=1;i<=n;i++)
	{
		st[stn++]=MP(a[i],1);
		bool flag=1;
		while(flag)
		{
			flag=0;
			if(stn>=2&&st[stn-1].FF==st[stn-2].FF)
			{
				flag=1;
				st[stn-2].SS+=st[stn-1].SS;
				stn--;
			}
			if(stn>=1&&st[stn-1].SS>=k)
			{
				if(st[stn-1].SS%k==0)stn--;
				else st[stn-1].SS%=k;
				flag=1;
			}
		}
	}
	int nn=0;
	for(int i=0;i<stn;i++)
	{
		while(st[i].SS--)a[++nn]=st[i].FF;
	}
	return nn;
}
int main()
{
	getiii(n,k,m);
	for(int i=1;i<=n;i++)geti(a[i]);
	bool allsame=1;
	for(int i=1;i<n;i++)allsame&=a[i]==a[i+1];
	if(allsame)
	{
		cout<<(1ll*n*m)%k;
	}
	else
	{
		if(k>=n)
		{
			cout<<1ll*n*m;
		}
		else
		{
			n=standardize(a,n);
			int BG=1,ED=n,bg,ed,tmp,cnt;
			bool flag=1;
			while(flag)
			{
				flag=0;
				tmp=a[BG],cnt=0,bg=BG,ed=ED;
				while(bg<=ed&&a[bg]==tmp&&cnt<k)bg++,cnt++;
				while(bg<=ed&&a[ed]==tmp&&cnt<k)ed--,cnt++;
				if(cnt==k)
				{
					BG=bg;ED=ed;flag=1;
				}
				
				tmp=a[ed],cnt=0,bg=BG,ed=ED;
				while(bg<=ed&&a[bg]==tmp&&cnt<k)bg++,cnt++;
				while(bg<=ed&&a[ed]==tmp&&cnt<k)ed--,cnt++;
				if(cnt==k)
				{
					BG=bg;ED=ed;flag=1;
				}
			}
//			cerr<<BG<<","<<ED<<endl;
			allsame=1;
			for(int i=BG;i+1<=ED;i++)allsame&=a[i]==a[i+1];
			if(allsame)
			{
				int nn=0,times=(1ll*(ED-BG+1)*m)%k;
				for(int i=1;i<BG;i++)b[++nn]=a[i];
				for(int i=0;i<times;i++)b[++nn]=a[BG];
				for(int i=ED+1;i<=n;i++)b[++nn]=a[i];
				int ans=standardize(b,nn);
				cout<<ans<<endl;
			}
			else
			{
				cout<<1ll*(ED-BG+1)*m+BG-1+n-ED<<endl;
			}
		}
	}
	return 0;
}