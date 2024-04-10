//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
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
const int maxn=12;
int n,m,q;
int f[1<<maxn];
int lg2[1<<maxn];
int tab[1<<maxn][1<<maxn];
void prework()
{
	for(int i=0;i<maxn;i++)lg2[1<<i]=i;
	for(int i=(1<<n)-1;i>=0;i--)
	{
		for(int j=0;j<(1<<n);j++)
		{
			if((i&j)==j)
			{
				if(i+1==(1<<n))tab[i][j]=f[j];
				else
				{
					int t=(1<<n)-1-i;
					t=lg2[t&(-t)];
					tab[i][j]=tab[i|(1<<t)][j]+tab[i|(1<<t)][j|(1<<t)];
				}
			}
		}
	}
}
int opid[256];
void query()
{
	char s[maxn];
	int msk[6]={};
	for(int i=0;i<n;i++)
	{
		s[i]=getreal();
	}
	reverse(s,s+n);
	for(int i=0;i<n;i++)
	{
		msk[opid[s[i]]]|=1<<i;
	}
	int ans=0;
	int msk00=msk[1]|msk[2];
	int msk01=msk[0]|msk[5];
	int msk10=msk[4]|msk[5];
	int msk11=msk[2]|msk[3];
	for(int i=0;i<(1<<n);i++)
	{
		if(!f[i])continue;
		int ni=(1<<n)-1-i;
		if(ni&msk[3])continue;
		if(i&msk[1])continue;
		int msk0=(ni&msk00)|(i&msk01);
		int msk1=(ni&msk10)|(i&msk11);
		ans+=f[i]*tab[msk0|msk1][msk1];
//		cerr<<i<<","<<msk0<<","<<msk1<<":"<<f[i]<<" "<<tab[msk0|msk1][msk1]<<endl;
	}
	printf("%d\n",ans);
}
int main()
{
	opid['A']=0;opid['O']=1;opid['X']=2;
	opid['a']=3;opid['o']=4;opid['x']=5;
	getiii(n,m,q);
	for(int i=0;i<m;i++)
	{
		int x;
		geti(x);
		f[x]++;
	}
	prework();
	for(int i=1;i<=q;i++)
	{
		query();
	}
	return 0;
}