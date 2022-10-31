#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<cstdio>
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
ll a[N];
int main()
{
	ll n,k;
	read(n,k);
	if(k*(k+1)/2>n)
	{
		printf("NO\n");
		return 0;
	}
	for(int i=1;i<=k;++i) a[i]=i;
	int sum=0,rest=n-k*(k+1)/2,tot=0;
	a[0]=1000000000;
	for(int i=1;i<=k;++i)
	{
		a[i]+=sum;
		int tim=min((a[i-1]<<1)-a[i],rest/(k-i+1));
		rest-=(k-i+1)*tim;
		sum+=tim,a[i]+=tim;
		tot+=a[i];
	}
	if(tot==n)
	{
		printf("YES\n");
		for(int i=1;i<=k;++i) printf("%lld ",a[i]);
		return 0;
	}
	printf("NO\n");
	return 0;
}
//Frame