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
	static uint seed=416;
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

const int N=3005;
int x[N],y[N];
std::vector<int> v1[N],v2[N];
int pre[N],nxt[N];
int id[N];
int main()
{
	int n,m,p,k;
	read(n,m,p,k);
	for(int i=1;i<=p;++i)
	{
		read(x[i],y[i]);
		v1[x[i]].pb(i);
		v2[y[i]].pb(i);
	}
	ll ans=0;
	for(int i=1;i<=n;++i)
	{
		memset(pre,0,(p+3)<<2);
		memset(nxt,0,(p+3)<<2);
		memset(id,0,(p+3)<<2);
		int res=0;
		int last=0;
		int cnt=0;
		for(int j=1;j<=m;++j)
		{
			for(auto it:v2[j])
			{
				if(x[it]>=i)
				{
					++cnt;
					pre[it]=last;
					if(last) nxt[last]=it;
					last=it;
				}
			}
		}
		int cur=last;
		int T=k-1;
		while(T--) cur=pre[cur];
		int qwq=last;
		for(int j=cnt;j>=k;--j)
		{
			id[cur]=qwq;
			qwq=pre[qwq];
			cur=pre[cur];
		}
		auto calc=[&](int cur)->int{return id[cur]?(y[cur]-y[pre[cur]])*(m-y[id[cur]]+1):0;};
		cur=last;
		while(cur)
		{
			res+=calc(cur);
			cur=pre[cur];
		}
		for(int j=n;j>=i;--j)
		{
			ans+=res;
			for(auto it:v1[j])
			{
				int tmp=it;
				res-=calc(it);
				if(pre[tmp]) nxt[pre[tmp]]=nxt[tmp];
				if(nxt[tmp])
				{
					res-=calc(nxt[tmp]);
					pre[nxt[tmp]]=pre[tmp];
					res+=calc(nxt[tmp]);
				}
				tmp=pre[tmp];
				int T=k-1;
				while((T--)&&tmp)
				{
					res-=calc(tmp);
					id[tmp]=nxt[id[tmp]];
					res+=calc(tmp);
					tmp=pre[tmp];
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}