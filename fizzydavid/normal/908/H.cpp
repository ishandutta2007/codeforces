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
int n;
char s[55][55];
int f[55],id[55];
int adj[55];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
int sz[55];
int sadj[1<<23];
bool dp[1<<23];
int lg2[1<<23];
void calcdp(int n)
{
	assert(n<=23);
	for(int i=1;i<(1<<n);i++)sadj[i]=sadj[i-(i&(-i))]|adj[lg2[i&(-i)]];
	dp[0]=1;
	for(int i=1;i<(1<<n);i++)dp[i]=(sadj[i]&i)==0;
}
void upd(int &x,int v){x=x+v>=mod?x+v-mod:x+v;}
void FMT(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<(1<<n);j++)
		{
			if((j>>i)&1)continue;
			upd(a[j|(1<<i)],a[j]);
		}
	}
}
int a[1<<23],b[1<<23],cnt1[1<<23];
int calcans(int n)
{
	cnt1[0]=1;
	for(int i=1;i<(1<<n);i++)cnt1[i]=-cnt1[i-(i&(-i))];
	FMT(a,n);
	for(int i=0;i<(1<<n);i++)b[i]=1;
	for(int i=0;i<=n;i++)
	{
		int sum=0;
		for(int j=0;j<(1<<n);j++)
		{
			if(cnt1[(1<<n)-j-1]==1)upd(sum,b[j]);
			else upd(sum,mod-b[j]);
		}
//		cerr<<"sum="<<sum<<endl;
		if(sum!=0)return i;
		for(int j=0;j<(1<<n);j++)b[j]=1ll*b[j]*a[j]%mod;
	}
	assert(false);
}
int main()
{
	srand(time(NULL));
	for(int i=0;i<23;i++)lg2[1<<i]=i;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		f[i]=i;
		scanf("%s",s[i]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(s[i][j]=='A')
			{
				f[gf(i)]=gf(j);
			}
		}
	}
	for(int i=0;i<n;i++)sz[gf(i)]++;
	int ans=n-1,idn=0;
	memset(id,-1,sizeof(id));
	for(int i=0;i<n;i++)
	{
		if(sz[i]>1)
		{
			id[i]=idn++;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(s[i][j]=='X')
			{
				if(gf(i)==gf(j))
				{
					puts("-1");
					return 0;
				}
				else
				{
					int x=id[gf(i)],y=id[gf(j)];
					if(x==-1||y==-1)continue;
					adj[x]|=1<<y;
					adj[y]|=1<<x;
//					cerr<<"adde:"<<x<<","<<y<<endl;
				}
			}
		}
	}
	calcdp(idn);
//	for(int i=0;i<(1<<idn);i++)cerr<<dp[i];cerr<<endl;
	for(int i=0;i<(1<<idn);i++)if(dp[i])a[i]=rand()+1;
	ans+=calcans(idn);
	cout<<ans<<endl;
	
	return 0;
}