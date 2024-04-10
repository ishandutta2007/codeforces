// Author -- Frame
#pragma GCC optimize(2)

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>
#include<map>
#include<bitset>
#include<queue>

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

const int N=5005;
const int mod=1000000007;
int s[N];
int f[N],h[N];
struct node{
    int a,b;
}a[N];
int n,m;
int calc1(int x,int y)
{
    int cnt=0;
    for(int i=1;i<=n;++i)
    {
        if(s[i]==x)
        {
            ++cnt;
            if(cnt==y)
            {
                return i;
            }
        }
    }
    return -1;
}
int calc2(int x,int y)
{
    int cnt=0;
    for(int i=n;i>=1;--i)
    {
        if(s[i]==x)
        {
            ++cnt;
            if(cnt==y)
            {
                return i;
            }
        }
    }
    return -1;
}
template <typename _Tp1,typename _Tp2>Finline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template <typename _Tp1,typename _Tp2>Finline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
int dp1[N],dp2[N];
std::vector<node> v[N];
void solve(int x)
{
	int lim=a[x].a;
	for(int i=1;i<=n;++i) v[i].clear();
	int pos=f[x];
	for(int i=1;i<=m;++i)
	{
		if(i!=x&&(a[i].a<=lim||a[i].b>lim))
		{
			v[f[i]].push_back(a[i]);
		}
	}
	dp1[0]=0,dp2[0]=1;
	for(int i=1;i<=n;++i)
	{
		if((int)v[i].size()==0)
		{
			dp1[i]=dp1[i-1];
			dp2[i]=dp2[i-1];
			continue;
		}
		if(i!=pos)
		{
			int cnt=0,cnt1=0,cnt2=0;
			for(auto it:v[i])
			{
				if(it.a<=lim)
				{
					++cnt1;
				}
				if(it.b>lim)
				{
					++cnt2;
				}
				if(it.a<=lim&&it.b>lim)
				{
					++cnt;
				}
			}
			int tmp=(cnt1-cnt)*cnt2+cnt*(cnt2-cnt)+cnt*(cnt-1);
			if(tmp)
			{
				dp1[i]=dp1[i-1]+2;
				dp2[i]=1ll*dp2[i-1]*tmp%mod;
			}
			else
			{
				dp1[i]=dp1[i-1]+1;
				dp2[i]=1ll*dp2[i-1]*(cnt1+cnt2)%mod;
			}
		}
		else
		{
			int cnt2=0;
			for(auto it:v[i])
			{
				if(it.b>lim)
				{
					++cnt2;
				}
			}
			if(cnt2)
			{
				dp1[i]=dp1[i-1]+1;
				dp2[i]=1ll*dp2[i-1]*cnt2%mod;
			}
			else
			{
				dp1[i]=dp1[i-1];
				dp2[i]=dp2[i-1];
			}
		}
	}
	++dp1[n];
}
void solve()
{
	for(int i=1;i<=n;++i) v[i].clear();
	for(int i=1;i<=m;++i)
	{
		v[f[i]].push_back(a[i]);
	}
	dp1[0]=0,dp2[0]=1;
	for(int i=1;i<=n;++i)
	{
		if((int)v[i].size()==0)
		{
			dp1[i]=dp1[i-1];
			dp2[i]=dp2[i-1];
			continue;
		}
		dp1[i]=dp1[i-1]+1;
		dp2[i]=1ll*dp2[i-1]*(int)v[i].size()%mod;
	}
}
signed main()
{
    read(n,m);
    for(int i=1;i<=n;++i)
    {
        read(s[i]);
    }
    for(int i=1;i<=m;++i)
    {
        read(f[i],h[i]);
        a[i]=(node){calc1(f[i],h[i]),calc2(f[i],h[i])};
        if(!~a[i].a)
        {
        	--i;
        	--m;
        	continue;
        }
    }
    if(!m)
    {
    	printf("0 1\n");
    	return 0;
    }
    int ans1=0,ans2=0;
    for(int i=1;i<=m;++i)
    {
    	solve(i);
    	if(dp1[n]>ans1)
    	{
    		ans1=dp1[n];
    		ans2=dp2[n];
    	}
    	else if(dp1[n]==ans1)
    	{
    		add(ans2,dp2[n]);
    	}
    }
    solve();
    if(dp1[n]>ans1)
    {
    	ans1=dp1[n];
    	ans2=dp2[n];
    }
    else if(dp1[n]==ans1)
    {
    	add(ans2,dp2[n]);
    }
    printf("%d %d\n",ans1,ans2);
    return 0;
}