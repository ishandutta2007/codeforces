// Author -- xyr2005

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;
using std::min;
using std::max;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>inline void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=1005;
int a[N],b[N];
const int D=50000;
std::bitset<100005> dp[N];
bool solve(int *a,int n,std::vector<int> &v1,std::vector<int> &v2)
{
	std::shuffle(a+1,a+n+1,rnd);
	for(int i=1;i<=n;++i) dp[i]=(dp[i-1]<<a[i])|(dp[i-1]>>a[i]);
	if(!dp[n].test(D)) return false;
	int cur=D;
	for(int i=n;i>=1;--i)
	{
		if(cur+a[i]<=D+D&&dp[i-1].test(cur+a[i])) cur+=a[i],v1.pb(a[i]);
		else cur-=a[i],v2.pb(a[i]);
	}
	return true;
}
void MAIN()
{
	int n,m;
	read(n);for(int i=1;i<=n;++i) read(a[i]);
	read(m);for(int i=1;i<=m;++i) read(b[i]);
	if(abs(n-m)>1) return (void)puts("No");
	std::vector<int> v1,v2,v3,v4;
	bool flag=solve(a,n,v1,v2)&solve(b,m,v3,v4);
	if(!flag) return (void)puts("No");
	puts("Yes");
	if(SZ(v1)>SZ(v2)) std::swap(v1,v2);
	if(SZ(v3)<SZ(v4)) std::swap(v3,v4);
	std::sort(v1.begin(),v1.end(),std::greater<int>());
	std::sort(v2.begin(),v2.end(),std::greater<int>());
	std::sort(v3.begin(),v3.end());
	std::sort(v4.begin(),v4.end());
	std::vector<int> A(v1);for(auto it:v2) A.pb(-it);
	std::vector<int> B(v3);for(auto it:v4) B.pb(-it);
	if(SZ(A)>=SZ(B))
	{
		int x=0,y=0;
		for(int i=0;i<SZ(A);++i)
		{
			printf("%d %d\n",x+=A[i],y);
			if(i<SZ(B)) printf("%d %d\n",x,y+=B[i]);
		}
	}
	else
	{
		int x=0,y=0;
		for(int i=0;i<SZ(B);++i)
		{
			printf("%d %d\n",x,y+=B[i]);
			if(i<SZ(A)) printf("%d %d\n",x+=A[i],y);
		}
	}
}
int main()
{
	dp[0].set(D);
	int _;read(_);
	while(_--) MAIN();
	return 0;
}