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
const int maxn=1001111;


namespace GEN
{
	vector<int> con[maxn];
	vector<int> v,a;
	int n;
	void dfs(int x)
	{
		v.PB(x);
		for(int i=0;i<con[x].size();i++)
		{
			dfs(con[x][i]);
			v.PB(x);
		}
	}
	int main()
	{
		v.clear();
		a.clear();
		int seed;
//		cin>>seed;
		seed=1;
		srand(seed);
		n=500000;
//		n=1000;
//		cerr<<"n="<<n<<endl;
		for(int i=2;i<=n;i++)
		{
//			con[rand()%(i-1)+1].PB(i);
			
//			con[i-1].PB(i);
			con[i-1-rand()%min(10,i-1)].PB(i);
		}
		dfs(1);
		int p=1,q=10;
		for(int i=0;i<v.size();i++)
		{
			if(rand()%q<p)a.PB(v[i]);
			else a.PB(0);
		}
		assert(a.size()==n+n-1);
//		for(int i=0;i<n+n-1;i++)cerr<<a[i]<<" ";
//		cerr<<"gen ok"<<endl;
		return 0;
	}
};

int n,a[maxn],pre[maxn],nxt[maxn],rnxt[maxn],lpre[maxn];
int lpos[maxn],lv[maxn];
bool used[maxn];
int it=1;
void failed(int id=0)
{
	puts("no");
//	cerr<<"id="<<id<<endl;
	exit(0);
}
int getunused(){while(used[it])it++;if(it>n)failed(3);used[it]=1;return it;}
void connect(int x,int y)
{
	assert(a[x]>0&&a[y]>0);
	pre[y]=x;
	nxt[x]=y;
}
const int B=1000010;
vector<int> buc[maxn*2];
void connect0(int x,int y)
{
	connect(rnxt[x]-1,y);
}
void solve0(int l,int r,bool popl=1)
{
	if(l>r)return;
	
//	cerr<<"solve0:"<<l<<","<<r<<endl;
	if(popl)buc[lv[l]].pop_back();
	if(l==r)
	{
		return;
	}
	int llv=lv[l];
	if(a[l]==0&&a[r]==0)
	{
		int r0=buc[lv[l]+5].back();
		assert(l<r0&&r0<r);
		solve0(l,r0,0);
		llv+=5;
		l=r0;
	}
	if(a[l]>0&&a[r]==0)
	{
		int lst=l;
		while(true)
		{
			int r0=buc[llv-1].back();
			assert(lst<r0&&r0<=r);
			buc[llv-1].pop_back();
			a[r0]=a[lst];
			connect0(lst,r0);
			solve0(rnxt[lst],lpre[r0]);
			lst=r0;
			if(r0==r)break;
		}
	}
	else if(a[l]==0&&a[r]>0)
	{
		a[l]=a[r];
		int lst=l;
		while(true)
		{
			int r0=buc[llv].size()==0?r+1:buc[llv].back();
			if(r0>r)
			{
				buc[lv[r]].pop_back();
				connect0(lst,r);
				solve0(rnxt[lst],lpre[r]);
				break;
			}
			else
			{
				buc[llv].pop_back();
				a[r0]=a[lst];
				connect0(lst,r0);
				solve0(rnxt[lst],lpre[r0]);
				lst=r0;
			}
		}
	}
}
int scnt;
void solve(int l,int r)
{
//	cerr<<"solve:"<<l<<","<<r<<endl;
	if(l>r)return;
	scnt++;
	if(l==r)
	{
		if(!a[l])a[l]=getunused();
		return;
	}
	assert(a[l]==a[r]);
	if(a[l]&&nxt[l]!=r)//divide into smaller parts
	{
		for(int i=l;i<r;)
		{
			int to=nxt[i];
			solve(i,nxt[i]);
			i=to;
		}
		return;
	}
	if(nxt[l]==r)
	{
		nxt[l]=0;pre[r]=0;
		a[r]=0;
	}
	//count nonzero terms
	int cnt=0,tot=0;
	for(int i=l;i<=r;)
	{
		cnt+=a[i]>0;tot++;
		int pi=i;
		while(i<r&&nxt[i])
		{
			if(nxt[i]>=r)failed(3);
			i=nxt[i];
		}
		i++;
		lpre[i]=pi;
		rnxt[pi]=i;
	}
	assert(tot&1);
	if(cnt>(tot+1)/2)failed(3);
	//add nonzero terms
	for(int i=l;i<r&&cnt<(tot+1)/2;i=rnxt[i])
	{
		if(!a[i])
		{
			a[i]=getunused();
			cnt++;
		}
	}
	assert(cnt==(tot+1)/2);
	assert(a[r]==0);
	//initialize levels and buckets
	int curlv=0;
	for(int i=l;i<=r;i=rnxt[i])
	{
		if(a[i]>0)curlv++;
		else curlv--;
		lv[i]=curlv*2+(a[i]>0)+B;
	}
	lpre[l]=0;
	for(int i=r;i>=l;i=lpre[i])buc[lv[i]].PB(i);

	solve0(l,r);
	for(int i=r;i>=l;i=lpre[i])assert(buc[lv[i]].size()==0);
	for(int i=l+1;i<r;)
	{
		while(i<r&&nxt[i])
		{
			int to=nxt[i];
			assert(to>i&&to<=r);
			solve(i,to);
			i=to;
		}
		i++;
	}
}
int main()
{	
//	freopen("1053E.in","r",stdin);
//	GEN::main();
//	n=GEN::n;
	geti(n);
//	n=500000;
	for(int i=1;i<n+n;i++)geti(a[i]);
//	for(int i=1;i<n+n;i++)a[i]=GEN::a[i-1];
	if(a[1]&&a[n+n-1]&&a[1]!=a[n+n-1])failed();
	if(a[1])a[n+n-1]=a[1];
	if(a[n+n-1])a[1]=a[n+n-1];
	for(int i=1;i<n+n;i++)
	{
		assert(a[i]>=0&&a[i]<=n);
		if(!a[i])continue;
		used[a[i]]=1;
		if(lpos[a[i]])
		{
			connect(lpos[a[i]],i);
			if((i-pre[i])%2==1)
			{
				failed();
			}
		}
		lpos[a[i]]=i;
	}
	solve(1,n+n-1);
//	cerr<<"scnt="<<scnt<<endl;
	puts("yes");
	for(int i=1;i<n+n;i++)puti(a[i]);
	return 0;
}