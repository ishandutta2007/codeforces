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
const int block_cnt=350;
const int block_size=350;
const int mxv=100005;
struct BLOCK
{
	int n;
	int cnt[mxv+233],f[mxv+block_size+233];
	int lazy,mx;
	int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
	void init(int ia[],int N)
	{
		mx=100000;
		for(int i=0;i<mxv+block_size+233;i++)f[i]=i;
		memset(cnt,0,sizeof(cnt));
		lazy=0;
		n=N;
		for(int i=1;i<=n;i++)f[mxv+i]=ia[i],cnt[ia[i]]++;
	}
	void modify(int x,int y,int v)
	{
		if(x==-1)x=1;
		if(y==-1)y=n;
		v+=lazy;
		for(int i=x;i<=y;i++)
		{
			int cur=gf(mxv+i);
			if(cur>v)
			{
				cnt[cur]--;
				cur=cur-v+lazy;
				cnt[cur]++;
				f[mxv+i]=cur;
			}
		}
	}
	void modify_all(int v)
	{
		v+=lazy;
		if(v<=lazy||v>=mx)return;
		int mid=lazy+mx>>1;
		if(v<=mid)
		{
			for(int i=lazy+1;i<=v;i++)
			{
				int nxt=i-lazy+v;
				f[i]=nxt;
				cnt[nxt]+=cnt[i];
				cnt[i]=0;
			}
			lazy=v;
		}
		else
		{
			for(int i=mx;i>v;i--)
			{
				int nxt=i-v+lazy;
				f[i]=nxt;
				cnt[nxt]+=cnt[i];
				cnt[i]=0;
			}
			mx=v;
		}
	}
	int query(int x,int y,int v)
	{
		if(x==-1)x=1;
		if(y==-1)y=n;
		int ret=0;
		for(int i=x;i<=y;i++)ret+=gf(mxv+i)==v+lazy;
		return ret;
	}
	int query_all(int v)
	{
		return v+lazy<=100000?cnt[v+lazy]:0;
	}
}B[block_cnt];
int n,m,a[100111],iid[100111];
int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	getii(n,m);
	for(int i=1;i<=n;i++)geti(a[i]);
	for(int i=1;i<=n;i+=block_size)
	{
		int r=min(n,i+block_size-1);
		B[(i-1)/block_size].init(a+i-1,r-i+1);
		for(int j=i;j<=r;j++)iid[j]=j-i+1;
	}
	for(int i=1;i<=m;i++)
	{
		int op,x,y,v;
		getii(op,x);
		getii(y,v);
		assert(v>0&&v<=100000);
		if(op==1)
		{
			int lid=(x-1)/block_size;
			int rid=(y-1)/block_size;
			if(lid==rid)B[lid].modify(iid[x],iid[y],v);
			else
			{
				B[lid].modify(iid[x],-1,v);
				B[rid].modify(-1,iid[y],v);
				for(int i=lid+1;i<rid;i++)B[i].modify_all(v);
			}
		}
		else
		{
			int ans=0;
			int lid=(x-1)/block_size;
			int rid=(y-1)/block_size;
			if(lid==rid)ans=B[lid].query(iid[x],iid[y],v);
			else
			{
				ans+=B[lid].query(iid[x],-1,v);
				ans+=B[rid].query(-1,iid[y],v);
				for(int i=lid+1;i<rid;i++)ans+=B[i].query_all(v);
			}
			putsi(ans);
		}
	}
	return 0;
}