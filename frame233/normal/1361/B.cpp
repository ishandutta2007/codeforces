// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;

Finline uint rnd()
{
	static uint seed=0x05ad13b4;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());
	bool f(false);
	while(ch<48||ch>57) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();
	while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args)
{
	read(t);read(args...);
}
Finline int read_str(char *s)
{
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=5000005;
const int mod=1000000007;
template<typename _Tp1,typename _Tp2>Finline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>Finline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
ll ksm(ll a,ll b=mod-2)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod,b>>=1;
	}
	return res;
}
int t[N];
int a[N],b[N];
int p;
bool flag;
int len;
bool used[N];
std::vector<int> e;
int l1,l2;
void ins(int x)
{
	int qwq=x;
	if(!flag)
	{
		chmin(l1,x-1);
		++a[x];
		if(!used[x]) e.pb(x),used[x]=true;
		while(a[x]==p)
		{
			a[x]=0;
			++a[x+1];
			++x;
			if(!used[x]) e.pb(x),used[x]=true;
		}
	}
	else
	{
		chmin(l2,x-1);
		++b[x];
		if(!used[x]) e.pb(x),used[x]=true;
		while(b[x]==p)
		{
			b[x]=0;
			++b[x+1];
			++x;
			if(!used[x]) e.pb(x),used[x]=true;
		}
	}
	int orig=len;
	chmax(len,x+1);
	while(len>0&&a[len-1]==b[len-1])
	{
		--len;
		if(len<l1&&len<l2)
		{
			len=0;
			break;
		}
		if(len<qwq)
		{
			chmin(len,orig);
			break;
		}
	}
	while(len>0&&a[len-1]==b[len-1])
	{
		--len;
		if(len<l1&&len<l2)
		{
			len=0;
			break;
		}
	}
	if(len==0) flag=false;
	else flag=a[len-1]>b[len-1];
}
void MAIN()
{
	l1=l2=inf;
	flag=false,len=0;
	e.clear();
	int n;
	read(n,p);
	for(int i=1;i<=n;++i)
	{
		read(t[i]);
	}
	if(p==1)
	{
		printf("%d\n",n&1);
		return;
	}
	std::sort(t+1,t+n+1);
	std::reverse(t+1,t+n+1);
	for(int i=1;i<=n;++i)
	{
		ins(t[i]);
	}
	ll ans=0;
	if(!flag)
	{
		for(auto it:e)
		{
			ll tmp=ksm(p,it);
			add(ans,tmp*b[it]%mod);
			sub(ans,tmp*a[it]%mod);
			used[it]=false;
			a[it]=b[it]=0;
		}
	}
	else
	{
		for(auto it:e)
		{
			ll tmp=ksm(p,it);
			sub(ans,tmp*b[it]%mod);
			add(ans,tmp*a[it]%mod);
			used[it]=false;
			a[it]=b[it]=0;
		}
	}
	printf("%lld\n",ans);
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
	return 0;
}