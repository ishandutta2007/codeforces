// Author -- xyr2005

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;
using std::min;
using std::max;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>inline void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}

const int N=1000005;
const int mod=1000000007;
int a[N],cnt[N],_[4],st[4],__[4];
bool vis[N];
void MAIN()
{
	memset(_,0,sizeof(_));
	int n;read(n);
	for(int i=1;i<=n;++i) read(a[i]),vis[i]=false,cnt[i]=0;
	for(int i=1;i<=n;++i)if(!vis[i])
	{
		int cur=i,qwq=0;
		while(!vis[cur]) vis[cur]=true,cur=a[cur],++qwq;
		++cnt[qwq];
	}
	if(n%3==0)
	{
		ll res=0;
		for(int i=1;i<=n;++i)
		{
			_[3]+=cnt[i]*(i/3);
			res+=cnt[i]*(i/3-1);
			if(i%3!=0) _[i%3]+=cnt[i],res+=cnt[i];
		}
		while(_[2]>_[1]) --_[2],_[1]+=2,++res;
		while(_[2]<_[1]) _[1]-=2,++_[2],++res;
		res+=_[2];
		ll ans=1;
		for(int i=1;i<=n/3;++i) ans=3LL*ans%mod;
		printf("%lld %lld\n",ans,res);
	}
	else if(n%3==1)
	{
		ll res=0,A=1e18;
		for(int i=1;i<=n;++i)if(i==1||i%3!=1)
		{
			_[3]+=cnt[i]*(i/3);
			res+=cnt[i]*(i/3-1);
			if(i%3!=0) _[i%3]+=cnt[i],res+=cnt[i];
		}
		ll _res=res;
		memcpy(__,_,sizeof(__));
		for(int type=0;type<2;++type)
		{
			res=_res;
			memcpy(_,__,sizeof(_));
			bool tag=type;
			for(int i=4;i<=n;i+=3)if(cnt[i])
			{
				if(tag)
				{
					tag=false;
					_[3]+=(i-4)/3,_[2]+=2;
					res+=i/3-1,--cnt[i];
				}
				_[3]+=cnt[i]*(i/3);
				res+=cnt[i]*(i/3-1);
				if(i%3!=0) _[i%3]+=cnt[i],res+=cnt[i];
			}
			memcpy(st,_,sizeof(st));
			ll tmp=res;
			if(!_[2]&&_[1]&&_[3]) _[2]+=2,--_[1],--_[3],++res;
			while(_[2]<2)
			{
				while(_[2]<2&&_[1]>=2) _[1]-=2,++_[2],++res;
				if(_[2]<2) --_[3],++_[2],++_[1],++res;
			}
			_[2]-=2;
			while(_[2]>_[1]) --_[2],_[1]+=2,++res;
			while(_[2]<_[1]) _[1]-=2,++_[2],++res;
			res+=_[2];
			
			std::swap(tmp,res),memcpy(_,st,sizeof(_));
			while(_[2]<2)
			{
				while(_[2]<2&&_[1]>=2) _[1]-=2,++_[2],++res;
				if(_[2]<2) --_[3],++_[2],++_[1],++res;
			}
			_[2]-=2;
			while(_[2]>_[1]) --_[2],_[1]+=2,++res;
			while(_[2]<_[1]) _[1]-=2,++_[2],++res;
			res+=_[2];
			chmin(A,min(res,tmp));
		}
		ll ans=4;
		for(int i=1;i<n/3;++i) ans=3LL*ans%mod;
		printf("%lld %lld\n",ans,A);
	}
	else
	{
		ll res=0;
		for(int i=1;i<=n;++i)
		{
			_[3]+=cnt[i]*(i/3);
			res+=cnt[i]*(i/3-1);
			if(i%3!=0) _[i%3]+=cnt[i],res+=cnt[i];
		}
		if(!_[2])
		{
			if(_[1]>=2) ++_[2],_[1]-=2,++res;
			else --_[3],++_[2],++_[1],++res;
		}
		--_[2];
		while(_[2]>_[1]) --_[2],_[1]+=2,++res;
		while(_[2]<_[1]) _[1]-=2,++_[2],++res;
		res+=_[2];
		ll ans=2;
		for(int i=1;i<=n/3;++i) ans=3LL*ans%mod;
		printf("%lld %lld\n",ans,res);
	}
}
int main()
{
	int _;read(_);
	while(_--) MAIN();
	return 0;
}