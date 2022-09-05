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
int n,m;
int a[400111],b[400111];
vector<int> v;
int getid(int x){return lower_bound(v.begin(),v.end(),x)-v.begin()+1;}
int ans[400111],cx[400111];
vector<pair<int,int> >cmd[400111];
int allans,dp[400111];
bool reached[400111];
int rcnt[400111];
struct BIT
{
	int a[800111];
	void init(){memset(a,0,sizeof(a));}
	BIT(){memset(a,0,sizeof(a));}
	void maxi(int x,int v)
	{
		for(int i=x;i<=800005;i+=i&(-i))a[i]=max(a[i],v);
	}
	int query(int x)
	{
		int ret=0;
		for(int i=x;i;i-=i&(-i))ret=max(ret,a[i]);
		return ret;
	}
}rikka;
int main()
{
	getii(n,m);
	for(int i=1;i<=n;i++)
	{
		geti(a[i]);
		v.PB(a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		getii(x,y);
		cx[i]=x;
		cmd[x].PB(MP(y,i));
		v.PB(y);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	rikka.init();
	for(int i=1;i<=n;i++)
	{
		b[i]=getid(a[i]);
		dp[i]=rikka.query(b[i]-1)+1;
		for(int j=0;j<cmd[i].size();j++)
		{
			int v=cmd[i][j].FF,id=cmd[i][j].SS;
			ans[id]=rikka.query(getid(v)-1)+1;
		}
		rikka.maxi(b[i],dp[i]);
		allans=max(allans,dp[i]);
	}
	static int mx[400111];
//	cerr<<"allans="<<allans<<endl;
	for(int i=n;i>=1;i--)
	{
		if(dp[i]==allans||b[i]<mx[dp[i]+1])
		{
			reached[i]=1;
			mx[dp[i]]=max(mx[dp[i]],b[i]);
			rcnt[dp[i]]++;
//			cerr<<"reached "<<i<<" "<<dp[i]<<endl;
		}
	}
	rikka.init();
	int vn=v.size();
	for(int i=n;i>=1;i--)
	{
		int cur=rikka.query((vn-b[i]+1)-1)+1;
		for(int j=0;j<cmd[i].size();j++)
		{
			int v=cmd[i][j].FF,id=cmd[i][j].SS;
			ans[id]+=rikka.query((vn-getid(v)+1)-1);
		}
		rikka.maxi(vn-b[i]+1,cur);
	}
	for(int t=1;t<=m;t++)
	{
		int i=cx[t];
		bool must=reached[i]&&rcnt[dp[i]]==1;
//		cerr<<"must="<<must<<" "<<reached[i]<<" "<<dp[i]<<endl;
		ans[t]=max(ans[t],allans-must);
		putsi(ans[t]);
	}
	return 0;
}