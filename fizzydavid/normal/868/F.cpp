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
int n,m;
int a[100111];
ll dp[100111],ndp[100111];
int L,R,cnt[100111];
ll curans;
void add(int x)
{
	curans-=1ll*cnt[a[x]]*(cnt[a[x]]-1)/2;
	cnt[a[x]]++;
	curans+=1ll*cnt[a[x]]*(cnt[a[x]]-1)/2;
}
void del(int x)
{
	curans-=1ll*cnt[a[x]]*(cnt[a[x]]-1)/2;
	cnt[a[x]]--;
	curans+=1ll*cnt[a[x]]*(cnt[a[x]]-1)/2;
}
void trans(int l,int r)
{
	while(L>l)add(--L);
	while(R<r)add(++R);
	while(L<l)del(L++);
	while(R>r)del(R--);
}
void solve(int l,int r,int tl,int tr)
{
	if(l>r)return;
	int mid=l+r>>1;
	int mnid=1;
	ll mn=8e18;
	for(int i=tl;i<=tr;i++)
	{
		trans(i,mid);
		if(curans+dp[i-1]<mn)
		{
			mn=curans+dp[i-1];
			mnid=i;
		}
	}
	ndp[mid]=mn;
	solve(l,mid-1,tl,mnid);
	solve(mid+1,r,mnid,tr);
}
int main()
{
	getii(n,m);
	for(int i=1;i<=n;i++)geti(a[i]);
	dp[0]=0;
	for(int i=1;i<=n;i++)dp[i]=4e18;
	L=1;R=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<=n;j++)ndp[j]=4e18;
		solve(1,n,1,n);
		swap(dp,ndp);
	}
	cout<<dp[n]<<endl;
	return 0;
}