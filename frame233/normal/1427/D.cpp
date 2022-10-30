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

const int N=55;
int a[N],b[N];
int main()
{
	int n;read(n);
	for(int i=1;i<=n;++i) read(a[i]);
	std::vector<std::vector<int> > ans;
	for(int t=0;;++t)
	{
		bool flag=true;
		for(int i=1;i<=n;++i)flag&=a[i]==i;
		if(flag) break;
		std::vector<int> v;
		if(!(t&1))
		{
			for(int i=1;i<=n;++i)
			{
				int j=i;
				while(j<n&&a[j+1]<a[i]) ++j;
				v.pb(j-i+1),i=j;
			}
		}
		else
		{
			for(int i=1;i<=n;++i)
			{
				int j=i;
				while(j<n&&a[j+1]>a[i]) ++j;
				v.pb(j-i+1),i=j;
			}
		}
		if(SZ(v)==1) continue;
		ans.pb(v);
		int cur=n,pos=0;
		for(int i=SZ(v)-1;i>=0;--i)
		{
			for(int j=cur-v[i]+1;j<=cur;++j) b[++pos]=a[j];
			cur-=v[i];
		}
		memcpy(a,b,sizeof(a));
	}
	printf("%d\n",SZ(ans));
	for(const auto &it:ans)
	{
		printf("%d ",SZ(it));
		for(auto itt:it) printf("%d ",itt);
		printf("\n");
	}
	return 0;
}