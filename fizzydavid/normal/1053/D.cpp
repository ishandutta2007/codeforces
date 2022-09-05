//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
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
ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
int n;
bool tmp[2000111];
bool np[2000111];
int cnt[2000111],mcnt[2000111];
vector<pair<int,int> > pfac[2000111];
int main()
{
	
	geti(n);
	vector<int> v,v2;
	for(int i=1;i<=n;i++)
	{
		int x;
		geti(x);
		v.PB(x);
		tmp[x-1]=1;
	}
	for(int i=2;i<=2000000;i++)
	{
		if(np[i])continue;
		pfac[i].PB(MP(i,1));
		for(int j=i+i;j<=2000000;j+=i)
		{
			np[j]=1;
			if(tmp[j])
			{
				int c=0,t=j;
				while(t%i==0)
				{
					t/=i;
					c++;
				}
				pfac[j].PB(MP(i,c));
			}
		}
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	bool add1=0;
	for(int i=0;i<v.size();i++)
	{
		int x=v[i];
		if(cnt[x]==0)
		{
			cnt[x]=1;
		}
		else
		{
			v2.PB(x);
			bool ok=0;
			for(int j=0;j<pfac[x-1].size();j++)
			{
				int pr=pfac[x-1][j].FF,k=pfac[x-1][j].SS;
				if(cnt[pr]<k)
				{
					cnt[pr]=k;
					mcnt[pr]=1;
					ok=1;
				}
				else if(cnt[pr]==k)
				{
					mcnt[pr]++;
				}
			}
			if(!ok)add1=1;
		}
	}
	if(!add1)
	{
		for(int i=0;i<v2.size();i++)
		{
			int x=v2[i];
			bool unn=1;
			for(int j=0;j<pfac[x-1].size();j++)
			{
				int pr=pfac[x-1][j].FF,k=pfac[x-1][j].SS;
				unn&=cnt[pr]>k||(cnt[pr]==k&&mcnt[pr]>=2);
			}
			if(unn)add1=1;
		}
	}
	ll ans=1;
	for(int i=2;i<=2000000;i++)
	{
		if(cnt[i])ans=ans*qpow(i,cnt[i])%mod;
	}
	cout<<(ans+add1)%mod<<endl;
	return 0;
}