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
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}

const int N=2005;
int d[N];
int a[N],b[N],c[N],cnt;
std::vector<int> e[N];
int main()
{
	int n;read(n);
	int m=0;
	for(int i=1;i<=n;++i) read(d[i]),m+=d[i];
	if(m%2||(m>>=1)<n-1) return puts("-1"),0;
	int _=m-n+1,o=0,l=0;
	for(int i=1;i<=n;++i) o+=d[i]&1,l+=d[i]==1;
	if(_>(n-1-max(o/2,l))/2) return puts("-1"),0;
	std::vector<int> v1,v2;
	for(int i=1;i<=n;++i)
	{
		if(d[i]&1) d[i]==1?v1.pb(i):v2.pb(i);
		else a[++cnt]=i,c[cnt]=d[i];
	}
	if(m==n-1)
	{
		printf("%d\n",m);
		for(int i=1;i<=m;++i)
		{
			int a=0;
			for(int j=1;j<=n;++j) if(d[j]==1) a=j;
			for(int j=1;j<=n;++j) if(d[j]>1){printf("2 %d %d\n",j,a);--d[j],--d[a];break;}
			if(d[a]) for(int j=1;j<=n;++j) if(d[j]&&j!=a){printf("2 %d %d\n",j,a);--d[j],--d[a];break;}
		}
		return 0;
	}
	std::vector<pi> ans;
	while(!v2.empty())
	{
		++cnt;
		a[cnt]=v2.back();v2.pop_back();
		if(!v1.empty()){b[cnt]=v1.back();v1.pop_back();}
		else{b[cnt]=v2.back();v2.pop_back();}
		ans.pb({a[cnt],b[cnt]});
		c[cnt]=d[a[cnt]]+d[b[cnt]]-2;
		--d[a[cnt]],--d[b[cnt]];
	}
	if(!v1.empty())
	{
		for(int i=1;i<=cnt;++i)
		{
			while(!v1.empty()&&d[b[i]]>=4)
			{
				ans.pb({v1.back(),b[i]});v1.pop_back();
				ans.pb({v1.back(),b[i]});v1.pop_back();
				d[b[i]]-=2,c[i]-=2;
			}
			while(!v1.empty()&&d[a[i]]>=4)
			{
				ans.pb({v1.back(),a[i]});v1.pop_back();
				ans.pb({v1.back(),a[i]});v1.pop_back();
				d[a[i]]-=2,c[i]-=2;
			}
		}
	}
	std::vector<pi> E;
	while(true)
	{
		int A=0,B=0,C=0;
		for(int i=1;i<=cnt;++i) if(c[i]==2) A?B=i:A=i;else if(c[i]) C=i;
		if(!C)
		{
			std::vector<int> v;
			for(int i=1;i<=cnt;++i) if(c[i]) v.pb(i);
			for(int i=1;i<SZ(v);++i) E.pb({v[i-1],v[i]});
			E.pb({v[0],v.back()});
			break;
		}
		else E.pb({A,B}),E.pb({A,C}),E.pb({B,C}),c[C]-=2,c[A]=c[B]=0;
	}
	for(auto it:E)
	{
		int A=it.first,B=it.second,nd1,nd2;
		if(d[a[A]]) nd1=a[A];
		else nd1=b[A];
		if(d[a[B]]) nd2=a[B];
		else nd2=b[B];
		--d[nd1],--d[nd2];
		ans.pb({nd1,nd2});
	}
	printf("%d\n",SZ(ans));
	for(auto it:ans) printf("2 %d %d\n",it.first,it.second);
	return 0;
}