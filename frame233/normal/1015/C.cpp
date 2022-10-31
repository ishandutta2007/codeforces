#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<cstdio>
#include<queue> 
#include<cstring>
#include<algorithm>

typedef long long ll;

template <typename T>T gcd(const T &a,const T &b){return (!b)?a:gcd(b,a%b);}
template <typename T>inline T abs(const T &a){return a>0?a:-a;}
template <typename T>inline T max(const T &a,const T &b){return a<b?b:a;}
template <typename T>inline T min(const T &a,const T &b){return a<b?a:b;}
template <typename T>inline void chmax(T &a,const T &b){(a<b)&&(a=b);}
template <typename T>inline void chmin(T &a,const T &b){(a>b)&&(a=b);}

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
const int N=100005;
struct node{
	ll a,b;
	inline bool operator < (const node &x)const{return a-b>x.a-x.b;}
}a[N];
int main() 
{
	ll n,m,sum=0;
	read(n,m);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld %lld",&a[i].a,&a[i].b);
		sum+=a[i].a;
	}
	std::sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		if(sum>m)
		{
			sum-=(a[i].a-a[i].b);
			++ans;
		}
		else
		{
			break;
		}
	}
	if(sum>m)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n",ans);
	}
	return 0;
}