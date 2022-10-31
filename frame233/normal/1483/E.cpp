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
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return !b?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}

const int N=100005;
const double p=0.3,q=0.7;
ll r;
char s[15];
int cnt;
inline ll ASK(ll x)
{
	printf("? %lld\n",x),fflush(stdout);
	read_str(s);
	return s[0]=='L';
}
inline int ask(ll x)
{
	++cnt;
	if(ASK(x))return r+=x,1;
	else return r-=x,0;
}
void MAIN()
{
	ll L=0,R=1e14;r=1,cnt=0;
	while(2LL*L<R)
	{
		ll mid;
		if(r>=3LL*R)mid=(L+R+1)>>1;
		else mid=min(r,L+(R-L)/3);
		if(ask(mid))L=mid;
		else R=mid-1;
	}
	while(L<R)
	{
		if(L+1==R)
		{
			while(r<R)ask(L);
			if(ask(R))L=R;
			else R=L;
			break;
		}
		if(r>=(105-cnt)*R)
		{
			ll mid=(L+R+1)>>1;
			if(ask(mid))L=mid;
			else R=mid-1;
			continue;
		}
		if(r>=5LL*R)
		{
			ll mid=L+2LL*(R-L)/5;
			if(mid==L)++mid;
			if(ask(mid))L=mid;
			else R=mid-1;
			continue;
		}
		ll m1=(L+L+R+1)/3,m2=(L+R+R+3)/3;
		if(m1==L)++m1;
		if(m2<m1)++m2;
		while(r<m1)ask(L);
		if(ask(m1))
		{
			L=m1;
			while(r<m2)ask(L);
			if(ask(m2))L=m2;
			else R=m2-1;
		}
		else R=m1-1;
	}
	printf("! %lld\n",L),fflush(stdout);
}
int main()
{
	int _;read(_);
	while(_--)MAIN();
	return 0;
}