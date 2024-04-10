// Author -- Frame

#include<cstdio>
#include<cstring>
#include<algorithm>

#define Finline __inline__ __attribute__ ((always_inline))

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7ffffffffffffff;

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline void read(_Tp& x)
{
    register char ch(getchar());
    bool f(false);
    while(ch<48||ch>57) f|=ch==45,ch=getchar();
    x=ch&15,ch=getchar();
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
    if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp& t, Args&... args)
{
    read(t);read(args...);
}
Finline int read_str(char *s)
{
	register char ch(getchar());
	while(ch<65||ch>122||(ch>90&&ch<97)) ch=getchar();
	register char *tar=s;
	*tar=ch,ch=getchar();
	while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=100005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],cnt[N],pos,Cnt;
ll f[N];
Finline void add(const int &u,const int &v){c[++Cnt]=(edge){v,front[u]},front[u]=Cnt;}
Finline bool cmp(const ll &a,const ll &b){return a>b;}
void dfs(int x,int fa)
{
	int C=0;
	for(int i=front[x];i;i=c[i].nxt,++C);
	C-=!!fa;
	cnt[x]-=!!fa;
	f[x]=!!fa;
	if(C<=cnt[x])
	{
		cnt[x]-=C;
		for(int i=front[x];i;i=c[i].nxt)
		{
			if(c[i].v!=fa)
			{
				dfs(c[i].v,x);
				f[x]+=f[c[i].v]+1;
			}
		}
		for(int i=front[x];i&&cnt[x];i=c[i].nxt)
		{
			if(c[i].v!=fa)
			{
				f[x]+=min(cnt[x],cnt[c[i].v])<<1;
				cnt[x]-=min(cnt[x],cnt[c[i].v]);
			}
		}
	}
	else
	{
		std::vector<ll> v;
		for(int i=front[x];i;i=c[i].nxt)
		{
			if(c[i].v!=fa)
			{
				dfs(c[i].v,x);
				v.push_back(f[c[i].v]);
			}
		}
		std::sort(v.begin(),v.end(),cmp);
		for(int i=0;i<cnt[x];++i) f[x]+=v[i]+1;
		cnt[x]=0;
	}
}
int main()
{
	int n,x,y;
	read(n);
	for(int i=1;i<=n;++i) read(cnt[i]);
	for(int i=1;i<n;++i)
	{
		read(x,y);
		add(x,y),add(y,x);
	}
	int s;
	read(s);
	dfs(s,0);
	printf("%lld\n",f[s]);
	return 0;
}