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
int n,k;
int a[211];
int dp[211][1011],ndp[211][1011];
void add(int &x,int v){x=x+v>=mod?x+v-mod:x+v;}
int main()
{
	getii(n,k);
	for(int i=1;i<=n;i++)geti(a[i]);
	sort(a+1,a+n+1);
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		memset(ndp,0,sizeof(ndp));
		for(int j=0;j<i;j++)
		{
			for(int t=0;t<=k;t++)
			{
				int &v=dp[j][t];
				if(v==0)continue;
				int nt=t+(a[i]-a[i-1])*j;
				if(nt>k)continue;
				add(ndp[j+1][nt],v);
				if(j>0)add(ndp[j-1][nt],1ll*v*j%mod);
				add(ndp[j][nt],1ll*v*(j+1)%mod);
			}
		}
		swap(dp,ndp);
	}
	ll sum=0;
	for(int i=0;i<=k;i++)sum+=dp[0][i];
	cout<<sum%mod<<endl;
	return 0;
}