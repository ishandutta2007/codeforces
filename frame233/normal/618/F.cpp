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

const int N=1000005;
ll a[N],b[N];
pi c[N];
bool vis[N];
int main()
{
	int n;read(n);
	for(int i=1;i<=n;++i) read(a[i]),a[i]+=a[i-1];
	for(int i=1;i<=n;++i) read(b[i]),b[i]+=b[i-1];
	bool flag=false;
	if(a[n]>b[n]) std::swap(a,b),flag=true;
	int p=0;
	for(int i=0;i<=n;++i)
	{
		while(p<n&&b[p+1]<=a[i]) ++p;
		if(vis[a[i]-b[p]])
		{
			int A=c[a[i]-b[p]].first,B=c[a[i]-b[p]].second;
			if(!flag)
			{
				printf("%d\n",i-A);for(int j=A+1;j<=i;++j) printf("%d ",j);printf("\n");
				printf("%d\n",p-B);for(int j=B+1;j<=p;++j) printf("%d ",j);printf("\n");
			}
			else
			{
				printf("%d\n",p-B);for(int j=B+1;j<=p;++j) printf("%d ",j);printf("\n");
				printf("%d\n",i-A);for(int j=A+1;j<=i;++j) printf("%d ",j);printf("\n");
			}
			return 0;
		}
		vis[a[i]-b[p]]=true,c[a[i]-b[p]]={i,p};
	}
	return 0;
}