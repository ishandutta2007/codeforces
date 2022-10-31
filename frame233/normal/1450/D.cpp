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

const int N=300005;
int n,a[N],ans[N];
bool tag[N];
int _q[N],_l,_r;
bool check(int k)
{
	memset(tag,0,(n+3)<<2);
	_l=1,_r=0;
	for(int i=1;i<=n;++i)
	{
		while(_l!=_r+1&&i-_q[_l]>=k) ++_l;
		while(_l!=_r+1&&a[i]<=a[_q[_r]]) --_r;
		_q[++_r]=i;
		if(i>=k) tag[a[_q[_l]]]=true;
	}
	for(int i=1;i<=n-k+1;++i)if(!tag[i])return false;
	return true;
}
void MAIN()
{
	read(n);
	for(int i=1;i<=n;++i) read(a[i]);
	int l=2,r=n+1;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	putchar(check(1)+48);
	for(int i=2;i<=n;++i) putchar((i>=l)+48);
	putchar('\n');
}
int main()
{
	int _;read(_);
	while(_--) MAIN();
	return 0;
}