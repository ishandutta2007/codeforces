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
typedef std::pair<int,int> pl;

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
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&((a=b),0);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&((a=b),0);}
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

const int N=200005;
int L[N],R[N];
struct node{
	int R,id;
	Finline bool operator < (const node &o)const
	{
		return R>o.R;
	}
};
std::priority_queue<node> q;
std::vector<node> v[N];
int ans[N],rev[N];
struct seg_tr{
	pi f[N<<2];
	int n,M;
	void init(int _n)
	{
		n=_n;
		for(M=1;M<=n+1;M<<=1);
	}
	Finline void Upd(int x,pi y)
	{
		f[x+=M]=y;
		for(x>>=1;x;x>>=1) f[x]=::max(f[x<<1],f[x<<1|1]);
	}
	Finline pi Qry(int s,int t)
	{
		pi ans=mkpr(0,0);
		for(s+=M-1,t+=M+1;s^t^1;s>>=1,t>>=1)
		{
			if(~s&1) chmax(ans,f[s^1]);
			if(t&1) chmax(ans,f[t^1]);
		}
		return ans;
	}
}tr;
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(L[i],R[i]);
		v[L[i]].pb((node){R[i],i});
	}
	for(int i=1;i<=n;++i)
	{
		for(auto it:v[i])
		{
			q.push(it);
		}
		ans[q.top().id]=i;
		rev[i]=q.top().id;
		q.pop();
	}
	tr.init(n);
	for(int i=1;i<=n;++i)
	{
		int id=rev[i];
		pi tmp=tr.Qry(L[id],i);
		if(tmp.second&&tmp.first>=i)
		{
			printf("NO\n");
			for(int i=1;i<=n;++i) printf("%d ",ans[i]);
			printf("\n");
			std::swap(ans[id],ans[tmp.second]);
			for(int i=1;i<=n;++i) printf("%d ",ans[i]);
			printf("\n");
			return 0;
		}
		tr.Upd(i,mkpr(R[id],id));
	}
	printf("YES\n");
	for(int i=1;i<=n;++i) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}