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

const int N=100005;
void MAIN()
{
	int n;read(n);
	for(int i=2;i<=n;++i)
	{
		printf("? %d %d\n",i-1,1);
		for(int j=1;j<i;++j)printf("%d%c",j," \n"[j+1==i]);
		printf("%d\n",i),fflush(stdout);
		int x;read(x);
		if(x)
		{
			std::vector<int> v;
			for(int j=i+1;j<=n;++j)
			{
				printf("? %d %d\n%d\n%d\n",1,1,i,j),fflush(stdout);
				read(x);
				if(!x)v.pb(j);
			}
			int l=1,r=i-1;
			while(l<r)
			{
				int mid=(l+r)>>1;
				printf("? %d %d\n",mid,1);
				for(int j=1;j<=mid;++j)printf("%d%c",j," \n"[j==mid]);
				printf("%d\n",i),fflush(stdout);
				read(x);
				if(x)r=mid;
				else l=mid+1;
			}
			for(int j=1;j<i;++j)if(j!=l)v.pb(j);
			printf("! %d ",SZ(v));
			for(auto it:v)printf("%d ",it);
			printf("\n"),fflush(stdout);
			return;
		}
	}
}
int main()
{
	int _;read(_);
	while(_--) MAIN();
	return 0;
}