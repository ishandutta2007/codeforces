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
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=100005;
const int mod=998244353;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
struct node{
	ll pos,val;
	inline bool operator < (const node &o)const
	{
		return pos<o.pos;
	}
}a[10000005];
int pos;
inline void push(ll l,ll r,ll opt)
{
	a[++pos]={l,opt},a[++pos]={r,-opt};
}
void calc(ll x,ll y,int opt)
{
	ll cur=0;
	for(int i=60;i>=0;--i)
	{
		int a=(x>>i)&1,b=(y>>i)&1;
		if(a&&b)
		{
			ll tmp=cur|(1LL<<i);
			push(tmp,tmp+(1LL<<i),((x&((1LL<<i)-1))+(y&((1LL<<i)-1))+2)*opt);
			push(cur,cur+(1LL<<i),(1LL<<i)*opt);
		}
		else if(a) push(cur,cur+(1LL<<i),((y&((1LL<<i)-1))+1)*opt),cur|=1LL<<i;
		else if(b) push(cur,cur+(1LL<<i),((x&((1LL<<i)-1))+1)*opt),cur|=1LL<<i;
	}
	push(cur,cur+1,opt);
}
ll l[N],r[N];
inline ll f(ll x)
{
	if(x<0) return 0LL;
	x%=mod;
	return (x*(x+1)/2)%mod;
}
int main()
{
	int na;read(na);
	for(int i=1;i<=na;++i) read(l[i],r[i]);
	int nb;read(nb);
	ll L,R;
	for(int i=1;i<=nb;++i)
	{
		read(L,R);
		for(int j=1;j<=na;++j) calc(R,r[j],1),calc(R,l[j]-1,-1),calc(L-1,r[j],-1),calc(L-1,l[j]-1,1);
	}
	std::sort(a+1,a+pos+1);
	ll tmp=0,last=0,ans=0;
	for(int i=1;i<=pos;++i)
	{
		if(tmp) add(ans,f(a[i].pos-1)),sub(ans,f(last-1));
		tmp+=a[i].val,last=a[i].pos;
	}
	printf("%lld\n",ans);
	return 0;
}