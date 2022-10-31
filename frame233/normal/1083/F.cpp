  // Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
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
using std::min;
using std::max;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

Finline uint rnd(){static uint seed=416;return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp,typename... Args>Finline _Tp min(const _Tp &a,const _Tp &b,const Args &...args){return a<b?min(a,args...):min(b,args...);}
template <typename _Tp,typename... Args>Finline _Tp max(const _Tp &a,const _Tp &b,const Args &...args){return a<b?max(b,args...):max(a,args...);}
Finline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=200005;
const int S=350;
int pool[N<<8],*p=pool;
int *_pool[N<<1],**_p=_pool;
ll ans;
int res;
bool mark[N];
struct DS{
	int *tag,*a;
	int **cnt;
	int max_block;
	int size;
	bool __,is_block;
	void init(std::vector<int> seq,bool ___)
	{
		is_block=SZ(seq)>S;
		__=___;
		size=SZ(seq);
		max_block=(SZ(seq)-1)/S+1;
		tag=p,p+=max_block+1;
		a=p,p+=SZ(seq)+1;
		if(is_block)
		{
			cnt=_p,_p+=max_block+1;
			for(int i=0;i<max_block;++i) cnt[i]=p,p+=1<<14;
		}
		for(int i=0;i<size;++i) a[i]=seq[i];
		for(int i=1;i<size;++i) a[i]^=a[i-1];
		for(int i=0;i<size;++i) ans+=!a[i],(is_block)&&(++cnt[i/S][a[i]]);
		if(__) res+=a[size-1]!=tag[(size-1)/S];
	}
	void upd(int pos,int val)
	{
		if(__)res-=a[size-1]!=tag[(size-1)/S];
		if(!is_block)
		{
			for(int orig=pos/S,i=pos;i/S==orig&&i<size;++i)
			{
				ans-=a[i]==tag[orig];
				a[i]^=val;
				ans+=a[i]==tag[orig];
			}
		}
		else
		{
			for(int i=pos/S+1;i<max_block;++i)
			{
				ans-=cnt[i][tag[i]];
				tag[i]^=val;
				ans+=cnt[i][tag[i]];
			}
			for(int orig=pos/S,i=pos;i/S==orig&&i<size;++i)
			{
				ans-=a[i]==tag[orig];
				--cnt[orig][a[i]];
				a[i]^=val;
				++cnt[orig][a[i]];
				ans+=a[i]==tag[orig];
			}
		}
		if(__)res+=a[size-1]!=tag[(size-1)/S];
	}
}ds[N];
int A[N],B[N];
int a[N];
std::vector<int> seq[N];
int main()
{
	int n,k,q;read(n,k,q);int x,y;
	for(int i=0;i<n;++i) read(a[i]),A[i]=a[i];
	for(int i=0;i<n;++i) read(x),a[i]^=x,B[i]=x;
	for(int i=n-1;i>0;--i) a[i]^=a[i-1];
	for(int i=0;i<n;++i) seq[i%k].pb(a[i]);
	for(int i=0;i+1<k;++i) mark[(n-i-1)%k]=true;
	for(int i=0;i<k;++i) ds[i].init(seq[i],mark[i]);
	if(!res) printf("%lld\n",n-ans);
	else printf("-1\n");
	char opt;
	while(q--)
	{
		opt=getchar();while(opt!='a'&&opt!='b') opt=getchar();
		read(x,y);--x;
		if(opt=='a')
		{
			y^=A[x];
			A[x]^=y;
		}
		else
		{
			y^=B[x];
			B[x]^=y;
		}
		ds[x%k].upd(x/k,y);
		++x;if(x<n)ds[x%k].upd(x/k,y);
		if(!res) printf("%lld\n",n-ans);
		else printf("-1\n");
	}
	return 0;
}