// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-10;

uint seed=19260817;
const uint _RAND_MAX_=4294967295u;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&((a=b),1);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp &x)
{
	register char ch(getchar());
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
	register char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	register char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=100005;
Finline ull HI(ull x){return x>>32;}
Finline ull LOW(ull x){return x&(0xffffffff);}
struct int128{
	ull high,low;
	Finline bool operator > (const int128 &o)const
	{
		return high==o.high?low>o.low:high>o.high;
	}
};
Finline int128 mul(ull a,ull b)
{
	ull t1=LOW(a)*LOW(b);
	ull t2=LOW(a)*HI(b)+HI(a)*LOW(b)+HI(t1);
	return (int128){HI(a)*HI(b)+HI(t2),(t2<<32)+LOW(t1)};
}
struct node{
	ll last,cur,id,type;
	Finline bool operator < (const node &o)const
	{
		return mul(cur,o.last)>mul(o.cur,last);
	}
};
struct Node{
	ll val,id,type;
	Finline bool operator < (const Node &o)const
	{
		return type<o.type;
	}
};
std::pair<ll,ll> maxx[N];
std::vector<Node> v[N];
node t[N];
int pos;
ll a[N];
int main()
{
	int n,m,k;
	read(n,m,k);
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
	}
	int opt;
	ll x,y;
	for(int i=1;i<=m;++i)
	{
		read(opt,x,y);
		if(opt==1)
		{
			chmax(maxx[x],std::make_pair(y,(ll)i));
		}
		else if(opt==2)
		{
			v[x].push_back((Node){y,i,2});
		}
		else
		{
			t[++pos]=(node){1,y,i,3};
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(maxx[i].first)
		{
			maxx[i].first-=a[i];
			if(maxx[i].first>0) v[i].push_back((Node){maxx[i].first,maxx[i].second,1});
		}
	}
	for(int i=1;i<=n;++i)
	{
		std::sort(v[i].begin(),v[i].end(),[](const Node &a,const Node &b)->bool{return a.val>b.val;});
		ll last=a[i];
		for(auto it:v[i])
		{
			t[++pos]=(node){last,last+it.val,it.id,it.type};
			last+=it.val;
		}
	}
	std::sort(t+1,t+pos+1);
	std::vector<Node> ans;
	for(int i=1;i<=k&&i<=pos;++i)
	{
		ans.push_back((Node){t[i].cur-t[i].last,t[i].id,t[i].type});
	}
	std::sort(ans.begin(),ans.end());
	printf("%d\n",(int)ans.size());
	for(auto it:ans) printf("%lld ",it.id);
	printf("\n");
	return 0;
}