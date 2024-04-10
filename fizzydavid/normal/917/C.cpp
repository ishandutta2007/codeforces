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
ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
struct matrix
{
	ll a[77][77];
	matrix(){memset(a,31,sizeof(a));}
	void set1(){memset(a,31,sizeof(a));for(int i=0;i<77;i++)a[i][i]=0;}
	matrix operator*(const matrix &t)const
	{
		matrix ret;
		for(int i=0;i<77;i++)
		{
			for(int j=0;j<77;j++)
			{
				for(int k=0;k<77;k++)
				{
					ret.a[i][k]=min(ret.a[i][k],a[i][j]+t.a[j][k]);
				}
			}
		}
		return ret;
	}
};
int n,m,K,q;
int cnt1[300];
int mskid[300];
int tot=0;
int w[11];
matrix A;
matrix apw[30];
vector<pair<int,pair<int,int> > > v;
ll dp[77];
ll ndp[77];
void go(const matrix &t)
{
	memset(ndp,31,sizeof(ndp));
	for(int i=0;i<77;i++)
	{
		for(int j=0;j<77;j++)
		{
			ndp[j]=min(ndp[j],dp[i]+t.a[i][j]);
		}
	}
	swap(dp,ndp);
}
void go(int x)
{
	for(int i=0;i<30;i++)
	{
		if((x>>i)&1)
		{
			go(apw[i]);
		}
	}
}
matrix construct(ll dlt[])
{
	matrix ret;
	for(int i=1;i<(1<<m);i++)
	{
		if(cnt1[i]!=n)continue;
		if(i&1)
		{
			int nmsk=i>>1;
			for(int j=0;j<m;j++)
			{
				if((nmsk>>j)&1)continue;
				ret.a[mskid[i]][mskid[nmsk|(1<<j)]]=w[j]+dlt[j];
			}
		}
		else ret.a[mskid[i]][mskid[i>>1]]=0;
	}
	return ret;
}
int main()
{
	for(int i=1;i<256;i++)cnt1[i]=cnt1[i-(i&(-i))]+1;
	cin>>n>>m>>K>>q;
	for(int i=0;i<m;i++)cin>>w[i];
	for(int i=1;i<(1<<m);i++)
	{
		if(cnt1[i]==n)
		{
			mskid[i]=++tot;
//			cerr<<"st "<<tot<<":"<<i<<endl;
		}
	}
	ll tmp[10]={};
	A=construct(tmp);
/*	for(int i=1;i<=tot;i++)
	{
		for(int j=1;j<=tot;j++)
		{
			cerr<<A.a[i][j]<<" ";
		}
		cerr<<endl;
	}*/
	
	apw[0]=A;
	for(int i=1;i<30;i++)apw[i]=apw[i-1]*apw[i-1];
	for(int i=1;i<=q;i++)
	{
		int x,c;
		cin>>x>>c;
		for(int j=0;j<m;j++)
		{
			int t=x-j+n-1;
			if(t>n&&t<=K)v.PB(MP(t,MP(j,c)));
		}
	}
	sort(v.begin(),v.end());
	int pre=n;
	memset(dp,31,sizeof(dp));
	dp[1]=0;
	for(int i=0;i<v.size();)
	{
		go(v[i].FF-pre-1);pre=v[i].FF;
		int r=i;
		while(r<v.size()&&v[r].FF==v[i].FF)r++;
		ll dlt[10]={};
		for(int j=i;j<r;j++)
		{
			dlt[v[j].SS.FF]+=v[j].SS.SS;
		}
		matrix B=construct(dlt);
		go(B);
//		cerr<<"dp:"<<endl;
//		for(int x=1;x<=tot;x++)cerr<<dp[x]<<" ";cerr<<endl;
		i=r;
	}
	go(K-pre);
	cout<<dp[1]<<endl;
	return 0;
}