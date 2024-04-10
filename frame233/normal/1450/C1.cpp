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

const int N=305;
char s[N][N];
std::vector<pi> v1[3],v2[3];
void MAIN()
{
	for(int i=0;i<3;++i) v1[i].clear(),v2[i].clear();
	int n;read(n);
	int c=0;
	for(int i=0;i<n;++i)
	{
		read_str(s[i]);
		for(int j=0;j<n;++j)
		{
			if(s[i][j]=='X') v1[(i+j)%3].pb({i,j}),++c;
			else if(s[i][j]=='O') v2[(i+j)%3].pb({i,j}),++c;
		}
	}
	c/=3;
	for(int i=0;i<3;++i)for(int j=0;j<3;++j)if(SZ(v1[i])+SZ(v2[j])<=c)
	{
		for(auto it:v1[i]) s[it.first][it.second]='O';
		for(auto it:v2[j]) s[it.first][it.second]='X';
		for(int i=0;i<n;++i) printf("%s\n",s[i]);
		return;
	}
}
int main()
{
	int _;read(_);
	while(_--) MAIN();
	return 0;
}