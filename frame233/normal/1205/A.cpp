// luogu-judger-enable-o2
// Author -- Frame
 
#pragma GCC optimize(2)
 
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<ctime>
 
#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
 
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
 
const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-8;
 
uint seed=19260817;
const uint _RAND_MAX_=4294967295u;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}
 
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp& x)
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
template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
 
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}
 
template <typename T>
struct hash_map_t {
    std::vector <T> v, val, nxt;
    std::vector <int> head;
    int mod, tot, lastv;
    T lastans;
    bool have_ans;
 
    hash_map_t (int md = 0) {
        head.clear(); v.clear(); val.clear(); nxt.clear(); tot = 0; mod = md;
        nxt.resize(1); v.resize(1); val.resize(1); head.resize(mod);
        have_ans = 0;
    }
 
    void clear() { *this = hash_map_t(mod); }
 
    bool count(int x) {
        int u = x % mod;
        for(register int i = head[u]; i; i = nxt[i]) {
            if(v[i] == x) {
                have_ans = 1;
                lastv = x;
                lastans = val[i];
                return 1;
            }
        }
        return 0;
    }
 
    void ins(int x, int y) {
        int u = x % mod;
        nxt.push_back(head[u]); head[u] = ++tot;
        v.push_back(x); val.push_back(y);
    }
 
    int qry(int x) {
        if(have_ans && lastv == x) return lastans;
        count(x);
        return lastans;
    }
};
struct Lbase{
	ll a[65];
	bool Insert(ll x)
	{
		for(int i=64;i>=0;--i)
		{
			if((x>>i)&1)
			{
				if(a[i])
				{
					x^=a[i];
				}
				else
				{
					a[i]=x;
					return 1;
				}
			}
		}
		return 0;
	}
	ll Query()
	{
		ll ans=0;
		for(int i=50;i>=0;--i)
		{
			if((ans^a[i])>ans)
			{
				ans^=a[i];
			}
		}
		return ans;
	}
}B;
void init()
{
	srand(time(0));
	B.Insert(rand());
}
ll a[N<<2],sum[N<<2];
bool check(int n)
{
	for(int i=1;i<=n;++i)
	{
		a[i+n]=a[i];
	}
	for(int i=1;i<=n<<1;++i)
	{
		sum[i]=sum[i-1]+a[i];
	}
	ll minn=INF,maxx=-INF;
	for(int i=1;i<=n;++i)
	{
		chmax(maxx,sum[i+(n>>1)-1]-sum[i-1]);
		chmin(minn,sum[i+(n>>1)-1]-sum[i-1]);
	}
	return abs(maxx-minn)<=1;
}
int main()
{
	int n;
	read(n);
	if(!(n&1))
	{
		printf("NO\n");
		return 0;
	}
	for(int i=1;i<=n;++i)
	{
		if(i&1)
		{
			a[i]=(i<<1)-1;
			a[i+n]=i<<1;
		}
		else
		{
			a[i]=i<<1;
			a[i+n]=(i<<1)-1;
		}
	}
	if(check(n<<1))
	{
		printf("YES\n");
		for(int i=1;i<=n<<1;++i) printf("%lld ",a[i]);
		printf("\n");
	}
	else
	{
		printf("NO\n");
	}
    return 0;
}