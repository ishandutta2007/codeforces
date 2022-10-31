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

const int N=100005;
ll a[N],d[N],sum[N];
int main()
{
	int n,q;
	read(n);
	for(int i=1;i<=n;++i) read(a[i]);
	std::sort(a+1,a+n+1);
	for(int i=2;i<=n;++i) d[i-1]=a[i]-a[i-1];
	std::sort(d+1,d+n);
	for(int i=1;i<n;++i) sum[i]=sum[i-1]+d[i];
	read(q);
	while(q--)
	{
		ll l,r;
		read(l,r);
		ll len=r-l+1;
		int pos=std::upper_bound(d+1,d+n,len)-d;
		printf("%lld\n",(n-pos)*len+sum[pos-1]+len);
	}
	return 0;
}
//Dpair AK IOI