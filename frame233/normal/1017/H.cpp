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

const int N=200005;
const int mod=998244353;
int e[N],a[N],inv[N];
struct info{
	int l,r,k,block,id;
	inline bool operator < (const info &o)const{return block==o.block?block&1?r>o.r:r<o.r:block<o.block;}
}q[N];
int n,m,b[N],ans,k,res[N],_[N];
inline void add(int x){ans=1LL*ans*(a[x]+k-(b[x]++))%mod;}
inline void del(int x){ans=1LL*ans*inv[a[x]+k-(--b[x])]%mod;}
void solve(int L,int R)
{
	ans=1,k=q[L].k;
	int mul=1;
	memset(b,0,sizeof(b));
	for(int i=0;i<=n;++i) _[i]=mul,mul=1LL*mul*((1LL*k*m+i+1)%mod)%mod;
	int B=max(1,(int)(n/sqrt(R-L+1)));
	for(int i=L;i<=R;++i) q[i].block=q[i].l/B;
	std::sort(q+L,q+R+1);
	int l=1,r=0;
	for(int i=L;i<=R;++i)
	{
		while(r<q[i].r) add(e[++r]);
		while(l>q[i].l) add(e[--l]);
		while(r>q[i].r) del(e[r--]);
		while(l<q[i].l) del(e[l++]);
		res[q[i].id]=1LL*ans*_[n-(q[i].r-q[i].l+1)]%mod;
	}
}
int main()
{
	inv[0]=inv[1]=1;for(int i=2;i<N;++i) inv[i]=1LL*inv[mod%i]*(mod-mod/i)%mod;
	int Q;read(n,m,Q);
	for(int i=1;i<=n;++i) read(e[i]),++a[e[i]];
	for(int i=1;i<=Q;++i) read(q[i].l,q[i].r,q[i].k),q[i].id=i;
	std::sort(q+1,q+Q+1,[&](const info &a,const info &b)->bool{return a.k<b.k;});
	for(int i=1;i<=Q;++i)
	{
		int j=i;
		while(j<Q&&q[j+1].k==q[i].k) ++j;
		solve(i,j),i=j;
	}
	for(int i=1;i<=Q;++i) printf("%d\n",res[i]);
	return 0;
}