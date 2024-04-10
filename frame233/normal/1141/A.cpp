#include<cstdio>
#include<algorithm>

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

int main()
{
	int n,m;
	read(n,m);
	if(m%n) return printf("-1\n"),0;
	m/=n;
	int ans=0;
	while(!(m%3)) ++ans,m/=3;
	while(!(m%2)) ++ans,m/=2;
	printf("%d\n",m==1?ans:-1);
	return 0;
}