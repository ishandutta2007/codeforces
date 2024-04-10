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
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
 
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
 
const int N=100005,mod=1000000007;
struct node{
    ll val;
    int cnt;
    Finline bool operator < (const node &o)const
    {
        return val<o.val; 
    }
    Finline bool operator == (const node &o)const
    {
        return val==o.val;
    }
    Finline bool operator < (const ll &o)const
    {
        return val<o; 
    }
};
struct edge{
    int v,nxt;
}c[N<<1];
int front[N],cnt;
ll a[N];
Finline void add(const int &u,const int &v)
{
    c[++cnt]=(edge){v,front[u]},front[u]=cnt;
}
ll ans;
Finline void _add(ll &a,const ll &b){(a+=b)>=mod&&(a-=mod);}
void dfs(int x,int fa,const std::vector<node> &_v)
{
    std::vector<node> v;
    for(auto it:_v)
    {
        v.emplace_back((node){gcd(a[x],it.val),it.cnt});
    }
    v.emplace_back((node){a[x],1});
    std::sort(v.begin(),v.end());
    ll last=-1;
    std::vector<node>::iterator _it;
    for(std::vector<node>::iterator it=v.begin();it!=v.end();)
    {
    	if(it->val==last)
    	{
    		_it->cnt+=it->cnt;
    		v.erase(it);
		}
		else
		{
			last=it->val;
			_it=it;
			++it;
		}
    }
    for(auto it:v)
    {
    	_add(ans,it.val*it.cnt%mod);
    }
    for(int i=front[x];i;i=c[i].nxt)
    {
        if(c[i].v!=fa)
        {
            dfs(c[i].v,x,v);
        }
    }
}
int main()
{
    int n;
    read(n);
    for(int i=1;i<=n;++i) read(a[i]);
    int x,y;
    for(int i=1;i<n;++i)
    {
        read(x,y);
        add(x,y),add(y,x);
    }
    std::vector<node> v; 
    dfs(1,0,v);
    printf("%lld\n",ans);
    return 0;
}