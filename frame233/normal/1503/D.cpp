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
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return !b?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}

const int N=200005;
int a[N],b[N],suf[N];
int main()
{
	int n;read(n);
	int x,y;
	for(int i=1;i<=n;++i)
	{
		read(x,y);
		if((x<=n)==(y<=n))return puts("-1"),0;
		a[min(x,y)]=max(x,y),b[min(x,y)]=x>y;
	}
	for(int i=n;i>=1;--i)suf[i]=max(a[i],suf[i+1]);
	int l1=0,l2=0,s1=0,s2=0,v1=inf,v2=inf,mn=inf,ans=0;
	for(int i=1;i<=n;++i)
	{
		chmin(mn,a[i]);
		if(a[i]<v1)++l1,v1=a[i],s1+=b[i];
		else if(a[i]<v2)++l2,v2=a[i],s2+=b[i];
		else return puts("-1"),0;
		if(mn>suf[i+1])ans+=min(s1+l2-s2,s2+l1-s1),l1=0,l2=0,s1=0,s2=0,v1=inf,v2=inf;
	}
	printf("%d\n",ans);
	return 0;
}