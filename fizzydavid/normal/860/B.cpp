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
int n;
char s[11];
set<ll>st[70011];
ll geths(string &v)
{
	ll ret=0;
	for(int i=0;i<9;i++)
	{
		ret=ret*11+s[i]-'0'+1;
	}
	return ret;
}
map<ll,int> cnt;
void out(ll x)
{
	char tmp[10]={};
	for(int i=8;i>=0;i--)
	{
		tmp[i]='0'+x%11-1;
		x/=11;
		if(x==0)break;
	}
	for(int i=0;i<9;i++)if(tmp[i])putchar(tmp[i]);puts("");
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		for(int j=0;j<9;j++)
		{
			ll hs=0;
			for(int k=j;k<9;k++)
			{
				hs=hs*11+s[k]-'0'+1;
				st[i].insert(hs);
			}
		}
		foreach(it,st[i])
		{
			cnt[*it]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		ll mn=n+1,mnid=-1;
		foreach(it,st[i])
		{
			int &v=cnt[*it];
			if(v<mn)
			{
				mn=v;
				mnid=*it;
			}
		}
		out(mnid);
	}
	return 0;
}