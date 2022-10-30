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
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}

const int N=100005;
int a[N],f[N],c[N];
template<typename _Tp>
class heap{
public:
	std::priority_queue<_Tp,std::vector<_Tp>,std::greater<_Tp>> q1,q2;
	int siz;
	inline bool empty(){return !siz;}
	inline int size(){return siz;}
	inline void push(const _Tp &o){q1.push(o);++siz;}
	inline void pop(const _Tp &o){q2.push(o);--siz;}
	inline _Tp top()
	{
		while(!q2.empty()&&q1.top()==q2.top()) q1.pop(),q2.pop();
		return q1.top();
	}
};
heap<int> S;
int main()
{
	int n;read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	memset(f,63,sizeof(f)),memset(c,63,sizeof(c));
	for(int i=1;i<=n;++i)S.push(inf);
	f[0]=1;
	int tag=0;
	for(int i=2;i<=n;++i)
	{
		int tp=c[a[i]],val;
		S.pop(tp),val=S.top(),S.push(tp);
		++val,chmin(val,min(c[a[i]],f[0]+1)),f[i-1]=val;
		if(a[i]!=a[i-1])++tag,--f[i-1];
		S.pop(c[a[i-1]]),chmin(c[a[i-1]],f[i-1]),S.push(c[a[i-1]]);
	}
	printf("%d\n",*std::min_element(f,f+n)+tag);
	return 0;
}