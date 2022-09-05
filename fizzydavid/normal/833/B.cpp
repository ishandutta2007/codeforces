//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define debug(...) (cerr<<"'"<<__FUNCTION__<<"': "),fprintf(stderr,__VA_ARGS__)
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
int n,k,a[35011];
int dp[35011],ndp[35011];
int cnt[35011],cur;
void add(int x){cur+=(cnt[a[x]]++)==0;}
void del(int x){cur-=(--cnt[a[x]])==0;}
const int B=200;
int tab[35011];
void calc(int x,int lim)
{
	ndp[x]=0;
	for(int i=x;i>=lim;i--)
	{
		add(i);
		if(dp[i-1]+cur>ndp[x])
		{
			ndp[x]=dp[i-1]+cur;
			tab[x]=i;
		}
	}
	for(int i=x;i>=lim;i--)del(i);
}
int main()
{
	getii(n,k);
//	n=k=20;
	for(int i=1;i<=n;i++)geti(a[i]);
//	for(int i=1;i<=n;i++)a[i]=rand()%20+1;
	for(int t=1;t<=k;t++)
	{
//		cerr<<"t="<<t<<endl;
		memset(tab,-1,sizeof(tab));
		memset(ndp,0,sizeof(ndp));
		memset(cnt,0,sizeof(cnt));cur=0;
		calc(1,1);calc(n,1);
		int tmp=tab[1];
		for(int i=B;i<n;i+=B)
		{
			calc(i,tmp);
			tmp=tab[i];
		}
		int l,r,it=1;
		for(int i=1;i<=n;i++)
		{
			add(i);
			if(tab[i]!=-1)
			{
				l=r=-1;
				continue;
			}
			if(l==-1)
			{
				l=i;while(tab[l]==-1)l--;
				r=i;while(tab[r]==-1)r++;
			}
			while(it<tab[l])del(it++);
			while(it>tab[l])add(--it);
//			cerr<<tab[l]<<" "<<tab[r]<<endl;
			for(int j=tab[l];j<=min(i,tab[r]);j++)
			{
				ndp[i]=max(ndp[i],dp[j-1]+cur);
				del(j);
			}
			for(int j=tab[l];j<=min(i,tab[r]);j++)add(j);
		}
		swap(dp,ndp);
		for(int i=1;i<t;i++)dp[i]=0;
//		for(int i=1;i<=n;i++)cout<<dp[i]<<" ";cout<<endl;
	}
	cout<<dp[n]<<endl;
	return 0;
}