#include<cstdio>
#include<algorithm>
#define IT std::vector<int>::iterator

typedef long long ll;

int gcd(int a,int b){return (!b)?a:gcd(b,a%b);}
inline int abs(int a){return a>0?a:-a;}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
inline void swap(int &a,int &b){int tmp=a;a=b,b=tmp;}

ll gcd(ll a,ll b){return (!b)?a:gcd(b,a%b);}
inline ll abs(ll a){return a>0?a:-a;}
inline ll max(ll a,ll b){return a>b?a:b;}
inline ll min(ll a,ll b){return a<b?a:b;}
inline void swap(ll &a,ll &b){ll tmp=a;a=b,b=tmp;}

template <typename T>inline void read(T& x)
{
    register char ch=getchar();
    while(ch<48||ch>57) ch=getchar();
    x=ch&15,ch=getchar();
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
}
template <typename T,typename... Args> inline void read(T& t, Args&... args)
{
    read(t);read(args...);
}

const int N=300005;
ll a[N];
int main()
{
	int n;
	ll rt=0,ans=0;
	read(n);
	for(int i=1;i<=n;++i) read(a[i]);
	for(int i=1;i<=n;++i)
	{
		ll tmp=min(rt,a[i]>>1);
		ans+=tmp;
		rt-=tmp;
		a[i]-=(tmp<<1);
		ans+=a[i]/3;
		a[i]%=3;
		rt+=a[i];
	}
	printf("%lld\n",ans);
	return 0;
}
//Dpair AK IOI