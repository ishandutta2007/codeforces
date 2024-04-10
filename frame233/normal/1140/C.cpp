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
const int N=300005;
struct node{
	int t,b;
	inline bool operator < (const node &x)const{return b>x.b;}
}a[N];
std::priority_queue<int,std::vector<int>,std::greater<int> > q;
int main() 
{
	int n,k;
	read(n,k);
	for(int i=1;i<=n;++i)
	{
		read(a[i].t,a[i].b);
	}
	std::sort(a+1,a+n+1);
	ll ans=0,sum=0;
	for(int i=1;i<=n;++i)
	{
		q.push(a[i].t);
		sum+=a[i].t;
		while(q.size()>k)
		{
			sum-=q.top();
			q.pop();
		}
		chmax(ans,sum*a[i].b);
	}
	printf("%lld\n",ans);
	return 0;
}