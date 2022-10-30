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

const int N=505;
bool a[N][N],orig[N][N];
void MAIN()
{
	int n,m;read(n,m);
	for(int i=0;i<=n+1;++i)memset(a[i],0,m+3);
	char ch;
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)
	{
		do{ch=getchar();}while(ch!='.'&&ch!='X');
		a[i][j]=ch=='X';
	}
	if(n==1)memset(a[1]+1,1,m);
	else if(m==1)for(int i=1;i<=n;++i)a[i][1]=true;
	else
	{
		for(int i=1;i<=n;++i)memcpy(orig[i],a[i],m+3);
		memset(a[1]+1,1,m);
		for(int i=1;i<=m;++i)if(orig[2][i]&&i%3!=2)a[2][i-1]=a[2][i+1]=true,a[1][i]=false,a[1][i+(i%3==0?1:-1)]=false;
		for(int i=2;i<=n;++i)for(int j=2;j<=m;j+=3)a[i][j]=true;
		if(m%3==1)for(int i=2;i<=n;++i)if(orig[i][m])a[i][m-1]=true;
	}
	for(int i=1;i<=n;++i){for(int j=1;j<=m;++j)putchar(a[i][j]?'X':'.');putchar('\n');}
}
int main()
{
	int _;read(_);
	while(_--)MAIN();
	return 0;
}