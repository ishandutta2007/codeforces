// Author -- xyr2005

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

Finline uint rnd(){static uint seed=416;return seed+=1910166719u,seed^=seed>>5,seed+=3338096008u,seed^=seed<<17,seed+=39740769u,seed^=seed>>13;}
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

const int N=(1<<18)+5;
int a[N];
struct node{
	int val,pos;
	Finline bool operator > (const node &o)const
	{
		return val==o.val?pos>o.pos:val>o.val;
	}
};
struct Node{
	node a,b;
	Finline void merge(const node &o)
	{
		if(o>a)
		{
			if(a.pos!=o.pos) b=a;
			a=o;
		}
		else if(o>b&&o.pos!=a.pos) b=o;
	}
	Finline void merge(const Node &o)
	{
		merge(o.a),merge(o.b);
	}
}s[N];
int fa[N];
node val[N];
bool mark[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int main()
{
	int n;read(n);
	ll sum=0;
	for(int i=1;i<=n;++i) read(a[i]),sum+=a[i],fa[i]=i;
	ll ans=0;
	while(true)
	{
		memset(val,0,sizeof(val));
		memset(s,0,sizeof(s));
		for(int i=0;i<=n;++i) s[a[i]].merge((node){a[i],find(i)});
		for(int i=0;i<18;++i) for(int j=0;j<1<<18;++j) if((j>>i)&1) s[j].merge(s[j^(1<<i)]);
		for(int i=0;i<=n;++i)
		{
			Node tmp=s[((1<<18)-1)^a[i]];
			tmp.a.val+=a[i],tmp.b.val+=a[i];
			int b=find(i);
			if(tmp.a.pos!=b){if(tmp.a>val[b]) val[b]=tmp.a;}
			else if(tmp.b>val[b]) val[b]=tmp.b;
		}
		for(int i=0;i<=n;++i) mark[i]=find(i)==i;
		for(int i=0;i<=n;++i)
		{
			if(mark[i])
			{
				int a=find(i),b=find(val[i].pos);
				if(a!=b) fa[a]=b,ans+=val[i].val;
			}
		}
		int cnt=0;
		for(int i=0;i<=n;++i) cnt+=find(i)==i;
		if(cnt==1)
		{
			printf("%lld\n",ans-sum);
			return 0;
		}
	}
	return 0;
}