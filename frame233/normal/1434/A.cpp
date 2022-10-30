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

const int N=600005;
int a[8],b[N];
int val[N][9];
struct node{
	int i,j,val;
	inline bool operator < (const node &o)const
	{
		return val<o.val;
	}
}c[N];
int cur[N];
int main()
{
	for(int i=1;i<=6;++i) read(a[i]);
	int n;read(n);
	int pos=0;
	int maxx=0;
	for(int i=1;i<=n;++i)
	{
		read(b[i]);
		for(int j=1;j<=6;++j) val[i][j]=b[i]-a[j];
		std::sort(val[i]+1,val[i]+7);
		for(int j=1;j<=6;++j)
		{
			c[++pos]={i,j,val[i][j]};
		}
		val[i][7]=2e9;
		chmax(maxx,cur[i]=val[i][1]);
	}
	std::sort(c+1,c+pos+1);
	int ans=1e9;
	for(int i=1;i<=pos;++i)
	{
		chmin(ans,maxx-c[i].val);
		chmax(maxx,val[c[i].i][c[i].j+1]);
		if(c[i].j==6) break;
	}
	printf("%d\n",ans);
	return 0;
}